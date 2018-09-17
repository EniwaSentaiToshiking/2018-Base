#include "Localization.h"

Localization::Localization()
{
    leftMotor = new WheelMotorDriver(PORT_C);
    rightMotor = new WheelMotorDriver(PORT_B);

    distance_reset();
}
Localization::~Localization()
{
}

void Localization::update()
{
    r0 = rightMotor->getCount();
    l0 = leftMotor->getCount();

    anR = r0 - r1;
    anL = l0 - l1; //タイヤの回転角度

    TR = 2 * M_PI * R * (anR / 360);
    TL = 2 * M_PI * R * (anL / 360); //タイヤの進んだ距離

    D = (TR + TL) / 2; //車体の進んだ距離

    w = (TR - TL) / (2 * d); //旋回角度計算

    x1 = x0 + (D * cos(z0 + (w / 2)));
    y1 = y0 + (D * sin(z0 + (w / 2))); //現在の座標を求める
    z1 = z0 + w;                       //現在の角度を求める

    point_x = x1;
    point_y = y1; //現在の座標を実際に取得する値
    current_distance += D;
    current_direction += w*(180/M_PI);

    x0 = x1;
    y0 = y1;
    z0 = z1; //座標の更新
    r1 = r0;
    l1 = l0; //エンコーダ値の更新
}

void Localization::distance_reset()
{
    x0 = 0.0;
    y0 = 0.0;
    z0 = 0.0;
    r1 = r0;
    l1 = l0;
    current_direction = 0.0;
    current_distance = 0.0;
}

float Localization::getCurrentDirection()
{
    return current_direction;
}

float Localization::getCurrentDistance()
{
    return current_distance;
}