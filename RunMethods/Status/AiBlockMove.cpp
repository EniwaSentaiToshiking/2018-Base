#include "AiBlockMove.h"

AiBlockMove::AiBlockMove(){
  //patterns.push_back(new RunPattern(BRAKE, 0, DISTANCE, 30));
  patterns.push_back(new RunPattern(STRAIGHT,   25,    BLACKLINE,  blackline));
  patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,  5));
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  angle_spin, DIRECTION_LEFT));
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   10,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, RIGHT));
  patterns.push_back(new RunPattern(STRAIGHT,   speed_slow, BRIGHTNESS, brightness));
  patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,   7));
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  -angle_spin, DIRECTION_RIGHT));
  //patterns.push_back(new RunPattern(STRAIGHT,  -speed_slow, DISTANCE,  -3));
  //0レーン目到着
  //1レーン目進行
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   20,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold,LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, speed_slow, BRIGHTNESS, brightness));
  //1レーン目到着

  patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));
  patterns.push_back(new RunPattern(STRAIGHT,   speed_slow, DISTANCE,   5));
  patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));

  //3.解答方向へ回転(if文の中)
  if(ana_ansnum >=4){
  //数字4,5,6,7の解答
  //4:analog_red
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION,  -arm_spin, DIRECTION_RIGHT));
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, arm_spin, DIRECTION_RIGHT));
  }else{
  //0:analog_red
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, tail_spin, DIRECTION_RIGHT));
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION, -tail_spin, DIRECTION_RIGHT));
  }
  patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));

  if(deg_ansnum >=4){
  //4:dezital_blue
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION,  arm_spin, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, -arm_spin, DIRECTION_LEFT));
  }else{
  //0:dezital_blue
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION,-tail_spin, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION,  tail_spin, DIRECTION_LEFT));
  }

  //1レーン目解答終了
  //patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,   5));
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   20,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold,LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, speed_slow, BRIGHTNESS, brightness));
  patterns.push_back(new RunPattern(STRAIGHT,   speed_slow, DISTANCE,   5));
  patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));

  //2レーン目開始
  if(ana_ansnum ==2 || ana_ansnum ==3 || ana_ansnum == 6 || ana_ansnum ==7){
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION,  -arm_spin, DIRECTION_RIGHT));
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, arm_spin, DIRECTION_RIGHT));
  }else{
    //0:analog_red
      patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, tail_spin, DIRECTION_RIGHT));
      patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION, -tail_spin, DIRECTION_RIGHT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));
  //3.解答方向へ回転(if文の中)
  if(deg_ansnum ==2 || deg_ansnum ==3 || deg_ansnum == 6 || deg_ansnum ==7){
    //数字2,3,6,7の解答(2の方向へ曲がる)
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION,  arm_spin, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, -arm_spin, DIRECTION_LEFT));
  }else{
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION,-tail_spin, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION, tail_spin, DIRECTION_LEFT));
  }
  //2レーン目終了
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   20,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold,LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, speed_slow, BRIGHTNESS, brightness));
  patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));
  patterns.push_back(new RunPattern(STRAIGHT,   speed_slow, DISTANCE,   5));
  patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));

  //3レーン目開始
  if(ana_ansnum ==1 || ana_ansnum ==3 || ana_ansnum == 5 || ana_ansnum ==7){
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION,  -arm_spin, DIRECTION_RIGHT));
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, arm_spin, DIRECTION_RIGHT));
  }else{
    //0:analog_red
      patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, tail_spin, DIRECTION_RIGHT));
      patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION, -tail_spin, DIRECTION_RIGHT));
  }
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));
  //3レーン目開始
  if(deg_ansnum ==1 || deg_ansnum ==3 || deg_ansnum == 5 || deg_ansnum ==7){
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION,  arm_spin, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION, -arm_spin, DIRECTION_LEFT));
  }else{
    patterns.push_back(new RunPattern(TURNING, -speed_high, DIRECTION,-tail_spin, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(TURNING, speed_high, DIRECTION,  tail_spin, DIRECTION_LEFT));
  }
  //patterns.push_back(new RunPattern(STRAIGHT,   speed_slow, DISTANCE,   5));
  patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, delay_500));
  patterns.push_back(new RunPattern(LINE_TRACE, speed_slow, DISTANCE,   5,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold,LEFT));
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   10,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold,LEFT));


  /*
*/
  setNextState();
}

AiBlockMove::~AiBlockMove(){
}

void AiBlockMove::init(){
}

void AiBlockMove::setNextState(){
    nextState = PARKING;
}

void AiBlockMove::aians_Input(int Predict_Ana_Num , int Predict_Deg_Num){
  Answer &ans = Answer::singleton();
  deg_ansnum = ans.digital;
  ana_ansnum = ans.analog;
}
