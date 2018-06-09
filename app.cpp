/**
 ******************************************************************************
 ** ファイル名 : app.cpp
 **
 ** 概要 : 2輪倒立振子ライントレースロボットのTOPPERS/HRP2用C++サンプルプログラム
 **
 ** 注記 : sample_cpp (ライントレース/尻尾モータ/超音波センサ/リモートスタート)
 ******************************************************************************
 **/

#include "ev3api.h"
#include "app.h"
#include "GyroSensor.h"
#include "Clock.h"
#include "ObjectDetecter.h"
#include "UI.h"
#include "ColorSensorDriver.h"
#include "WheelMotorDriver.h"
#include "ArmMotorDriver.h"
#include "TailMotorDriver.h"

using namespace ev3api;

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/* Bluetooth */
static int32_t   bt_cmd = 0;      /* Bluetoothコマンド 1:リモートスタート */
static FILE     *bt = NULL;      /* Bluetoothファイルハンドル */

/* 下記のマクロは個体/環境に合わせて変更する必要があります */
#define GYRO_OFFSET           0  /* ジャイロセンサオフセット値(角速度0[deg/sec]時) */
#define LIGHT_WHITE          40  /* 白色の光センサ値 */
#define LIGHT_BLACK           0  /* 黒色の光センサ値 */
//#define DEVICE_NAME     "ET0"  /* Bluetooth名 hrp2/target/ev3.h BLUETOOTH_LOCAL_NAMEで設定 */
//#define PASS_KEY        "1234" /* パスキー    hrp2/target/ev3.h BLUETOOTH_PIN_CODEで設定 */
#define CMD_START         '1'    /* リモートスタートコマンド */

/* オブジェクトへのポインタ定義 */
GyroSensor*     gyroSensor;
WheelMotorDriver*          leftMotor;
WheelMotorDriver*          rightMotor;
ArmMotorDriver* armMotor;
TailMotorDriver*          tailMotor;
Clock*          clock;
ObjectDetecter* objectDetecter;
UI* ui;
ColorSensorDriver* colorSensorDriver;

/* メインタスク */
void main_task(intptr_t unused)
{
    int8_t forward;      /* 前後進命令 */
    int8_t turn;         /* 旋回命令 */
    int8_t pwm_L, pwm_R; /* 左右モータPWM出力 */

    /* 各オブジェクトを生成・初期化する */
    gyroSensor  = new GyroSensor(PORT_1);
    leftMotor   = new WheelMotorDriver(PORT_C);
    rightMotor  = new WheelMotorDriver(PORT_B);
    armMotor    = new ArmMotorDriver();
    tailMotor   = new TailMotorDriver();
    clock       = new Clock();
    objectDetecter = new ObjectDetecter();
    ui = new UI();
    colorSensorDriver = new ColorSensorDriver();

    /* 尻尾モーターのリセット */
    tailMotor->reset();
    armMotor->reset();
    
    /* Open Bluetooth file */
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);

    /* Bluetooth通信タスクの起動 */
    act_tsk(BT_TASK);

    ev3_led_set_color(LED_ORANGE); /* 初期化完了通知 */

    /* スタート待機 */
    while(1)
    {
        tailMotor->rotateDefault();
        armMotor->rotateDefault(); /* 完全停止中の角度に制御*/

        if (bt_cmd == 1)
        {
            break; /* リモートスタート */
        }

        if (ui->isTouched())
        {
            break; /* タッチセンサが押された */
        }

        clock->sleep(10);
    }

    /* 走行モーターエンコーダーリセット */
    leftMotor->reset();
    rightMotor->reset();
    
    /* ジャイロセンサーリセット */
    gyroSensor->reset();

    ev3_led_set_color(LED_GREEN); /* スタート通知 */

    /**
    * Main loop for the self-balance control algorithm
    */
    while(1)
    {
        int32_t motor_ang_l, motor_ang_r;
        int32_t gyro, volt;

        if (ev3_button_is_pressed(BACK_BUTTON)) break;

        tailMotor->rotateDefault();
        armMotor->rotateDefault();

        if (objectDetecter->detect()) /* 障害物検知 */
        {
            forward = turn = 0; /* 障害物を検知したら停止 */
        }
        else
        {
            forward = 30; /* 前進命令 */
            if (colorSensorDriver->getBrightness() >= (LIGHT_WHITE + LIGHT_BLACK)/2)
            {
                pwm_L = forward; /* 左旋回命令 */
                pwm_R = 0;
            }
            else
            {
                pwm_R = forward; /* 右旋回命令 */
                pwm_L = 0;
            }
        }

        /* 倒立振子制御API に渡すパラメータを取得する */
        motor_ang_l = leftMotor->getCount();
        motor_ang_r = rightMotor->getCount();
        gyro = gyroSensor->getAnglerVelocity();
        volt = ev3_battery_voltage_mV();

        leftMotor->controlMotor(pwm_L);
        rightMotor->controlMotor(pwm_R);

        clock->sleep(4); /* 4msec周期起動 */
    }
    leftMotor->reset();
    rightMotor->reset();

    ter_tsk(BT_TASK);
    fclose(bt);

    ext_tsk();
}

//*****************************************************************************
// 関数名 : bt_task
// 引数 : unused
// 返り値 : なし
// 概要 : Bluetooth通信によるリモートスタート。 Tera Termなどのターミナルソフトから、
//       ASCIIコードで1を送信すると、リモートスタートする。
//*****************************************************************************
void bt_task(intptr_t unused)
{
    while(1)
    {
        uint8_t c = fgetc(bt); /* 受信 */
        switch(c)
        {
        case '1':
            bt_cmd = 1;
            break;
        default:
            break;
        }
        fputc(c, bt); /* エコーバック */
    }
}
