#include "Board.h"
#include "Comp.h"
#include <vector>

class Game{
  public:
  Game();
  void gameMode1();

  private:
  Board p1Board;
  Board p2Board;
  Comp compPlayer;
  std::vector<std::vector<std::string>> ships;
};