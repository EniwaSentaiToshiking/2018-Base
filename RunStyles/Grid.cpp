#include "Grid.h"

Grid::Grid(){

}

Grid::~Grid(){
	
}

/* 初期化関数 */
void Grid::init() {
    grid_distance = 0.0;
    grid_direction = 0.0;
}

/* 座標aから座標bまでの移動距離を取得する関数 */
float Grid::getDistance(int aX, int aY, int bX, int bY) {
	grid_distance = sqrt( pow((float)(bX-aX),2) + pow((float)(bY-aY),2) );
    return grid_distance;
}

/* 目標座標の方位を取得する関数 */
float Grid::getDirection(int aX, int aY, int bX, int bY) {
    float targetDir = 0.0;// 目標方位
    //　座標aから座標bへの方位（ラジアン）を取得
    targetDir = atan2((float)(bY-aY), (float)(bX-aX));
    //ラジアンから度に変換
    targetDir = targetDir * 180.0 / M_PI;

    grid_direction = targetDir;

    return grid_direction;
}