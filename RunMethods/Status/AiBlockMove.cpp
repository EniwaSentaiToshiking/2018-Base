#include "AiBlockMove.h"

AiBlockMove::AiBlockMove(){

  //1.AIコース走る
  patterns.push_back(new RunPattern(STRAIGHT,   speed, BLACKLINE,  blackline));//20
  patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,   10));//10
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  angle_spin));//20
  patterns.push_back(new RunPattern(STRAIGHT,   speed, BLACKLINE,  blackline));//20
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  -angle_spin));//20
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   20,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, RIGHT));//15
  patterns.push_back(new RunPattern(LINE_TRACE, speed, BRIGHTNESS, brightness, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, RIGHT));//15
  patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,   5));//10
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  -angle_spin));//20
  //1レーン目到着右向いた状態
  //1レーン目
  //-----------------------------------------アナログ赤解答開始------------------------------------------------
  //1.赤まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, speed, COLOR ,     COLOR_RED,  strong_pid[0], strong_pid[1], strong_pid[2], linenear_threshold, LEFT));//20
    //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,5));//10
  //3.解答方向へ回転(if文の中)
  if(ana_ansnum >=4){
    //数字4,5,6,7の解答
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, -block_spin));//20
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));//10
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));//-10
    patterns.push_back(new RunPattern(SPIN,     -speed,      COLOR,     COLOR_BLACK, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, LEFT));//-20
  }else{
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, block_spin));//20
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));//10
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));//-10
    patterns.push_back(new RunPattern(SPIN,     speed,       BLACKLINE, blackline,nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, LEFT));
  }//leftラインへ復帰2-
  patterns.push_back(new RunPattern(LINE_TRACE, speed,       DISTANCE,  5,          strong_pid[0],strong_pid[1], strong_pid[2],linenomal_threshold, LEFT));//20PIDの数値を上げて，ライン復帰を強制的にしています．
  patterns.push_back(new RunPattern(LINE_TRACE, speed,       BRIGHTNESS,brightness, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, LEFT));//20
  patterns.push_back(new RunPattern(STRAIGHT,   speed,       DISTANCE,  5));//20
  //LINEはレフトを見たまま,交差点に入るまで
  //-----------------------------------------アナログ赤解答終了------------------------------------------------
  //-----------------------------------------デジタル青解答開始------------------------------------------------
  //1.青まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, speed,       COLOR ,    COLOR_BLUE, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, LEFT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT,   speed,       DISTANCE,  3));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(deg_ansnum >=4){
    //数字4,5,6,7の解答
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     speed,       BLACKLINE, blackline, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, LEFT));
    //いったん黒ラインへ戻す
  }else{
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, -block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     -speed,      COLOR,     COLOR_BLACK, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   5,          strong_pid[0],strong_pid[1],strong_pid[2], linenear_threshold, LEFT));//PIDの数値を上げて，ライン復帰を強制的にしています．
  patterns.push_back(new RunPattern(LINE_TRACE, speed, BRIGHTNESS, brightness, strong_pid[0],strong_pid[1],strong_pid[2], linenear_threshold, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT,   15, DISTANCE, 10));
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  angle_spin));//90度回転　LINEはレフトを見たまま,交差点に入るまで
  //-----------------------------------------デジタル青解答終了------------------------------------------------

  //2レーン目入る
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   15,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linefar_threshold, RIGHT));
  patterns.push_back(new RunPattern(LINE_TRACE, speed, BRIGHTNESS, brightness, nomal_pid[0], nomal_pid[1], nomal_pid[2], linefar_threshold, RIGHT));
  patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,   5));
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  -angle_spin));
  //2レーン目到着
  //patterns.push_back(new RunPattern(BRAKE, 0, DISTANCE, 30));

  //-----------------------------------------アナログ緑解答開始------------------------------------------------
  //1.緑まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE, 3, strong_pid[0], strong_pid[1], strong_pid[2], linenomal_threshold, LEFT));//応急処置
  patterns.push_back(new RunPattern(LINE_TRACE, speed, COLOR,    COLOR_GREEN, nomal_pid[0], nomal_pid[1], nomal_pid[2],  linenear_threshold, LEFT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT, speed, DISTANCE,   5));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転

  if(ana_ansnum ==2 || ana_ansnum ==3 || ana_ansnum == 6 || ana_ansnum ==7){
    //数字2,3,6,7の解答(2の方向へ曲がる)
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, -block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     -speed,      COLOR,     COLOR_BLACK, nomal_pid[0], nomal_pid[1], nomal_pid[2],    linenear_threshold, LEFT));
  }else{
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     speed,       BLACKLINE,  blackline,  nomal_pid[0], nomal_pid[1], nomal_pid[2],    linenear_threshold, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, speed,       DISTANCE,  5,           strong_pid[0], strong_pid[1], strong_pid[2], linenomal_threshold, LEFT));//PIDの数値を上げて，ライン復帰を強制的にしています．
  patterns.push_back(new RunPattern(LINE_TRACE, speed,       BRIGHTNESS,brightness,  nomal_pid[0],  nomal_pid[1],  nomal_pid[2],  linenomal_threshold, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT,   speed,       DISTANCE,  5));
  //LINEはレフトを見たまま,交差点に入るまで
  //-----------------------------------------アナログ緑解答終了------------------------------------------------

  //-----------------------------------------デジタル黄解答開始------------------------------------------------
  //1.黄まで走る
  //patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE ,5, 1.0, 0.0, 0.05, linefar_threshold,LEFT));//応急処置
  patterns.push_back(new RunPattern(LINE_TRACE, speed, COLOR,    COLOR_YELLOW, strong_pid[0], strong_pid[1], strong_pid[2], linenear_threshold, LEFT));
  //2.ちょっとでる

  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(deg_ansnum ==2 || deg_ansnum ==3 || deg_ansnum == 6 || deg_ansnum ==7){
    //数字4,5,6,7の解答
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     speed,       BLACKLINE, blackline,nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, LEFT));
  }else{
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, -block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     -speed,      COLOR,     COLOR_BLACK, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   5,          strong_pid[0],strong_pid[1],strong_pid[2], linenear_threshold, LEFT));//PIDの数値を上げて，ライン復帰を強制的にしています．
  patterns.push_back(new RunPattern(LINE_TRACE, speed, BRIGHTNESS, brightness, strong_pid[0],strong_pid[1],strong_pid[2], linenear_threshold, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT,   15, DISTANCE, 10));
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  angle_spin));//90度回転　LINEはレフトを見たまま,交差点に入るまで
  //-----------------------------------------デジタル黄解答終了------------------------------------------------
  //3レーン目入る
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   15,         nomal_pid[0], nomal_pid[1], nomal_pid[2], linefar_threshold, RIGHT));
  patterns.push_back(new RunPattern(LINE_TRACE, speed, BRIGHTNESS, brightness, nomal_pid[0], nomal_pid[1], nomal_pid[2], linefar_threshold, RIGHT));
  patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,   5));
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  -angle_spin));
  //3レーン目到着

  //-----------------------------------------デジタル青解答終了------------------------------------------------
  //-----------------------------------------アナログ赤解答開始------------------------------------------------
  //1.赤まで走る
  //patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE ,10, nomal_pid[0], nomal_pid[1], nomal_pid[2], linefar_threshold,RIGHT));//応急処置
  patterns.push_back(new RunPattern(LINE_TRACE, speed, COLOR ,COLOR_RED , strong_pid[0], strong_pid[1], strong_pid[2], linenear_threshold, LEFT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT,   speed, DISTANCE,5));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(ana_ansnum ==1 || ana_ansnum ==3 || ana_ansnum == 5 || ana_ansnum ==7){
    //数字1,3,5,7の解答(2の方向へ曲がる)
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, -block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     -speed,      COLOR,     COLOR_BLACK ,nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, LEFT));
    //patterns.push_back(new RunPattern(STRAIGHT, -10, COLOR, 5,nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, RIGHT));//こっちは赤色見つかるまでバック
  }else{
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     speed,       BLACKLINE, blackline,  nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, speed,       DISTANCE,  5,strong_pid[0], strong_pid[1], strong_pid[2], linenomal_threshold, LEFT));//PIDの数値を上げて，ライン復帰を強制的にしています．
  patterns.push_back(new RunPattern(LINE_TRACE, speed,       BRIGHTNESS,brightness, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT,   speed,       DISTANCE,  5));
  //LINEはレフトを見たまま,交差点に入るまで
  //-----------------------------------------アナログ赤解答終了------------------------------------------------
  //-----------------------------------------デジタル赤解答開始------------------------------------------------
  //1.赤まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, speed,       COLOR,     COLOR_RED ,strong_pid[0], strong_pid[1], strong_pid[2], linenear_threshold, LEFT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT,   speed,       DISTANCE,  5));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(deg_ansnum ==1 || deg_ansnum ==3 || deg_ansnum == 5 || deg_ansnum ==7){
    //数字4,5,6,7の解答
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     speed,       BLACKLINE, blackline, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, LEFT));
    //patterns.push_back(new RunPattern(STRAIGHT, -speed, COLOR, 5,nomal_pid[0], nomal_pid[1], nomal_pid[2], linenomal_threshold, RIGHT));//こっちは赤色見つかるまでバック
  }else{
    patterns.push_back(new RunPattern(SPIN,     speed,       DIRECTION, -block_spin));
    patterns.push_back(new RunPattern(STRAIGHT, speed_slow,  DISTANCE,  5));
    patterns.push_back(new RunPattern(STRAIGHT, -speed_slow, DISTANCE,  5));
    patterns.push_back(new RunPattern(SPIN,     -speed,      COLOR,     COLOR_BLACK, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   5,          strong_pid[0],strong_pid[1],strong_pid[2], linenear_threshold, LEFT));//PIDの数値を上げて，ライン復帰を強制的にしています．
  patterns.push_back(new RunPattern(LINE_TRACE, speed, BRIGHTNESS, brightness, strong_pid[0],strong_pid[1],strong_pid[2], linenear_threshold, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT,   15, DISTANCE, 5));
  patterns.push_back(new RunPattern(SPIN,       speed, DIRECTION,  angle_spin));//90度回転　LINEはレフトを見たまま,交差点に入るまで
    //-----------------------------------------デジタル赤解答終了------------------------------------------------
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   5,  strong_pid[0], strong_pid[1], strong_pid[2], linenomal_threshold, RIGHT));
  patterns.push_back(new RunPattern(LINE_TRACE, speed, DISTANCE,   15, nomal_pid[0], nomal_pid[1], nomal_pid[2], linenear_threshold, RIGHT));
  //AIアンサー解答終了
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
  ana_ansnum = Predict_Ana_Num;
  deg_ansnum = Predict_Deg_Num;
}
