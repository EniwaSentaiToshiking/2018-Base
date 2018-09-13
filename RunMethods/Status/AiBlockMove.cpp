#include "AiBlockMove.h"

AiBlockMove::AiBlockMove(){
  //AIコース走る
  patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE,1));
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,10));
  patterns.push_back(new RunPattern(SPIN, 20,DIRECTION, 90));
  patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE,20));
  //patterns.push_back(new RunPattern(STRAIGHT, 20, COLOR,1));
  patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,-90));
  patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 5,2.0, 0.0, 0.05, 70, RIGHT));
  patterns.push_back(new RunPattern(LINE_TRACE, 15, BRIGHTNESS,40, 2.0, 0.0, 0.05, 70, RIGHT));
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
  patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -90));
  //1レーン目到着右向いた状態
  //1レーン目
  //アナログ赤色の解答
  //1.赤まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR ,5, 2.0, 0.0, 0.05, 30, RIGHT));//
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(ana_ansnum >=4){
    //数字4,5,6,7の解答
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,-30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, -20, COLOR,1,2.0, 0.0, 0.05, 70, LEFT));
    //patterns.push_back(new RunPattern(STRAIGHT, -10, COLOR, 5,2.0, 0.0, 0.05, 70, RIGHT));//こっちは赤色見つかるまでバック
  }else{
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, 20, BLACKLINE,20,2.0, 0.0, 0.05, 70, LEFT));
    //patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,10));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 5,1.0, 0.0, 0.05, 100, LEFT));//修正
  patterns.push_back(new RunPattern(LINE_TRACE, 20, BRIGHTNESS,40, 2.0, 0.0, 0.05, 70, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE,5,2.0, 0.0, 0.05, 100, LEFT));
  //LINEはレフトを見たまま,交差点に入るまで
  //アナログ赤解答終了

  //デジタル青色の解答
  //1.青まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR ,2, 1.0, 0.0, 0.05, 30, LEFT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(deg_ansnum >=4){
    //数字4,5,6,7の解答
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE, 5));
    patterns.push_back(new RunPattern(SPIN, 20, BLACKLINE,20,2.0, 0.0, 0.05, 70, LEFT));
    //patterns.push_back(new RunPattern(STRAIGHT, -10, COLOR, 5,2.0, 0.0, 0.05, 70, RIGHT));//こっちは赤色見つかるまでバック
  }else{
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,-30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, -20, COLOR,1,2.0, 0.0, 0.05, 70, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 5,2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(LINE_TRACE, 20, BRIGHTNESS,40, 2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE,10,2.0, 0.0, 0.05, 70, LEFT));
  patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,90));//90度回転　LINEはレフトを見たまま,交差点に入るまで
  //デジタル青解答終了

  //2レーン目入る
  patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 5,2.0, 0.0, 0.05, 100, RIGHT));
  patterns.push_back(new RunPattern(LINE_TRACE, 15, BRIGHTNESS,40, 2.0, 0.0, 0.05, 100, RIGHT));
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
  patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -90));
  //2レーン目到着

  //アナログ緑色の解答
  //1.緑まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE ,5, 2.0, 0.0, 0.05, 100, RIGHT));//応急処置
  patterns.push_back(new RunPattern(LINE_TRACE, 15, COLOR ,COLOR_GREEN, 2.0, 0.0, 0.05, 100, RIGHT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転

  if(ana_ansnum ==2 || ana_ansnum ==3 || ana_ansnum == 6 || ana_ansnum ==7){
    //数字2,3,6,7の解答(2の方向へ曲がる)
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,-30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, -20, COLOR, 1,2.0, 0.0, 0.05, 30, LEFT));
    //patterns.push_back(new RunPattern(STRAIGHT, -10, COLOR, 5,2.0, 0.0, 0.05, 70, RIGHT));//こっちは赤色見つかるまでバック
  }else{
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, 20, BLACKLINE,20,2.0, 0.0, 0.05, 30, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 5,2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(LINE_TRACE, 20, BRIGHTNESS,40, 2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE,5,2.0, 0.0, 0.05, 100, LEFT));
  //LINEはレフトを見たまま,交差点に入るまで
  //アナログ緑解答終了

  //デジタル黄色の解答

  //1.黄まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, 10, COLOR ,4, 2.0, 0.0, 0.05, 100, LEFT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5,2.0, 0.0, 0.05, 100, LEFT));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(deg_ansnum ==2 || deg_ansnum ==3 || deg_ansnum == 6 || deg_ansnum ==7){
    //数字4,5,6,7の解答
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE, 5));
    patterns.push_back(new RunPattern(SPIN, 20, BLACKLINE,20,2.0, 0.0, 0.05, 30, LEFT));
    //patterns.push_back(new RunPattern(STRAIGHT, -10, COLOR, 5,2.0, 0.0, 0.05, 70, RIGHT));//こっちは赤色見つかるまでバック
  }else{
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,-30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, -20, COLOR,1,2.0, 0.0, 0.05, 30, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 5,2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(LINE_TRACE, 20, BRIGHTNESS,40, 2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE,10));
  patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,90));//90度回転　LINEはレフトを見たまま,交差点に入るまで
  //デジタル黄解答終了

  //3レーン目
  patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 5,2.0, 0.0, 0.05, 100, RIGHT));
  patterns.push_back(new RunPattern(LINE_TRACE, 15, BRIGHTNESS,40, 2.0, 0.0, 0.05, 100, RIGHT));
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
  patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -90));
  //3レーン目終了

  //アナログ赤色の解答
  //1.赤まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR ,5, 2.0, 0.0, 0.05, 100, RIGHT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(ana_ansnum ==1 || ana_ansnum ==3 || ana_ansnum == 5 || ana_ansnum ==7){
    //数字1,3,5,7の解答(2の方向へ曲がる)
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,-30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, -20, COLOR, 1,2.0, 0.0, 0.05, 30, LEFT));
    //patterns.push_back(new RunPattern(STRAIGHT, -10, COLOR, 5,2.0, 0.0, 0.05, 70, RIGHT));//こっちは赤色見つかるまでバック
  }else{
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, 20, BLACKLINE,20,2.0, 0.0, 0.05, 30, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 5,2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(LINE_TRACE, 10, BRIGHTNESS,40, 2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, 15, DISTANCE,5,2.0, 0.0, 0.05, 100, LEFT));
  //LINEはレフトを見たまま,交差点に入るまで
  //アナログ赤解答終了

  //デジタル赤色の解答
  //1.赤まで走る
  patterns.push_back(new RunPattern(LINE_TRACE, 10, COLOR ,5, 2.0, 0.0, 0.05, 100, LEFT));
  //2.ちょっとでる
  patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
  //3.解答方向へ回転(if文の中)
  //ちょっと押す
  //バックする
  //黒線見つかるまで回転
  if(deg_ansnum ==1 || deg_ansnum ==3 || deg_ansnum == 5 || deg_ansnum ==7){
    //数字4,5,6,7の解答
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE, 5));
    patterns.push_back(new RunPattern(SPIN, 15, BLACKLINE,20,2.0, 0.0, 0.05, 30, LEFT));
    //patterns.push_back(new RunPattern(STRAIGHT, -10, COLOR, 5,2.0, 0.0, 0.05, 70, RIGHT));//こっちは赤色見つかるまでバック
  }else{
    patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,-30));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE,5));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE,5));
    patterns.push_back(new RunPattern(SPIN, -20, COLOR,1,2.0, 0.0, 0.05, 30, LEFT));
  }//leftラインへ復帰
  patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 5,2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(LINE_TRACE, 10, BRIGHTNESS,40, 2.0, 0.0, 0.05, 100, LEFT));
  patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE,5));
  patterns.push_back(new RunPattern(SPIN, 20, DIRECTION,90));//90度回転　LINEはレフトを見たまま,交差点に入るまで
  //デジタル赤解答終了
  patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 5, 2.0, 0.0, 0.01, 100, RIGHT));
  //patterns.push_back(new RunPattern(LINE_TRACE, 15, GRAYLINE, 55, 1.0, 0.0, 0.01, 40, RIGHT));
  //灰色到着
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
