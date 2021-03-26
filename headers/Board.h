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
  std::vector<std::string> toplineAlpha = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","aa","ab","ac","ad","ae","af","ag","ah","ai","aj","ak","al","am","an","ao","ap","aq","ar","as","at","au","av","aw","ax","ay","az","ba","bb","bc","bd","be","bf","bg","bh","bi","bj","bk","bl","bm","bn","bo","bp","bq","br","bs","bt","bu","bv","bw","bx","by","bz","ca","cb"}; 
};
#endif