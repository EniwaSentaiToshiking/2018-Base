#include "ev3api.h"
#include "app.h"
#include "Clock.h"
#include "UI.h"

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
//#define DEVICE_NAME     "ET0"  /* Bluetooth名 hrp2/target/ev3.h BLUETOOTH_LOCAL_NAMEで設定 */
//#define PASS_KEY        "1234" /* パスキー    hrp2/target/ev3.h BLUETOOTH_PIN_CODEで設定 */
#define CMD_START         '1'    /* リモートスタートコマンド */

/* オブジェクトへのポインタ定義 */
Clock*          clock;
UI* ui;

/* メインタスク */
void main_task(intptr_t unused)
{

    /* 各オブジェクトを生成・初期化する */
    clock       = new Clock();
    ui = new UI();
    
    /* Open Bluetooth file */
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);

    /* Bluetooth通信タスクの起動 */
    act_tsk(BT_TASK);

    ev3_led_set_color(LED_ORANGE); /* 初期化完了通知 */

    /* スタート待機 */
    while(1)
    {

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

    ev3_led_set_color(LED_GREEN); /* スタート通知 */

    /**
    * Main loop
    */
    while(1)
    {

        if (ev3_button_is_pressed(BACK_BUTTON)) break;


        clock->sleep(4); /* 4msec周期起動 */
    }

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
