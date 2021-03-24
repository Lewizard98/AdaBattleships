#include "headers/Game.h"
#include "headers/Board.h"
#include <iostream>
#include <vector>
#include <string>

void printLine(int fullBoard){
  for(int i=0;i<fullBoard+1;i++){
     std::cout<<"-";
  }
}

Board::Board(){
}

void Board::generateBoard(){
  int boardSize = 10;
  int fullBoard = (boardSize+1)*2;
  std::vector<std::string> line;

  
  line.push_back("  ");
  for(int i=0;i<boardSize;i++){
    line.push_back(Board::toplineAlpha[i]);
  }

  Board::boardState.push_back(line);
  line.clear();

  for(int i=0;i<boardSize;i++){

    
    if(i+1<10){

      line.push_back(std::to_string(i+1) +" ");
    } else {
      line.push_back(std::to_string(i+1));
    }
    for(int j=0;j<boardSize;j++){
      line.push_back(" ");
    }

    Board::boardState.push_back(line);
    line.clear();
  }
}

void Board::renderBoard(){
  int boardSize = 10;
  int fullBoard = (boardSize+1)*2;
  for(int i=0;i<Board::boardState.size();i++){
    for(int j=0;j<Board::boardState[i].size();j++){
      std::cout<<Board::boardState[i][j];
      std::cout<<"|";
    }
    std::cout<<std::endl;
    printLine(fullBoard);
    std::cout<<std::endl;
    
  }
  std::cout<<std::endl<<std::endl;
}

void Board::renderOtherBoard(){
int boardSize = 10;
  int fullBoard = (boardSize+1)*2;

  for(int i=0;i<Board::boardState.size();i++){
    for(int k=0;k<Board::boardState[i].size();k++){
      if(Board::boardState[i][k] == "C"||Board::boardState[i][k] == "B"||Board::boardState[i][k] == "D"||Board::boardState[i][k] == "S"||Board::boardState[i][k] == "P"){
        std::cout<<" ";
        std::cout<<"|";
      }else{
        std::cout<<Board::boardState[i][k];
        std::cout<<"|";
      }
    }
    std::cout<<std::endl;
    printLine(fullBoard);
    std::cout<<std::endl;
    
  }
  std::cout<<std::endl<<std::endl;
}

std::vector<std::vector<std::string>> Board::getBoardState(){
  return Board::boardState;
}

