#include "Board.h"
#include "Comp.h"
#include "User.h"
#include <vector>

class Game{
  public:
  Game();
  void gameMode1();

  private:
  Board p1Board;
  Board p2Board;
  Comp compPlayer;
  User userPlayer;
  std::vector<std::vector<std::string>> ships;
  int p1Points;
  int p2Points;
};