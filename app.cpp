/**
 ******************************************************************************
 ** �t�@�C���� : app.cpp
 **
 ** �T�v : 2�֓|���U�q���C���g���[�X���{�b�g��TOPPERS/HRP2�pC++�T���v���v���O����
 **
 ** ���L : sample_cpp (���C���g���[�X/�K�����[�^/�����g�Z���T/�����[�g�X�^�[�g)
 ******************************************************************************
 **/

#include "ev3api.h"
#include "app.h"
#include "ColorSensor.h"
#include "GyroSensor.h"
#include "Motor.h"
#include "Clock.h"
#include "ObjectDetecter.h"
#include "UI.h"

using namespace ev3api;

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/* Bluetooth */
static int32_t   bt_cmd = 0;      /* Bluetooth�R�}���h 1:�����[�g�X�^�[�g */
static FILE     *bt = NULL;      /* Bluetooth�t�@�C���n���h�� */

/* ���L�̃}�N���͌�/���ɍ��킹�ĕύX����K�v������܂� */
#define GYRO_OFFSET           0  /* �W���C���Z���T�I�t�Z�b�g�l(�p���x0[deg/sec]��) */
#define LIGHT_WHITE          40  /* ���F�̌��Z���T�l */
#define LIGHT_BLACK           0  /* ���F�̌��Z���T�l */
#define TAIL_ANGLE_DEFAULT    0  /* �K���̏����p�x[�x] */
#define TAIL_ANGLE_EXTEND  4800  /* �K����L�΂������̊p�x[�x] (�K��)*/
#define COLOR_ANGLE_DRIVE    25  /* ���s���̃J���[�Z���T�̊p�x[�x] (�K��)*/
  /* �o�����X���s���̊p�x[�x] */
#define P_GAIN             2.5F  /* ���S��~�p���[�^������W�� */
#define PWM_ABS_MAX          60  /* ���S��~�p���[�^����PWM��΍ő�l */
//#define DEVICE_NAME     "ET0"  /* Bluetooth�� hrp2/target/ev3.h BLUETOOTH_LOCAL_NAME�Őݒ� */
//#define PASS_KEY        "1234" /* �p�X�L�[    hrp2/target/ev3.h BLUETOOTH_PIN_CODE�Őݒ� */
#define CMD_START         '1'    /* �����[�g�X�^�[�g�R�}���h */

/* LCD�t�H���g�T�C�Y */
#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (6/*TODO: magic number*/)
#define CALIB_FONT_HEIGHT (8/*TODO: magic number*/)

/* �֐��v���g�^�C�v�錾 */
static void tail_control(int32_t angle);
static void colorMotor_control(int32_t angle);

/* �I�u�W�F�N�g�ւ̃|�C���^��` */
ColorSensor*    colorSensor;
GyroSensor*     gyroSensor;
Motor*          leftMotor;
Motor*          rightMotor;
Motor*          tailMotor;
Motor*          colorMotor;
Clock*          clock;
ObjectDetecter* objectDetecter;
UI* ui;

