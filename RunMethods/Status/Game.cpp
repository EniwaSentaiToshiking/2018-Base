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
    nextState = PARKING;
}

void Game::straight(int color){
    Edge edge;
    if(edge_line==Line_L){
        edge = LEFT;
    }else{
        edge = RIGHT;
    }
    patterns.push_back(new RunPattern(LINE_TRACE, 20, DISTANCE, 5, 1.5, 0.0, 0.1, 25, edge));
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

void Game::turnBack(int catch_flag){
    if(catch_flag==0){
        if(edge_line==Line_R){
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -90, DIRECTION_RIGHT));
            patterns.push_back(new RunPattern(SPIN, 20, BLACKLINE, 0, DIRECTION_RIGHT));
        }else{
            patterns.push_back(new RunPattern(SPIN, -20, DIRECTION, 90, DIRECTION_LEFT));
            patterns.push_back(new RunPattern(SPIN, -20, BLACKLINE, 0, DIRECTION_LEFT));
        }
        return;
    }
    if(edge_line==Line_R){
        patterns.push_back(new RunPattern(SPIN, 10, DIRECTION, -90, DIRECTION_RIGHT));
        patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 1));
        patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
        patterns.push_back(new RunPattern(SPIN, 10, BLACKLINE, 0, DIRECTION_RIGHT));
    }else{
        patterns.push_back(new RunPattern(SPIN, -10, DIRECTION, 90, DIRECTION_LEFT));
        patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 1));
        patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
        patterns.push_back(new RunPattern(SPIN, -10, BLACKLINE, 0, DIRECTION_LEFT));
    }
}

void Game::release(int direction, int before_point, int now_point){
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
    patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 11));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
    int jump_direction = jumpDirection(before_point, now_point);
    switch(direction){
        case JUMP:
            switch(jump_direction){
                case LEF:
                    //左回り
                    if(edge_line==Line_L){
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));
                        patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -75, DIRECTION_RIGHT));
                        patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                        patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, -30, DIRECTION_RIGHT));
                        edge_line = Line_R;
                    }else{
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));
                        patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -75, DIRECTION_RIGHT));
                        patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                        patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, -30, DIRECTION_RIGHT));
                        edge_line = Line_R;
                    }
                break;
                case RIG:
                    //右回り
                    if(edge_line==Line_L){
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30, DIRECTION_RIGHT));
                        patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 75, DIRECTION_LEFT));
                        patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                        patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, 30, DIRECTION_LEFT));
                        edge_line = Line_L;
                    }else{
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30, DIRECTION_RIGHT));
                        patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
                        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 75, DIRECTION_LEFT));
                        patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                        patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, 30, DIRECTION_LEFT));
                        edge_line = Line_L;
                    }
                break;
            }
            break;
        case TL:
            if(edge_line==Line_R){
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, 30, DIRECTION_LEFT));
                edge_line = Line_L;
            }else{
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, 33, DIRECTION_LEFT));
                edge_line = Line_L;
            }
            break;
        case TR:
            if(edge_line==Line_L){
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30, DIRECTION_RIGHT));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, -30, DIRECTION_RIGHT));
                edge_line = Line_R;
            }else{
                patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30, DIRECTION_RIGHT));
                patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 4));
                patterns.push_back(new RunPattern(STRAIGHT, 20, BLACKLINE, 0));
                patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, -33, DIRECTION_RIGHT));
                edge_line = Line_R;
            }
            break;
        case TB:
            break;
    }
}

void Game::jump(){
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 12));
    if(edge_line==Line_L){
        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 15, DIRECTION_LEFT));
        edge_line = Line_L;
    }else{
        patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -15, DIRECTION_RIGHT));
        edge_line = Line_R;
    }
}

void Game::blockcatch(int direction){
    if(direction==TB){
        patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 4));
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
    //ここからゲーム開始
    patterns.push_back(new RunPattern(LINE_TRACE, 40, DISTANCE, 100, 0.6, 0.00, 0.03, 70));
    patterns.push_back(new RunPattern(LINE_TRACE, 20, COLOR, COLOR_RED, 0.6, 0.0, 0.03, 25));
    Block &block = Block::singleton();
    int blocks[4]={block.red, block.yellow, block.green, block.blue};
    int dead_flag = 0;
    for(int i= 0;i<4;i++){
        if(blocks[i]==4||blocks[i]==8||blocks[i]==9||blocks[i]==12){
            dead_flag++;
        }
    }
    if(dead_flag==4){
        release(TL,1,2);
        straight(YELLOW);
        dijkstra->start_area = 4;
        dijkstra->now_state = UP;
    }else{
        dijkstra->start_area = 8;
        dijkstra->now_state = RIG;
    }
    dijkstra->setBlock(blocks);
    dijkstra->run();
    dijkstra->createPat();
    int last_num =0;
    for(int j=0;j<4;j++){
        int color_num=0;
        int now_num=0;
        int catch_flag = 0;
        for(int i=0;i<30;i++){
            if(dijkstra->pat[j][i]==-1){
                break;
            }
            switch(dijkstra->pat[j][i]){
                case ST:
                    straight(dijkstra->direct_color[j][color_num]);
                    color_num++;
                    last_num = now_num;
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
                    turnBack(catch_flag);
                    break;
                case CAT:
                    blockcatch(dijkstra->pat[j][i+1]);
                    catch_flag = 1;
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

    if(dijkstra->now_point[3][last_num]!=11){
        dijkstra->escape();
        int color_num=1;
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
                    if(dijkstra->es_pat[i-1]!=REL){
                        turnL();
                    }
                    break;
                case TR:
                    if(dijkstra->es_pat[i-1]!=REL){
                        turnR();
                    }
                    break;
                case TB:
                    turnBack(0);
                    break;
                case REL:
                    if(i==0){
                        release(dijkstra->es_pat[i+1], dijkstra->now_point[3][dijkstra->now_point_num-2], dijkstra->now_point[3][dijkstra->now_point_num-1]);
                    }else{
                        release(dijkstra->es_pat[i+1], dijkstra->es_route[now_num-1] ,dijkstra->es_route[now_num]);
                    }
                    break;
                case JUMP:
                    if(dijkstra->es_pat[i-1]!=REL){
                        jump();
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if(dijkstra->block[2]==11){
        switch(dijkstra->now_state){
        case UP:
            patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
            patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 12));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -30, DIRECTION_RIGHT));
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -45, DIRECTION_RIGHT));
            break;
        case RIG:
            patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
            patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 12));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));            
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -65, DIRECTION_RIGHT));
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 40, DIRECTION_LEFT));
            break;
        case DOWN:
            patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
            patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 12));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 30, DIRECTION_LEFT));
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 45, DIRECTION_LEFT));
            break;
        }
    }else{
        switch(dijkstra->now_state){
        case UP:
            patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 6));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, -80, DIRECTION_RIGHT));
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 10));
            break;
        case RIG:
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 15));
            break;
        case DOWN:
            patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 300));
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 2));
            patterns.push_back(new RunPattern(SPIN, 20, DIRECTION, 80, DIRECTION_LEFT));
            patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 10));
            break;
        }
    }
}