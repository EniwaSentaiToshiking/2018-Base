#include "Game.h"

Game::Game(){
    dijkstra = new Dijkstra();
    startGame();
    setNextState();
    edge_line = Line_L;
}

Game::~Game(){
    delete dijkstra;
}

void Game::init(){
}

void Game::setNextState(){
    nextState = STOP;
}

void Game::straight(int color){
    Edge edge;
    if(edge_line==Line_L){
        edge = LEFT;
    }else{
        edge = RIGHT;
    }
    switch(color){
        case RED:
            patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_RED, 1.5, 0.0, 0.1, 25, edge));
            break;
        case YELLOW:
            patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_YELLOW, 1.5, 0.0, 0.1, 25, edge));
            break;
        case GREEN:
            patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_GREEN, 1.5, 0.0, 0.1, 25, edge));
            break;
        case BLUE:
            patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_BLUE, 1.5, 0.0, 0.1, 25, edge));
            break;
    }
}

void Game::turnR(){
    if(edge_line==Line_R){
        patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, -110));
        edge_line = Line_R;
    }else{
        patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, -130));
        edge_line = Line_R;
    }
    
}

void Game::turnL(){
    if(edge_line==Line_R){
        patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, 110));
        edge_line = Line_L;
    }else{
        patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, 130));
        edge_line = Line_L;
    }
}

void Game::turnBack(){
    if(edge_line==Line_R){
        patterns.push_back(new RunPattern(SPIN, 12, DIRECTION, 90));
        patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 1));
        patterns.push_back(new RunPattern(SPIN, 12, COLOR, COLOR_BLACK));
    }else{
        patterns.push_back(new RunPattern(SPIN, 12, DIRECTION, -90));
        patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 1));
        patterns.push_back(new RunPattern(SPIN, -12, COLOR, COLOR_BLACK));
    }
}

void Game::release(int direction){
    patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 12, 1.5, 0.0, 0.01));
    switch(direction){
        case JUMP:
            //左回り
            if(edge_line==Line_L){
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20));
                patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -50));
                patterns.push_back(new RunPattern(STRAIGHT, 14, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20));
                edge_line = Line_R;
            }else{
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20));
                patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -55));
                patterns.push_back(new RunPattern(STRAIGHT, 14, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20));
                edge_line = Line_R;
            }
            //右回り
            // if(edge_line==Line_L){
            //     patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20));
            //     patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30, 1.5, 0.0, 0.01));
            //     patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 60));
            //     patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 28, 1.5, 0.0, 0.01));
            //     patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20));
            //     edge_line = Line_L;
            // }else{
            //     patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20));
            //     patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30, 1.5, 0.0, 0.01));
            //     patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 50));
            //     patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 28, 1.5, 0.0, 0.01));
            //     patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20));
            //     edge_line = Line_L;
            // }
            break;
        case TL:
            if(edge_line==Line_R){
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30));
                edge_line = Line_L;
            }else{
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30));
                edge_line = Line_L;
            }
            break;
        case TR:
            if(edge_line==Line_L){
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30));
                edge_line = Line_R;
            }else{
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30));
                edge_line = Line_R;
            }
            break;
        case TB:
            break;
    }
}

void Game::jump(){
    patterns.push_back(new RunPattern(STRAIGHT, -15, DISTANCE, 10));
    if(edge_line==Line_L){
        patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 10, 1.5, 0.0, 0.1, 25, LEFT));
    }else{
        patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 10, 1.5, 0.0, 0.1, 25, RIGHT));
    }
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 15));
}

void Game::blockcatch(int direction){
    if(direction!=JUMP){
        patterns.push_back(new RunPattern(STRAIGHT, 8, DISTANCE, 4));
    }
}

void Game::startGame(){

    // edge_line = Line_L;
    // straight(RED);

    // release(TR);

    // straight(YELLOW);

    // patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 20, 1.5, 0.0, 0.1, 25));

    // //patterns.push_back(new RunPattern(LINE_TRACE, 80, DISTANCE, 2000, 0.25, 0.00, 0.03, 60));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_RED, 1.5, 0.0, 0.1, 25));
    int block[4]={4,3,7,8};
    dijkstra->setBlock(block);
    dijkstra->run();
    dijkstra->createPat();
    for(int j=0;j<4;j++){
        int color_num=0;
        for(int i=0;i<30;i++){
            if(dijkstra->pat[j][i]==-1){
                break;
            }
            switch(dijkstra->pat[j][i]){
                case ST:
                    straight(dijkstra->direct_color[j][color_num]);
                    color_num++;
                    break;
                case TL:
                    if(i!=0){
                        turnL();
                    }
                    break;
                case TR:
                    if(i!=0){
                        turnR();
                    }
                    break;
                case TB:
                    turnBack();
                    break;
                case CAT:
                    blockcatch(dijkstra->pat[j][i+1]);
                    break;
                case REL:
                    if(j!=3){
                        release(dijkstra->pat[j+1][0]);
                    }
                    break;
                case JUMP:
                    if(i!=0){
                        jump();
                    }
                    break;
                default:
                    break;
            }
        }
    }
}