#include "RunStatus.h"
#include "Dijkstra.h"

enum TraceLine{
  Line_R = 0,
  Line_L = 1,
};

class Game : public RunStatus
{
  private:
  	Dijkstra *dijkstra;
    void straight(int color);
    void turnR();
    void turnL();
    void turnBack();
    void jump();
    void release(int direction);
    void blockcatch();

    int edge_line;

  public:
    Game();
    void init();
    void setNextState();
    void startGame();
    virtual ~Game();
};