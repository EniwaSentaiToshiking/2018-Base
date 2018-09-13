#include "Dijkstra.h"

Dijkstra::Dijkstra(){
	settled_block[0]=0;
	settled_block[1]=0;
	settled_block[2]=0;
	settled_block[3]=0;
	start_area=8;
	now_state = RIG;
}

Dijkstra::~Dijkstra(){
}

void Dijkstra::initNode(){
	for(int i = 0; i < SIZE; i++) {
    	COST[i] = INF;
    	USED[i] = FALSE;
    	VIA[i] = -1;
    	for(int j = 0; j < SIZE; j++)
      		DIST[i][j] = INF;
    }
}

void Dijkstra::setStart(int x){
	start = x;
}

void Dijkstra::setDestination(int x){
	distination = x;
}

void Dijkstra::setNodeCount(int x){
	N = x;
}

void Dijkstra::setEdgeCount(int x){
	r = x;
}

void Dijkstra::setNode(){
	DIST[0][1] = 1;
  	DIST[0][4] = 1;
	DIST[1][0] = 1;
	DIST[1][2] = 1;
	DIST[1][5] = 1;
	DIST[2][1] = 1;
	DIST[2][3] = 1;
	DIST[2][6] = 1;
	DIST[3][2] = 1;
	DIST[3][7] = 1;
	DIST[4][0] = 1;
	DIST[4][5] = 1;
	DIST[4][8] = 1;
	DIST[5][1] = 1;
	DIST[5][4] = 1;
	DIST[5][6] = 1;
	DIST[5][9] = 1;
	DIST[6][2] = 1;
	DIST[6][5] = 1;
	DIST[6][7] = 1;
	DIST[6][10] = 1;
	DIST[7][3] = 1;
	DIST[7][6] = 1;
	DIST[7][11] = 1;
	DIST[8][4] = 1;
	DIST[8][9] = 1;
	DIST[8][12] = 1;
	DIST[9][5] = 1;
	DIST[9][8] = 1;
	DIST[9][10] = 1;
	DIST[9][13] = 1;
	DIST[10][6] = 1;
	DIST[10][9] = 1;
	DIST[10][11] = 1;
	DIST[10][14] = 1;
	DIST[11][7] = 1;
	DIST[11][10] = 1;
	DIST[11][15] = 1;
	DIST[12][8] = 1;
	DIST[12][13] = 1;
	DIST[13][9] = 1;
	DIST[13][12] = 1;
	DIST[13][14] = 1;
	DIST[14][10] = 1;
	DIST[14][13] = 1;
	DIST[14][15] = 1;
	DIST[15][11] = 1;
	DIST[15][14] = 1;
}

int Dijkstra::calCost(int start, int goal){
  	int min; 
  	int target=0;

  	COST[start] = 0;
  	while(1){
    	min = INF;
    	for(int i = 0; i < N; i++){
      		if(!USED[i] && min > COST[i]) {
        	min = COST[i];
        	target = i;
      		}
    	}
    	if(target == goal)
    		return COST[goal];
    	for(int neighboring = 0; neighboring < N; neighboring++){
    		if(COST[neighboring] > DIST[target][neighboring] + COST[target]) {
        		COST[neighboring] = DIST[target][neighboring] + COST[target];
        		VIA[neighboring] = target;
      		}
    	}
    	USED[target] = TRUE;
  	}
}

void Dijkstra::createRoute(int x){
	int a[30];
	for(int i=0;i<30;i++){
		a[i]=-1;
		route[x][i]=-1;
	}
	if(cost[x]==0){
		return;
	}
	int node = distination;
	int num = 0;
	a[num] = node;
	while(1){
		num++;
    	node = VIA[node];
    	a[num] = node;
    	if (node == start) {
    		break;
    	}
  	}
  	num = 0;
  	for(int i=29;i>-1;i--){
  		if(a[i]!=-1){
  			route[x][num] = a[i];
  			num++;
  		}
  	}
}

void Dijkstra::createRoute(int x, bool flag){
	int a[30];
	for(int i=0;i<30;i++){
		a[i]=-1;
		route[x][i]=-1;
	}
	if(flag==false){
		return;
	}
	int node = distination;
	int num = 0;
	a[num] = node;
	while(1){
		num++;
    	node = VIA[node];
    	a[num] = node;
    	if (node == start) {
    		break;
    	}
  	}
  	num = 0;
  	for(int i=29;i>-1;i--){
  		if(a[i]!=-1){
  			route[x][num] = a[i];
  			num++;
  		}
  	}
}

void Dijkstra::setBlock(int x[4]){
	block[RED] = x[RED];
	block[YELLOW] = x[YELLOW];
	block[GREEN] = x[GREEN];
	block[BLUE] = x[BLUE];		
}

void Dijkstra::deleteNode(int x){
	int color = x;
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if(i==color||j==color){
				DIST[i][j] = INF;
			}
		}
	}
}

