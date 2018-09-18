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
        patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, -110, DIRECTION_RIGHT));
        edge_line = Line_R;
    }else{
        patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, -100, DIRECTION_RIGHT));
        edge_line = Line_R;
    }
    
}

void Game::turnL(){
    if(edge_line==Line_R){
        patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, 100, DIRECTION_LEFT));
        edge_line = Line_L;
    }else{
        patterns.push_back(new RunPattern(TURNING, 20, DIRECTION, 110, DIRECTION_LEFT));
        edge_line = Line_L;
    }
}

void Game::turnBack(){
    if(edge_line==Line_R){
        patterns.push_back(new RunPattern(SPIN, 10, DIRECTION, -90, DIRECTION_RIGHT));
        patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 1));
        patterns.push_back(new RunPattern(SPIN, 10, COLOR, COLOR_BLACK, DIRECTION_RIGHT));
    }else{
        patterns.push_back(new RunPattern(SPIN, -10, DIRECTION, 90, DIRECTION_LEFT));
        patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 1));
        patterns.push_back(new RunPattern(SPIN, -10, COLOR, COLOR_BLACK, DIRECTION_LEFT));
    }
}

void Game::release(int direction, int before_point, int now_point){
    patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 12));
    int jump_direction = jumpDirection(before_point, now_point);
    switch(direction){
        case JUMP:
            switch(jump_direction){
                case LEF:
                    //左回り
                    if(edge_line==Line_L){
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20, DIRECTION_LEFT));
                        patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -50, DIRECTION_RIGHT));
                        patterns.push_back(new RunPattern(STRAIGHT, 14, BLACKLINE, 0));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20, DIRECTION_RIGHT));
                        edge_line = Line_R;
                    }else{
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20, DIRECTION_LEFT));
                        patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -55, DIRECTION_RIGHT));
                        patterns.push_back(new RunPattern(STRAIGHT, 14, BLACKLINE, 0));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20, DIRECTION_RIGHT));
                        edge_line = Line_R;
                    }
                break;
                case RIG:
                    //右回り
                    if(edge_line==Line_L){
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20, DIRECTION_RIGHT));
                        patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 50, DIRECTION_LEFT));
                        patterns.push_back(new RunPattern(STRAIGHT, 14, BLACKLINE, 0));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20, DIRECTION_LEFT));
                        edge_line = Line_L;
                    }else{
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20, DIRECTION_RIGHT));
                        patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 50, DIRECTION_LEFT));
                        patterns.push_back(new RunPattern(STRAIGHT, 14, BLACKLINE, 0));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20, DIRECTION_LEFT));
                        edge_line = Line_L;
                    }
                break;
            }
            break;
        case TL:
            if(edge_line==Line_R){
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20, DIRECTION_LEFT));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));
                edge_line = Line_L;
            }else{
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));
                edge_line = Line_L;
            }
            break;
        case TR:
            if(edge_line==Line_L){
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20, DIRECTION_RIGHT));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30, DIRECTION_RIGHT));
                edge_line = Line_R;
            }else{
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30, DIRECTION_RIGHT));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30, DIRECTION_RIGHT));
                edge_line = Line_R;
            }
            break;
        case TB:
            break;
    }
}

void Game::jump(){
    patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 13));
    if(edge_line==Line_L){
        patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 11, 1.5, 0.0, 0.1, 25, LEFT));
    }else{
        patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 11, 1.5, 0.0, 0.1, 25, RIGHT));
    }
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 16));
}

void Game::blockcatch(int direction){
    if(direction==TB){
        patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 7));
    }
}

int Game::jumpDirection(int before_point, int now_point){
    if(now_point==1){
        if(before_point==0){
            return RIG;
        }
        if(before_point==2){
            return LEF;
        }
    }
    if(now_point==2){
        if(before_point==1){
            return RIG;
        }
        if(before_point==3){
            return LEF;
        }
    }

    if(now_point==4){
        if(before_point==0){
            return LEF;
        }
        if(before_point==8){
            return RIG;
        }
    }
    if(now_point==8){
        if(before_point==4){
            return LEF;
        }
        if(before_point==12){
            return RIG;
        }
    }

    if(now_point==13){
        if(before_point==12){
            return LEF;
        }
        if(before_point==14){
            return RIG;
        }
    }
    if(now_point==14){
        if(before_point==13){
            return LEF;
        }
        if(before_point==15){
            return RIG;
        }
    }

    if(now_point==7){
        if(before_point==3){
            return RIG;
        }
        if(before_point==11){
            return LEF;
        }
    }
    if(now_point==11){
        if(before_point==7){
            return RIG;
        }
        if(before_point==15){
            return LEF;
        }
    }

    return LEF;
}

void Game::startGame(){

    // edge_line = Line_L;
    // straight(RED);

    // release(TR);

    // straight(YELLOW);

    // patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 20, 1.5, 0.0, 0.1, 25));

    patterns.push_back(new RunPattern(LINE_TRACE, 40, DISTANCE, 120, 0.6, 0.00, 0.03, 70));
    patterns.push_back(new RunPattern(LINE_TRACE, 40, COLOR, COLOR_RED, 0.6, 0.0, 0.03, 25));
    Block &block = Block::singleton();
    int blocks[4]={block.red, block.yellow, block.green, block.blue};
    dijkstra->setBlock(blocks);
    dijkstra->run();
    dijkstra->createPat();
    for(int j=0;j<4;j++){
        int color_num=0;
        int now_num=0;
        for(int i=0;i<30;i++){
            if(dijkstra->pat[j][i]==-1){
                break;
            }
            switch(dijkstra->pat[j][i]){
                case ST:
                    straight(dijkstra->direct_color[j][color_num]);
                    color_num++;
                    now_num++;
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
                        release(dijkstra->pat[j+1][0], dijkstra->now_point[j][now_num-1] ,dijkstra->now_point[j][now_num]);
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

    dijkstra->escape();
    int color_num=0;
    int now_num=0;
    for(int i=0;i<30;i++){
        if(dijkstra->es_pat[i]==-1){
            break;
        }
        switch(dijkstra->es_pat[i]){
            case ST:
                straight(dijkstra->es_direct_color[color_num]);
                color_num++;
                now_num++;
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
            case REL:
                if(i==0){
                    release(dijkstra->es_pat[i+1], dijkstra->now_point[3][dijkstra->now_point_num-1], dijkstra->es_route[dijkstra->now_point_num]);
                }else{
                    release(dijkstra->es_pat[i+1], dijkstra->es_route[now_num-1] ,dijkstra->es_route[now_num]);
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
    switch(dijkstra->now_state){
        case UP:
            release(TR,15,11);
            break;
        case RIG:
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 20, DIRECTION_LEFT));
            patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -50, DIRECTION_RIGHT));
            patterns.push_back(new RunPattern(STRAIGHT, 14, DISTANCE, 30));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -20, DIRECTION_RIGHT));
            break;
        case DOWN:
            release(TL,7,11);
            break;
    }
}