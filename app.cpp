#include "ev3api.h"
#include "app.h"
#include "Clock.h"
#include "UI.h"
#include "RunManager.h"
#include "Block.h"

using namespace ev3api;

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/* Bluetooth */
static int32_t bt_cmd = 0; /* Bluetooth�R�}���h 1:�����[�g�X�^�[�g */
static FILE *bt = NULL;    /* Bluetooth�t�@�C���n���h�� */

/* ���L�̃}�N���͌�/���ɍ��킹�ĕύX����K�v������܂� */
//#define DEVICE_NAME     "ET0"  /* Bluetooth�� hrp2/target/ev3.h BLUETOOTH_LOCAL_NAME�Őݒ� */
//#define PASS_KEY        "1234" /* �p�X�L�[    hrp2/target/ev3.h BLUETOOTH_PIN_CODE�Őݒ� */
#define CMD_START '1' /* �����[�g�X�^�[�g�R�}���h */

/* �I�u�W�F�N�g�ւ̃|�C���^��` */
Clock *clock;
UI *ui;
RunManager *runManager;
ArmMotorDriver *armMotor;

int color[4];
int black[2];


/* ���C���^�X�N */
void main_task(intptr_t unused)
{

    /* �e�I�u�W�F�N�g�𐶐��E���������� */
    clock = new Clock();
    ui = new UI();
    runManager = new RunManager();
    armMotor = new ArmMotorDriver();

    /* Open Bluetooth file */
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);

    /* Bluetooth�ʐM�^�X�N�̋N�� */
    act_tsk(BT_TASK);

    armMotor->calibration();

    ev3_led_set_color(LED_ORANGE); /* �����������ʒm */

    /* �X�^�[�g�ҋ@ */
    while (1)
    {
        armMotor->rotateDefault();
        runManager->init();

        if (ui->isTouched())
        {
            fprintf(bt, "%d\n", 5);
            break; /* �^�b�`�Z���T�������ꂽ */
        }

        clock->sleep(10);
    }

    ev3_led_set_color(LED_GREEN); /* �X�^�[�g�ʒm */

    /**
    * Main loop
    */
    while (1)
    {

        if (ev3_button_is_pressed(BACK_BUTTON))
            break;

        if(bt_cmd == 1){
            Block &block = Block::singleton();
            block.red = color[0];
            block.yellow = color[1];
            block.green = color[2];
            block.blue = color[3];
            block.black1 = black[0];
            block.black2 = black[1];
            bt_cmd = -1;
        }

        runManager->run();

        clock->sleep(4); /* 4msec�����N�� */
    }

    ter_tsk(BT_TASK);
    fclose(bt);

    ext_tsk();
}

void get_color(int color_pos[4], char all_pos[256]){
    for (int i = 0; i < 4; i++ ){
        if (all_pos[2 * i] == '0'){
            color_pos[i] = all_pos[(2 * i) + 1] - 48;
        }else{
            color_pos[i] = 10 + all_pos[(2 * i) + 1] - 48;
        }
    }
}

void get_black(int black_pos[2], char all_pos[256]){
    for (int i = 0; i < 2; i++ ){
        black_pos[i] = all_pos[i + 8] - 48;
    }
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
    char tmp[256];
    int count = 0;
    while(1)
    {
        uint8_t c = fgetc(bt); /* 受信 */
        if (c - 48 >= 0 && c - 48 <= 9 && count <= 9){
            if(count == 0){
                snprintf(tmp, 255, "%d", c - 48);
            }else{
                snprintf(tmp, 255, "%s%d", tmp, c - 48);
            }
            count ++;
        } else  if (count == 10){
            get_color(color, tmp);
            get_black(black, tmp);
            //bt_cmd = 1;
            break;
        }
        fputc(c, bt); /* エコーバック */
    }
}
