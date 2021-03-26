#import "Board.h"
#include <vector>

class User{
  public:
  User();
  void setBoard(Board);
  int placeShips(std::vector<std::vector<std::string>>);
  void autoPlaceShips(std::vector<std::vector<std::string>>);
  Board takeTurn(Board);
  Board userBoard;
};