#include "ev3api.h"
#include "app.h"
#include "Clock.h"
#include "UI.h"
#include "RunManager.h"

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
//#define DEVICE_NAME     "ET0"  /* Bluetooth�� hrp2/target/ev3.h BLUETOOTH_LOCAL_NAME�Őݒ� */
//#define PASS_KEY        "1234" /* �p�X�L�[    hrp2/target/ev3.h BLUETOOTH_PIN_CODE�Őݒ� */
#define CMD_START         '1'    /* �����[�g�X�^�[�g�R�}���h */

/* �I�u�W�F�N�g�ւ̃|�C���^��` */
Clock*          clock;
UI* ui;
RunManager* runManager;

/* ���C���^�X�N */
void main_task(intptr_t unused)
{

    /* �e�I�u�W�F�N�g�𐶐��E���������� */
    clock       = new Clock();
    ui = new UI();
    runManager = new RunManager();
    
    /* Open Bluetooth file */
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);

    /* Bluetooth�ʐM�^�X�N�̋N�� */
    act_tsk(BT_TASK);

    ev3_led_set_color(LED_ORANGE); /* �����������ʒm */

    /* �X�^�[�g�ҋ@ */
    while(1)
    {

        runManager->init();

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

    ev3_led_set_color(LED_GREEN); /* �X�^�[�g�ʒm */

    /**
    * Main loop
    */
    while(1)
    {

        if (ev3_button_is_pressed(BACK_BUTTON)) break;

        runManager->run();

        clock->sleep(4); /* 4msec�����N�� */
    }

    ter_tsk(BT_TASK);
    fclose(bt);

    ext_tsk();
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
