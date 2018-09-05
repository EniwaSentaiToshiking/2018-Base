#include "math.h"

#ifndef GRID_H
#define GRID_H

typedef enum {
    TURN, // 目標座標の方位へ向くまで旋回
    MOVE, // 目標座標に到達するまで前進
    END   // 構造体に格納されている座標を移動しきったら停止
} RUN_STATE;

class Grid {
private:

public:
	Grid();

	float grid_distance = 0.0; //現在座標から目標座標までの距離
	float grid_direction = 0.0;//現在座標から目標座標の方位
	RUN_STATE state = TURN;

	void init();

	/* 座標aから座標bまでの移動距離を取得する関数 */
	float getDistance(int aX, int aY, int bX, int bY);

	/* 目標座標の方位を取得する関数 */
	float getDirection(int aX, int aY, int bX, int bY);

	virtual ~Grid();
};

#endif