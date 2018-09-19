#include <stdio.h>
#define INF 1000
#define SIZE 100
#define TRUE 1
#define FALSE 0

enum Color
{
    RED = 0,
    YELLOW = 1,
    GREEN = 2,
    BLUE =3,
};

enum Direction
{
    UP = 1,
    LEF = 2,
    RIG = 3,
    DOWN = 4,
};

enum Pat
{
    JUMP = 0,
    ST = 1,
    TL = 2,
    TR = 3,
    TB = 4,
    CAT = 5,
    REL = 6,
};

class Dijkstra
{
  private:
    int DIST[SIZE][SIZE];
    int COST[SIZE];
    int VIA[SIZE];
    int N;
    char USED[SIZE];

    int r;
    int a,b,l;
    int start,distination;

    int route[4][30];
    int cost[4];
    int block_area[4];
    int settled_block[4];//RYGB
    int pat_num;
    int block[4];//RYGB
    int start_area;
    int to_block_route[4][30];
    int to_area_route[4][30];

    void initNode();//ノードの初期化
    void setStart(int x);//開始地点を決める
    void setDestination(int x);//終了地点を決める
    void setNodeCount(int x);//ノードの数を決める
    void setEdgeCount(int x);//エッジの数を決める
    void setNode();//どのノードがつながっているか決める
    int calCost(int start, int goal);//探索を実行する
    void createRoute(int x);//ルートを生成
    void deleteNode(int x);//ブロックを置いてるノードを消す
    void createRoute(int x, bool flag);
    void searchSameColorBlockArea(int color);
    int colorCheck(int x);
    int searchMinBlock(int u);
    int searchMinBlockArea(int u);
    int stateCheck(int x, int y);
    void setPat(int i, int now, int next);
    int checkTurn(int next_state);
    void directColor();
    int colorArea(int area);

  public:
    Dijkstra();
    int pat[4][60];
    int direct_color[4][60];
    int now_point[4][60];
    
    void setBlock(int x[4]);//ブロックの位置を決める
    void run();
    void createPat();
    void escape();
    int es_cost;
    int es_route[30];
    int es_pat[30];
    int es_direct_color[30];
    int now_point_num;
    int now_state;

    virtual ~Dijkstra();
};