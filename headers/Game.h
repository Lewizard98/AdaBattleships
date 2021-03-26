#include "Board.h"
#include "Comp.h"
#include "User.h"
#include <vector>

class Game{
  public:
  Game();
  int gameMode1(bool);
  int gameMode2(bool);

  private:
  Board p1Board;
  Board p2Board;
  Comp compPlayer;
  User userPlayer;
  User userPlayer2;
  std::vector<std::vector<std::string>> ships;
};