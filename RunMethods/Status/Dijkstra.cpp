#include "Dijkstra.h"

Dijkstra::Dijkstra(){
	settled_block[0]=0;
	settled_block[1]=0;
	settled_block[2]=0;
	settled_block[3]=0;
	start_area=8;
	now_state = RIGHT;
}

Dijkstra::~Dijkstra(){
}

/* 初期化 */
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

    /* 未確定の中から距離が最も小さい地点(a)を選んで、その距離を その地点の最小距離として確定します */
    	min = INF;
    	for(int i = 0; i < N; i++){
      		if(!USED[i] && min > COST[i]) {
        	min = COST[i];
        	target = i;
      		}
    	}

    /* 全ての地点の最短経路が確定 */
    	if(target == goal)
    		return COST[goal];

    /* 今確定した場所から「直接つながっている」かつ「未確定の」地点に関して、
    今確定した場所を経由した場合の距離を計算し、今までの距離よりも小さければ書き直します。 */
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
					state = RIGHT;
					break;
				case 4:
					state = DOWN;
					break; 
			}
			break;
		case 1:
			switch(next){
				case 0:
					state = LEFT;
					break;
				case 2:
					state = RIGHT;
					break;
				case 5:
					state = DOWN;
					break;
			}
			break;
		case 2:
			switch(next){
				case 1:
					state = LEFT;
					break;
				case 3:
					state = RIGHT;
					break;
				case 6:
					state = DOWN;
					break;
			}
			break;
		case 3:
			switch(next){
				case 2:
					state = LEFT;
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
					state = RIGHT;
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
					state = LEFT;
					break;
				case 6:
					state = RIGHT;
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
					state = LEFT;
					break;
				case 7:
					state = RIGHT;
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
					state = LEFT;
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
					state = RIGHT;
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
					state = LEFT;
					break;
				case 10:
					state = RIGHT;
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
					state = LEFT;
					break;
				case 11:
					state = RIGHT;
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
					state = LEFT;
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
					state = RIGHT;
					break;
			}
			break;
		case 13:
			switch(next){
				case 9:
					state = UP;
					break;
				case 12:
					state = LEFT;
					break;
				case 14:
					state = RIGHT;
					break;
			}
			break;
		case 14:
			switch(next){
				case 10:
					state = UP;
					break;
				case 13:
					state = LEFT;
					break;
				case 15:
					state = RIGHT;
					break;
			}
			break;
		case 15:
			switch(next){
				case 11:
					state = UP;
					break;
				case 14:
					state = LEFT;
					break;
			}
			break;
	}
	return state;
}

void Dijkstra::setPat(int i, int now, int next){
	int next_state = stateCheck(now,next);
	if(checkTurn(next_state)!=0){
		pat[i][pat_num]=checkTurn(next_state);
		pat_num++;
	}
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
}	

int Dijkstra::checkTurn(int next_state){
	int direction=100;
	switch(now_state){
		case UP:
			switch(next_state){
				case UP:
					direction = 0;
					break;
				case LEFT:
					direction = TL;
					break;
				case RIGHT:
					direction = TR;
					break;
				case DOWN:
					direction = TB;
					break;
			}
			break;
		case LEFT:
			switch(next_state){
				case UP:
					direction = TR;
					break;
				case LEFT:
					direction = 0;
					break;
				case RIGHT:
					direction = TB;
					break;
				case DOWN:
					direction = TL;
					break;
			}
			break;
		case RIGHT:
			switch(next_state){
				case UP:
					direction = TL;
					break;
				case LEFT:
					direction = TB;
					break;
				case RIGHT:
					direction = 0;
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
				case LEFT:
					direction = TR;
					break;
				case RIGHT:
					direction = TL;
					break;
				case DOWN:
					direction = 0;
					break;
			}
			break;
	}
	return direction;
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