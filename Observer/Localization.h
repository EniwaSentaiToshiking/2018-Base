#ifndef Localization_H
#define Localization_H

#include "WheelMotorDriver.h"
#define _USE_MATH_DEFINES
#include <math.h>
using namespace ev3api;

class Localization
{
private:
  int32_t r0 = 0; //今回右エンコーダ値
  int32_t l0 = 0; //今回左エンコーダ値

  int32_t r1 = 0; //前回右エンコーダ値
  int32_t l1 = 0; //前回左エンコーダ値

  float anR = 0.0; //左回転角度
  float anL = 0.0; //右回転角度

  float R = 5.08; //車輪の半径

  float TR = 0.0; //左タイヤの進んだ距離
  float TL = 0.0; //右タイヤの進んだ距離

  float D = 0.0; //車体の進んだ距離
  float w = 0.0; //旋回角度
  float d = 7.75; //軸からタイヤまでの距離（車軸長）

  float x0 = 0.0; //更新前x座標
  float y0 = 0.0; //更新前y座標
  float z0 = 0.0; //更新前角度

  float x1 = 0.0; //更新後x座標
  float y1 = 0.0; //更新後y座標
  float z1 = 0.0; //更新前角度

  float current_distance = 0.0;
  float current_direction = 0.0;

  WheelMotorDriver *leftMotor;
  WheelMotorDriver *rightMotor;

public:
  Localization();
  void update();
  void distance_reset();
  float getCurrentDirection();
  float getCurrentDistance();

  float point_x = 0.0; //自己位置のx座標データ
  float point_y = 0.0; //自己位置のy座標データ
  virtual ~Localization();
};

#endif
