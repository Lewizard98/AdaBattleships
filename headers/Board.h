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
  std::vector<std::vector<std::string>> boardState;
  
  private:
  std::vector<std::string> toplineAlpha = {"a","b","c","d","e","f","g","h","i","j"};
  

};
#endif