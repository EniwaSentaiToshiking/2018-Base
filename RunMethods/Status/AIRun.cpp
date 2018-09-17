#include "AIRun.h"

AIRun::AIRun(){
    analogLog  = new AnalogLog();
    digitalLog = new DigitalLog();
    answer = new AIAnswer();

    // デジタル走行
    patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 9, 0.3, 0.001, 0.1, 50, LEFT));
    patterns.push_back(new RunPattern(STRAIGHT, 10, COLOR, COLOR_GREEN));
    patterns.push_back(new RunPattern(STRAIGHT, 10, BRIGHTNESS, 100));
    patterns.push_back(new RunPattern(STRAIGHT, SPEED , DISTANCE, 3));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, COLOR, 3, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(LINE_TRACE, -10, DISTANCE,  4,  0.2, 0.001, 0.05, 80, RIGHT));
    patterns.push_back(new RunPattern(LINE_TRACE,  10, DISTANCE,  13, 0.2, 0.001, 0.05, 80, RIGHT));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, DIRECTION, -90, DIRECTION_RIGHT));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(STRAIGHT, -SPEED, DISTANCE, 3));

    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 11)); //第一回
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 13)); //第二回

    patterns.push_back(new RunPattern(STRAIGHT, 10, COLOR, COLOR_GREEN));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 3));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, BRIGHTNESS, 100, DIRECTION_LEFT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 15, 0.3, 0.001, 0.05, 80, LEFT));

    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, DIRECTION, 90, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(STRAIGHT, SPEED, DISTANCE, 8)); //第三回

    // 下から上へ
    patterns.push_back(new RunPattern(STRAIGHT, SPEED, DISTANCE, 8));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, DIRECTION, 90, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(STRAIGHT, -SPEED, DISTANCE, 5));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 13)); //第四回
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 13)); //第五回

    // アナログ走行
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(STRAIGHT, 5, COLOR, COLOR_GREEN)); //緑まで前
    patterns.push_back(new RunPattern(STRAIGHT, 5, DISTANCE, 3));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, BRIGHTNESS, 100, DIRECTION_LEFT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(LINE_TRACE, 15, BRIGHTNESS, 50, 0.3, 0.001, 0.05, 80, LEFT));
    patterns.push_back(new RunPattern(STRAIGHT, 5, DISTANCE, 3)); 
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, BRIGHTNESS, 100, DIRECTION_LEFT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 15, 0.3, 0.001, 0.05, 80, LEFT));

    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, DIRECTION, -90, DIRECTION_RIGHT));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));

    patterns.push_back(new RunPattern(STRAIGHT, 15, BRIGHTNESS, 100)); //白まで直進
    patterns.push_back(new RunPattern(STRAIGHT, 15, DISTANCE, 25)); //アナログ数字第一回
    patterns.push_back(new RunPattern(STRAIGHT, 10, COLOR, COLOR_GREEN)); //緑まで前


    patterns.push_back(new RunPattern(STRAIGHT, 15, DISTANCE, 3));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, BRIGHTNESS, 100, DIRECTION_LEFT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 15, 0.2, 0.001, 0.05, 80, LEFT));
    
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, DIRECTION, 90, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(STRAIGHT, -SPEED, DISTANCE, 3));
    patterns.push_back(new RunPattern(STRAIGHT, 15, DISTANCE, 25)); //アナログ数字第2回
    patterns.push_back(new RunPattern(STRAIGHT, 10, BRIGHTNESS, 50)); //緑まで前

    patterns.push_back(new RunPattern(STRAIGHT, -15, DISTANCE, 15));
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(SPIN, 10, DIRECTION, -90, DIRECTION_RIGHT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 10, CLOCK, 100));
    patterns.push_back(new RunPattern(STRAIGHT, 15, DISTANCE, 15));

    patterns.push_back(new RunPattern(STRAIGHT, 10, BRIGHTNESS, 100)); //白まで前
    patterns.push_back(new RunPattern(BRAKE, 10, DISTANCE, 10));

    setNextState();
}

AIRun::~AIRun(){
    delete analogLog;
    delete digitalLog;
    delete answer;
}

void AIRun::init(){
}

void AIRun::setNextState(){
    nextState = STOP;
}

bool AIRun::run() {
    bool isFinishPattern = patterns[currentPattern]->run();
    if (isFinishPattern)
    {
        if(shouldLogging() == DIGITAL_LOG) {
            ev3_speaker_play_tone(400,400);
            digitalLog->finishLogging();
        }
        bool isFinishStatus = changeNextPattern();
        if(isFinishStatus) return true;
    } 

    // Logging
    if(shouldLogging() == ANALOG_LOG){
        analogLog->logging();
    }
    if(shouldLogging() == DIGITAL_LOG) {
        digitalLog->logging();
    }
    if(shouldLogging() == END_LOG) {
        digitalLog->saveLog("digitalNumber.csv");
        int digiNum = answer->answerDigital(digitalLog);
        char num[10];
        sprintf(num, "%d", digiNum);
        ev3_lcd_set_font(EV3_FONT_MEDIUM);
        ev3_lcd_draw_string(num, 10, 60);
    }

    return false;
}

void AIRun::saveLog() {
    digitalLog->saveLog("digitalNumber.log");
    analogLog->saveLog("analogNumber.log");
}

LogType AIRun::shouldLogging() {
    if(logPattern[currentPattern] == 1) {
        return DIGITAL_LOG;
    }
    if(logPattern[currentPattern] == 2) {
        return ANALOG_LOG;
    }
    if(logPattern[currentPattern] == 3) {
        return END_LOG;
    }
    return NONE_LOG;
}
