#include "headers/Game.h"
#include "headers/Board.h"
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> generateMidLine(int fullBoard){
  std::vector<std::string> line;
  for(int i=0;i<fullBoard+1;i++){
    line.push_back("-");
  }
  return line;
}

Board::Board(){
}

void Board::generateBoard(){
  int boardSize = 10;
  int fullBoard = (boardSize+1)*2;
  std::vector<std::string> line;

  
  line.push_back("  ");
  line.push_back("|");
  for(int i=0;i<boardSize;i++){
    line.push_back(Board::toplineAlpha[i]);
    line.push_back("|");
  }

  Board::boardState.push_back(line);
  line.clear();
  Board::boardState.push_back(generateMidLine(fullBoard));

  for(int i=0;i<boardSize;i++){

    line.push_back(std::to_string(i+1));
    if(i+1<10){
      line.push_back(" ");
    }
    line.push_back("|");
    for(int j=0;j<boardSize;j++){
      line.push_back(" ");
      line.push_back("|");
    }

    Board::boardState.push_back(line);
    line.clear();
    Board::boardState.push_back(generateMidLine(fullBoard));
  }
}

void Board::renderBoard(){
  for(int i=0;i<Board::boardState.size();i++){
    for(int j=0;j<Board::boardState[i].size();j++){
      std::cout<<Board::boardState[i][j];
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl<<std::endl;
}

std::vector<std::vector<std::string>> Board::getBoardState(){
  return Board::boardState;
}

