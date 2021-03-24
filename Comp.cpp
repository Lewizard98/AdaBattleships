#include <iostream>
#include <stdlib.h>
#include <vector>
#include "headers/Comp.h"

bool isClear(int shipSize,int ypos,int xpos, std::vector<std::vector<std::string>> board,std::string direction){
  if(direction == "x-"){
    for(int i=0;i<shipSize;i++){
      if(board[ypos][xpos+i] != " "){
        return false;
      }
    }
  }else if(direction == "-x"){
    for(int i=0;i<shipSize;i++){
      if(board[ypos][xpos-i] != " "){
        return false;
      }
    }
  }else if(direction == "y-"){
    for(int i=0;i<shipSize;i++){
      if(board[ypos+i][xpos] != " "){
        return false;
      }
    }
  } else if(direction == "-y"){
    for(int i=0;i<shipSize;i++){
      if(board[ypos-i][xpos] != " "){
        return false;
      }
    }
  }

  return true;
}

Comp::Comp(){
}

void Comp::setBoard(Board inpBoard){
  compBoard = inpBoard;
}

void Comp::placeShips(std::vector<std::vector<std::string>> ships){
  srand((unsigned int)time(NULL));
  int xrand;
  int yrand;
  int xOry;

  for(int i=0;i<ships.size();i++){
    xrand = rand() % compBoard.boardState[0].size();
    yrand = rand() % compBoard.boardState[0].size();

    bool placed = false;

    while(!placed){
      xOry = rand() % 2;
    //compBoard.boardState[yrand][xrand] = ships[i][0];

      if(xOry != 1){
        if(xrand + stoi(ships[i][1]) <= 10 && isClear(stoi(ships[i][1]),yrand,xrand,    compBoard.boardState,"x-")){
          for(int j=0;j<stoi(ships[i][1]);j++){
            compBoard.boardState[yrand][xrand+j] = ships[i][0].substr(0,1);
          }
          placed = true;
        } else if(isClear(stoi(ships[i][1]),yrand,xrand,compBoard.boardState,"-x")) {
          for(int j=stoi(ships[i][1]);j>0;j--){
            compBoard.boardState[yrand][xrand-j] = ships[i][0].substr(0,1);
          }
          placed = true;
        }
      } else{
        if(yrand + stoi(ships[i][1]) <= 10 && isClear(stoi(ships[i][1]),yrand,xrand,        compBoard.boardState,"y-")){
          for(int j=0;j<stoi(ships[i][1]);j++){
            compBoard.boardState[yrand+j][xrand] = ships[i][0].substr(0,1);
          }
          placed = true;
        } else if(isClear(stoi(ships[i][1]),yrand,xrand,compBoard.boardState,"-y")){
          for(int j=stoi(ships[i][1]);j>0;j--){
            compBoard.boardState[yrand-j][xrand] = ships[i][0].substr(0,1);
          }
          placed = true;
        }
      }
      xrand = rand() % compBoard.boardState[0].size();
      yrand = rand() % compBoard.boardState[0].size();
    }
  }
  compBoard.renderBoard();
}