int Dijkstra::searchMinBlock(int u){
	int min_cost = INF;
	int min_block = 0;
	for(int i=0;i<4;i++){
		if(min_cost > cost[i]){
			min_block = i;
			min_cost = cost[i];
		}
	}
	for(int i=0;i<30;i++){
		if(route[min_block][i]!=-1){
			to_block_route[u][i]=route[min_block][i];
		}else{
			to_block_route[u][i]=-1;
		}
	}
	return min_block;
}

int Dijkstra::searchMinBlockArea(int u){
	int min_cost = INF;
	int min_block_area =0;
	int carry_block_area=-1;
	for(int i=0;i<4;i++){
		if(min_cost > cost[i]){
			min_block_area = i;
			min_cost = cost[i];
		}
	}
	for(int i=0;i<30;i++){
		if(route[min_block_area][i]!=-1){
			to_area_route[u][i]=route[min_block_area][i];
			carry_block_area=route[min_block_area][i];
		}else{
			to_area_route[u][i]=-1;
		}
	}
	return carry_block_area;
}

void Dijkstra::searchSameColorBlockArea(int color){
	switch(color){
		case RED:
			block_area[0]=0;
			block_area[1]=6;
			block_area[2]=8;
			block_area[3]=14;
			break;
		case YELLOW:
			block_area[0]=1;
			block_area[1]=7;
			block_area[2]=9;
			block_area[3]=15;
			break;
		case GREEN:
			block_area[0]=3;
			block_area[1]=5;
			block_area[2]=11;
			block_area[3]=13;
			break;
		case BLUE:
			block_area[0]=2;
			block_area[1]=4;
			block_area[2]=10;
			block_area[3]=12;
			break;
	}
}

int Dijkstra::colorCheck(int x){
	switch(x){
		case 0:
			return RED;
		case 1:
			return YELLOW;
		case 2:
			return GREEN;
		case 3:
			return BLUE; 
	}
	return -1;
}

int Dijkstra::stateCheck(int now, int next){
	int state;
	switch(now){
		case 0:
			switch(next){
				case 1:
					state = RIG;
					break;
				case 4:
					state = DOWN;
					break; 
			}
			break;
		case 1:
			switch(next){
				case 0:
					state = LEF;
					break;
				case 2:
					state = RIG;
					break;
				case 5:
					state = DOWN;
					break;
			}
			break;
		case 2:
			switch(next){
				case 1:
					state = LEF;
					break;
				case 3:
					state = RIG;
					break;
				case 6:
					state = DOWN;
					break;
			}
			break;
		case 3:
			switch(next){
				case 2:
					state = LEF;
					break;
				case 7:
					state = DOWN;
					break;
			}
			break;
		case 4:
			switch(next){
				case 0:
					state = UP;
					break;
				case 5:
					state = RIG;
					break;
				case 8:
					state = DOWN;
					break;
			}
			break;
		case 5:
			switch(next){
				case 1:
					state = UP;
					break;
				case 4:
					state = LEF;
					break;
				case 6:
					state = RIG;
					break;
				case 9:
					state = DOWN;
					break;
			}
			break;
		case 6:
			switch(next){
				case 2:
					state = UP;
					break;
				case 5:
					state = LEF;
					break;
				case 7:
					state = RIG;
					break;
				case 10:
					state = DOWN;
					break;
			}
			break;
		case 7:
			switch(next){
				case 3:
					state = UP;
					break;
				case 6:
					state = LEF;
					break;
				case 11:
					state = DOWN;
					break;
			}
			break;
		case 8:
			switch(next){
				case 4:
					state = UP;
					break;
				case 9:
					state = RIG;
					break;
				case 12:
					state = DOWN;
					break;
			}
			break;
		case 9:
			switch(next){
				case 5:
					state = UP;
					break;
				case 8:
					state = LEF;
					break;
				case 10:
					state = RIG;
					break;
				case 13:
					state = DOWN;
					break;
			}
			break;
		case 10:
			switch(next){
				case 6:
					state = UP;
					break;
				case 9:
					state = LEF;
					break;
				case 11:
					state = RIG;
					break;
				case 14:
					state = DOWN;
					break;
			}
			break;
		case 11:
			switch(next){
				case 7:
					state = UP;
					break;
				case 10:
					state = LEF;
					break;
				case 15:
					state = DOWN;
					break;
			}
			break;
		case 12:
			switch(next){
				case 8:
					state = UP;
					break;
				case 13:
					state = RIG;
					break;
			}
			break;
		case 13:
			switch(next){
				case 9:
					state = UP;
					break;
				case 12:
					state = LEF;
					break;
				case 14:
					state = RIG;
					break;
			}
			break;
		case 14:
			switch(next){
				case 10:
					state = UP;
					break;
				case 13:
					state = LEF;
					break;
				case 15:
					state = RIG;
					break;
			}
			break;
		case 15:
			switch(next){
				case 11:
					state = UP;
					break;
				case 14:
					state = LEF;
					break;
			}
			break;
	}
	return state;
}

