#include "headers/Game.h"
#include "headers/Board.h"
#include <iostream>
#include <vector>

Board::Board(){
}

void Board::generateBoard(){
  int boardSize = 10;

  

  std::vector<char> topLine;
  topLine.push_back(' ');
  topLine.push_back('|');
  for(int i=0;i<boardSize;i++){
    topLine.push_back(Board::toplineAlpha[i]);
    topLine.push_back('|');
  }

  std::vector<char> secondLine;
  for(int i=0;i<topLine.size();i++){
    topLine.push_back('-');
  }
  

  Board::boardState.push_back(topLine);
  Board::boardState.push_back(secondLine);

  for(int i=0;i<Board::boardState.size();i++){
    for(int j=0;j<Board::boardState[i].size();j++){
      std::cout<<Board::boardState[i][j];
    }
    std::cout<<std::endl;
  }

}

// std::vector<std::vector<char>>