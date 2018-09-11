#include "RunStatus.h"
#include "Dijkstra.h"

class Game : public RunStatus
{
  private:
  	Dijkstra *dijkstra;

  public:
    Game();
    void init();
    void setNextState();
    void startGame();
    void straight();
    void turnR();
    void turnL();
    virtual ~Game();
};