/* ���C���^�X�N */
void main_task(intptr_t unused)
{
    int8_t forward;      /* �O��i���� */
    int8_t turn;         /* ���񖽗� */
    int8_t pwm_L, pwm_R; /* ���E���[�^PWM�o�� */

    /* �e�I�u�W�F�N�g�𐶐��E���������� */
    colorSensor = new ColorSensor(PORT_2);
    gyroSensor  = new GyroSensor(PORT_1);
    leftMotor   = new Motor(PORT_C);
    rightMotor  = new Motor(PORT_B);
    tailMotor   = new Motor(PORT_A);
    colorMotor  = new Motor(PORT_D);
    clock       = new Clock();
    objectDetecter = new ObjectDetecter();
    ui = new UI();

    /* LCD��ʕ\�� */
    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
    ev3_lcd_draw_string("EV3way-ET sample_cpp", 0, CALIB_FONT_HEIGHT*1);

    /* �K�����[�^�[�̃��Z�b�g */
    tailMotor->reset();
    colorMotor->reset();
    
    /* Open Bluetooth file */
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);

    /* Bluetooth�ʐM�^�X�N�̋N�� */
    act_tsk(BT_TASK);

    ev3_led_set_color(LED_ORANGE); /* �����������ʒm */

    /* �X�^�[�g�ҋ@ */
    while(1)
    {
        tail_control(TAIL_ANGLE_DEFAULT); /* ���S��~�p�p�x�ɐ��� */
        colorMotor_control(COLOR_ANGLE_DRIVE); /* ���S��~���̊p�x�ɐ���*/

        if (bt_cmd == 1)
        {
            break; /* �����[�g�X�^�[�g */
        }

        if (ui->isTouched())
        {
            break; /* �^�b�`�Z���T�������ꂽ */
        }

        clock->sleep(10);
    }

    /* ���s���[�^�[�G���R�[�_�[���Z�b�g */
    leftMotor->reset();
    rightMotor->reset();
    
    /* �W���C���Z���T�[���Z�b�g */
    gyroSensor->reset();

    ev3_led_set_color(LED_GREEN); /* �X�^�[�g�ʒm */

    /**
    * Main loop for the self-balance control algorithm
    */
    while(1)
    {
        int32_t motor_ang_l, motor_ang_r;
        int32_t gyro, volt;

        if (ev3_button_is_pressed(BACK_BUTTON)) break;

        tail_control(TAIL_ANGLE_DEFAULT); /* �o�����X���s�p�p�x�ɐ��� */
        colorMotor_control(COLOR_ANGLE_DRIVE); /* ���s�p�p�x�ɐ��� */

        if (objectDetecter->detect()) /* ��Q�����m */
        {
            forward = turn = 0; /* ��Q�������m�������~ */
        }
        else
        {
            forward = 30; /* �O�i���� */
            if (colorSensor->getBrightness() >= (LIGHT_WHITE + LIGHT_BLACK)/2)
            {
                pwm_L = forward; /* �����񖽗� */
                pwm_R = 0;
            }
            else
            {
                pwm_R = forward; /* �E���񖽗� */
                pwm_L = 0;
            }
        }

        /* �|���U�q����API �ɓn���p�����[�^���擾���� */
        motor_ang_l = leftMotor->getCount();
        motor_ang_r = rightMotor->getCount();
        gyro = gyroSensor->getAnglerVelocity();
        volt = ev3_battery_voltage_mV();

        leftMotor->setPWM(pwm_L);
        rightMotor->setPWM(pwm_R);

        clock->sleep(4); /* 4msec�����N�� */
    }
    leftMotor->reset();
    rightMotor->reset();

    ter_tsk(BT_TASK);
    fclose(bt);

    ext_tsk();
}

//*****************************************************************************
// �֐��� : tail_control
// ���� : angle (���[�^�ڕW�p�x[�x])
// �Ԃ�l : ����
// �T�v : ���s�̊��S��~�p���[�^�̊p�x����
//*****************************************************************************
static void tail_control(int32_t angle)
{
    float pwm = (float)(angle - tailMotor->getCount()) * P_GAIN; /* ��ᐧ�� */
    /* PWM�o�͖O�a���� */
    if (pwm > PWM_ABS_MAX)
    {
        pwm = PWM_ABS_MAX;
    }
    else if (pwm < -PWM_ABS_MAX)
    {
        pwm = -PWM_ABS_MAX;
    }

    tailMotor->setPWM(pwm);
}

//*****************************************************************************
// �֐��� : colorMotor_control
// ���� : angle (���[�^�ڕW�p�x[�x])
// �Ԃ�l : ����
// �T�v : ���s�̊��S��~�p���[�^�̊p�x����
//*****************************************************************************
static void colorMotor_control(int32_t angle)
{
    float pwm = (float)(angle - colorMotor->getCount()) * P_GAIN; /* ��ᐧ�� */
    /* PWM�o�͖O�a���� */
    if (pwm > PWM_ABS_MAX)
    {
        pwm = PWM_ABS_MAX;
    }
    else if (pwm < -PWM_ABS_MAX)
    {
        pwm = -PWM_ABS_MAX;
    }

    colorMotor->setPWM(pwm);
}

//*****************************************************************************
// �֐��� : bt_task
// ���� : unused
// �Ԃ�l : �Ȃ�
// �T�v : Bluetooth�ʐM�ɂ�郊���[�g�X�^�[�g�B Tera Term�Ȃǂ̃^�[�~�i���\�t�g����A
//       ASCII�R�[�h��1�𑗐M����ƁA�����[�g�X�^�[�g����B
//*****************************************************************************
void bt_task(intptr_t unused)
{
    while(1)
    {
        uint8_t c = fgetc(bt); /* ��M */
        switch(c)
        {
        case '1':
            bt_cmd = 1;
            break;
        default:
            break;
        }
        fputc(c, bt); /* �G�R�[�o�b�N */
    }
}
