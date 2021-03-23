#include <iostream>
#include <vector>
#ifndef BOARD_H
#define BOARD_H 

class Board{
  public:
  Board();
  void generateBoard();
  void renderBoard();
  std::vector<std::vector<std::string>> getBoardState();
  
  private:
  std::vector<std::vector<std::string>> boardState;
  std::vector<std::string> toplineAlpha = {"a","b","c","d","e","f","g","h","i","j"};
  

};
#endif