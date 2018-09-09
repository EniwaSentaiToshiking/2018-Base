#include "SpeedCal.h"

SpeedCal::SpeedCal(){
	localization = new Localization();
}

SpeedCal::~SpeedCal(){
    delete localization;
}

void SpeedCal::init(){
	//各変数値を初期化
    localization -> distance_reset();
    speed = 0.0;
    pre_dis = 0.0;
    cur_dis = 0.0;

}

void SpeedCal::update(){
	/* SAMPLING_INTERVAL[ms]が経過した毎にサンプリングを行う */
    if(++intervalTimer >= (int)(SAMPLING_INTERVAL / TASK_INTERVAL)) {
        intervalTimer = 0;   // 時間計測用変数初期化
        pre_dis = cur_dis;   // サンプリング過去値更新
        cur_dis = localization -> getCurrentDistance(); //サンプリング現在値更新
        // 現在の速度を計算する1000倍してmm/msから，mm/sに変換している
        speed = ((cur_dis - pre_dis) / SAMPLING_INTERVAL) * 1000.0;
    }
}

float SpeedCal::getSpeed(){
	return speed;
}