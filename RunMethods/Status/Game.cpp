#include "Game.h"

Game::Game(){
    dijkstra = new Dijkstra();
    startGame();
    setNextState();
}

Game::~Game(){
}

void Game::init(){
}

void Game::setNextState(){
    nextState = STOP;
}

void Game::startGame(){
    int block[4]={5,14,10,9};
    dijkstra->setBlock(block);
    dijkstra->run();
    dijkstra->createPat();
    
    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_RED, 1.5, 0.0, 0.1, 40));
    patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, 90));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_BLUE, 1.5, 0.0, 0.1, 40));
    patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, -90));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_GREEN, 1.5, 0.0, 0.1, 40));
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 15, 1.5, 0.0, 0.01));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_RED, 1.5, 0.0, 0.1, 40));
    patterns.push_back(new RunPattern(SPIN, 5, DIRECTION, 180));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_GREEN, 1.5, 0.0, 0.1, 40));
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 15, 1.5, 0.0, 0.01));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_BLUE, 1.5, 0.0, 0.1, 40));
    patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, 90));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_RED, 1.5, 0.0, 0.1, 40));


    // patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 15, 1.5, 0.0, 0.01));
    // patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 15, 1.5, 0.0, 0.1, 40));
    // patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, 90));

    // patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_YELLOW, 1.5, 0.0, 0.1, 40));
    // patterns.push_back(new RunPattern(SPIN, 5, DIRECTION, 180));
    // patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_RED, 1.5, 0.0, 0.1, 40));
    // patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, -90));
    // patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_BLUE, 1.5, 0.0, 0.1, 40));

    for(int i=0;i<30;i++){
        if(dijkstra->pat[0][i]!=-1){
            break;
        }
    }
}