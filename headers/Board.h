#include <iostream>
#include <vector>

class Board{
  public:
  Board();
  void generateBoard();
  std::vector<std::vector<char>> boardState;

  std::vector<char> toplineAlpha = {'a','b','c','d','e','f','g','h','i','j'};
  

};