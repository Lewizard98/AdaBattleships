#include <iostream>
#include <stdlib.h>
#include "headers/Comp.h"

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

    while(compBoard.boardState[yrand][xrand] != " "){
      xrand = rand() % compBoard.boardState[0].size();
      yrand = rand() % compBoard.boardState[0].size();
    }

    xOry = rand() % 1;

  compBoard.boardState[yrand][xrand] = ships[i][0];
  }

  

  compBoard.renderBoard();

}
