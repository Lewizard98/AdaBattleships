#import "Board.h"
#include <vector>

class Comp{
  public:
  Comp();
  void setBoard(Board);
  void placeShips(std::vector<std::vector<std::string>>);

  private:
  Board compBoard;
};