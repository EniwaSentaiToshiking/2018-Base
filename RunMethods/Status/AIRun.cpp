#include "AIRun.h"

AIRun::AIRun(){
    
    Localization* localization = new Localization();
    localization->distance_reset();

    analogLog  = new AnalogLog();
    digitalLog = new DigitalLog();
    answer = new AIAnswer();

    /* デジタル走行 */
    patterns.push_back(new RunPattern(LINE_TRACE, NORMAL, COLOR, COLOR_GREEN, 0.3, 0.01, 0.1, 50, LEFT));
    patterns.push_back(new RunPattern(STRAIGHT , NORMAL, BRIGHTNESS, AI_GREEN_WHITE));
    patterns.push_back(new RunPattern(STRAIGHT , NORMAL, DISTANCE, 3));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN , HIGH, BRIGHTNESS, AI_GREEN_WHITE, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(LINE_TRACE,  NORMAL, BRIGHTNESS, EDGE, 1.5, 0.0, 0.025, 90, RIGHT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT , -NORMAL, DISTANCE, 3));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, HIGH, DIRECTION, 15, DIRECTION_LEFT));
    
    patterns.push_back(new RunPattern(SPIN, HIGH, BRIGHTNESS, AI_GREEN_WHITE, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(LINE_TRACE, NORMAL, DISTANCE, 21, 1.5, 0.0, 0.025, 90, LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, DIRECTION, 90, DIRECTION_LEFT, -90));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT, SLOW, DISTANCE, 11)); //第一回
    patterns.push_back(new RunPattern(STRAIGHT, SLOW, DISTANCE, 13)); //第二回
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, BRIGHTNESS, AI_GREEN_WHITE)); //緑まで前
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, DISTANCE, 5));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, HIGH, BRIGHTNESS, AI_GREEN_WHITE, DIRECTION_LEFT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(LINE_TRACE, NORMAL, DISTANCE, 13, 1.5, 0.0, 0.025, 90, LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, DIRECTION, 90, DIRECTION_LEFT, -90));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT, SLOW, DISTANCE, 8)); //第三回
    // 下から上へ
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, DISTANCE, 8));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, DIRECTION, 90, DIRECTION_LEFT, 180)); //行き過ぎるので恣意的に低くしている
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT, -NORMAL, DISTANCE, 5));
    patterns.push_back(new RunPattern(STRAIGHT, SLOW, DISTANCE, 13)); //第四回
    patterns.push_back(new RunPattern(STRAIGHT, SLOW, DISTANCE, 13)); //第五回

    /* アナログ走行 */
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, BRIGHTNESS, AI_GREEN_WHITE));
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, DISTANCE, 5));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, BRIGHTNESS, AI_GREEN_WHITE, DIRECTION_RIGHT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(LINE_TRACE, NORMAL, BRIGHTNESS, EDGE, 1.5, 0.0, 0.025, AI_GREEN_WHITE, RIGHT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, DIRECTION, 15, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(SPIN, NORMAL, BRIGHTNESS, AI_GREEN_WHITER, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(LINE_TRACE, NORMAL, BRIGHTNESS, EDGE, 1.5, 0.0, 0.025, 90, LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, DISTANCE, 3)); 
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, BRIGHTNESS, AI_GREEN_WHITE, DIRECTION_LEFT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(LINE_TRACE, NORMAL, DISTANCE, 16, 1.5, 0.0, 0.025, 90, LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, DIRECTION, -90, DIRECTION_RIGHT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, BRIGHTNESS, AI_WHITE)); //白まで直進
    patterns.push_back(new RunPattern(STRAIGHT, SLOW, DISTANCE, 20)); //アナログ数字第一回
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, BRIGHTNESS, AI_GREEN_WHITE)); //緑まで前
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, DISTANCE, 4));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, BRIGHTNESS, AI_WHITE, DIRECTION_LEFT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(LINE_TRACE, NORMAL, DISTANCE, 15, 1.5, 0.0, 0.025, 90, LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, DIRECTION, 90, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT, SLOW, DISTANCE, 26)); //アナログ数字第2回
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, BRIGHTNESS, AI_GREEN_WHITE)); //緑まで前
    patterns.push_back(new RunPattern(STRAIGHT, -NORMAL, DISTANCE, 7));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(SPIN, NORMAL, DIRECTION, -90, DIRECTION_RIGHT)); //白まで回転
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 1000));
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, DISTANCE, 15));
    patterns.push_back(new RunPattern(STRAIGHT, NORMAL, BRIGHTNESS, AI_WHITE)); //白まで前
    patterns.push_back(new RunPattern(BRAKE, 0, DISTANCE, 10));

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
    if(shouldLogging() == DIGITAL_ANSWER) {
        int digiNum = answer->answerDigital(digitalLog);
        char num[10];
        sprintf(num, "%d", digiNum);
        ev3_lcd_set_font(EV3_FONT_MEDIUM);
        ev3_lcd_draw_string(num, 10, 60);
    }
    if(shouldLogging() == ANALOG_ANSWER) {
        answer->answerAnalog(analogLog);
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
        return DIGITAL_ANSWER;
    }
    if(logPattern[currentPattern] == 4) {
        return ANALOG_ANSWER;
    }
    return NONE_LOG;
}
