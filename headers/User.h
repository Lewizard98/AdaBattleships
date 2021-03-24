#import "Board.h"
#include <vector>

class User{
  public:
  User();
  void setBoard(Board);
  void placeShips(std::vector<std::vector<std::string>>);

  private:
  Board userBoard;
};