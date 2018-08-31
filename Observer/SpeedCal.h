# include "Localization.h"

//タスク周期
#define TASK_INTERVAL 4.0
#define SAMPLING_INTERVAL 80.0 //速度値更新間隔[ms]

class SpeedCal {
	private:
		Localization * localization;
	public:
		SpeedCal();
		/*///////////////////
		速度計の初期化関数
		*////////////////////
		void init();

		/*/////////////////////////
		現在の速度を更新する関数
		タスク周期ごとに呼び出す
		*//////////////////////////
		void update();

		/*/////////////////////////
		現在の速度を取得する関数
		*//////////////////////////
		float getSpeed();

		float speed = 0.0;   //車体の現在の速度 mm/s
		float pre_dis = 0.0; //サンプリングの過去値
		float cur_dis = 0.0; //サンプリングの現在値
		//サンプリング待機時間計測用変数
		int intervalTimer = (int)(SAMPLING_INTERVAL / TASK_INTERVAL);

		virtual ~SpeedCal();
};