#include <iostream>
#include <vector>
#ifndef BOARD_H
#define BOARD_H 

class Board{
  public:
  Board();
  void generateBoard(std::vector<std::string>);
  void renderBoard();
  void renderOtherBoard();
  std::vector<std::string> destroyed(std::vector<std::vector<std::string>>);
  std::vector<std::vector<std::string>> boardState;
  std::vector<std::string> toplineAlpha = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","aa","ab","ac","ad","ae","af","ag","ah","ai","aj","ak","al","am","an","ao","ap","aq","ar","as","at","au","av","aw","ax","ay","az","b","b","b","b","b","b","b","b","b","b","b","b","b","b","","","","","","","","","","","","ca","cb"}; 
};
#endif