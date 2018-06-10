#define BUFFER_SIZE 10

class Filter {

private:
    const int BAND_MAX = 50;
    const int BAND_MIN = 5;
    int buffer[BUFFER_SIZE] = {};
    int bufferSubscript = 0;

public:
    Filter();

    /**
     * lowpass - ローパスフィルター
     *
     * @param  {int} value センサ値
     * @return {int} 計算結果
     */
    int lowpass(int value);

    /**
     * band - バンド幅補正
     *
     * @param  {void}
     * @return {void} 計算結果
     */
    int band(int value, int white, int black);
    virtual ~Filter();
};