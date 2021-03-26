#import "Board.h"
#include <vector>

class Comp{
  public:
  Comp();
  void setBoard(Board);
  void placeShips(std::vector<std::vector<std::string>>);
  Board takeTurn(Board);
  Board compBoard;
};