void Dijkstra::setPat(int i, int now, int next){
	int next_state = stateCheck(now,next);
	pat[i][pat_num]=checkTurn(next_state);
	pat_num++;
	pat[i][pat_num]=ST;
	pat_num++;
	now_state = next_state;
}

void Dijkstra::createPat(){
	for(int i=0;i<4;i++){
		for(int j=0;j<60;j++){
			pat[i][j]=-1;
		}
	}
	for(int i=0;i<4;i++){
		pat_num = 0;
		for(int j=0;j<30;j++){
			if(to_block_route[i][j+1]!=-1){
				int now = to_block_route[i][j];
				int next = to_block_route[i][j+1];
				setPat(i, now, next);
			}else{
				break;
			}
		}
		pat[i][pat_num]=CAT;
		pat_num++;
		for(int j=0;j<30;j++){
			if(to_area_route[i][j+1]!=-1){
				int now = to_area_route[i][j];
				int next = to_area_route[i][j+1];
				setPat(i, now, next);
			}else{
				break;
			}
		}
		pat[i][pat_num]=REL;
	}
	directColor();
}	

int Dijkstra::checkTurn(int next_state){
	int direction=100;
	switch(now_state){
		case UP:
			switch(next_state){
				case UP:
					direction = JUMP;
					break;
				case LEF:
					direction = TL;
					break;
				case RIG:
					direction = TR;
					break;
				case DOWN:
					direction = TB;
					break;
			}
			break;
		case LEF:
			switch(next_state){
				case UP:
					direction = TR;
					break;
				case LEF:
					direction = JUMP;
					break;
				case RIG:
					direction = TB;
					break;
				case DOWN:
					direction = TL;
					break;
			}
			break;
		case RIG:
			switch(next_state){
				case UP:
					direction = TL;
					break;
				case LEF:
					direction = TB;
					break;
				case RIG:
					direction = JUMP;
					break;
				case DOWN:
					direction = TR;
					break;
			}
			break;
		case DOWN:
			switch(next_state){
				case UP:
					direction = TB;
					break;
				case LEF:
					direction = TR;
					break;
				case RIG:
					direction = TL;
					break;
				case DOWN:
					direction = JUMP;
					break;
			}
			break;
	}
	return direction;
}

void Dijkstra::directColor(){
	for(int i=0;i<4;i++){
		for(int j=0;j<60;j++){
			direct_color[i][j]=-1;
		}
	}
	for(int i=0;i<4;i++){
		int x=0;
		for(int j=1;j<30;j++){
			if(to_block_route[i][j]!=-1){
				direct_color[i][x]=colorArea(to_block_route[i][j]);
				x++;	
			}
		}
		x--;
		for(int j=0;j<30;j++){
			if(to_area_route[i][j]!=-1){
				direct_color[i][x]=colorArea(to_area_route[i][j]);
				x++;
			}
		}
	}
}

int Dijkstra::colorArea(int area){
	switch(area){
		case 0:
		case 6:
		case 8:
		case 14:
			return RED;
		case 1:
		case 7:
		case 9:
		case 15:
			return YELLOW;
		case 3:
		case 5:
		case 11:
		case 13:
			return GREEN;
		case 2:
		case 4:
		case 10:
		case 12:
			return BLUE;
	}
	return 0;
}

void Dijkstra::run(){
	for(int u=0;u<4;u++){
		//ブロックまでの経路
		for(int i=0;i<4;i++){
			if(settled_block[i]==0){
				initNode();
				setStart(start_area);
				setDestination(block[i]);

				setNodeCount(16);
				setEdgeCount(48);
				setNode();

				for(int j=0;j<4;j++){
					if(block[j]!=start_area&&i!=j){
						deleteNode(block[j]);
					}
				}
				cost[i] = calCost(start, distination);
				createRoute(i);
			}else{
				cost[i]=INF;
			}
		}
		int carry_block_num = searchMinBlock(u);

		//ブロック置き場までの経路
		int carry_block = block[carry_block_num];
		int carry_block_color= colorCheck(carry_block_num);
		searchSameColorBlockArea(carry_block_color);

		for(int i=0;i<4;i++){
			initNode();
			setStart(carry_block);
			setDestination(block_area[i]);

			setNodeCount(16);
			setEdgeCount(48);
			setNode();

			for(int j=0;j<4;j++){
				if(block[j] != carry_block){
					deleteNode(block[j]);
				}
			}

			bool flag = true;
			for(int j=0;j<4;j++){
				if(block_area[i]==block[j]){
					cost[i] = INF;
					flag = false;
					createRoute(i,flag);
					break;
				}
			}
			if(flag == true){
				cost[i] = calCost(start, distination);
				createRoute(i,flag);
			}
		}
		int carry_area = searchMinBlockArea(u);
		settled_block[carry_block_num]=1;
		block[carry_block_color]=carry_area;
		start_area=carry_area;
	}
}
