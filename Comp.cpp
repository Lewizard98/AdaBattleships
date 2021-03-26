#include <iostream>
#include <stdlib.h>
#include <vector>
#include "headers/Comp.h"

//Funcion to check if the area is clear for placing a ship, taking the start position, the length of the ship, and what direction it is facing. Returns false if the ship will not fit and true if it will
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

//Empty Constructor
Comp::Comp(){
}

//Set the new board state
void Comp::setBoard(Board inpBoard){
  compBoard = inpBoard;
}

//Randomly placing the ships
void Comp::placeShips(std::vector<std::vector<std::string>> ships){
  //For the randomization
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
}

void printAttack(int xrand, int yrand, Board userBoard){

  for(int i = 1;i<userBoard.boardState[0].size();i++){
    if(i == xrand){
      std::cout<<userBoard.boardState[0][i]<<yrand<<std::endl;
    }
  }
}

//The computer takes it's turn
Board Comp::takeTurn(Board userBoard){

  int xrand;
  int yrand;

  std::cout << "\nIt is your opponents turn...\n\n";
  std::cout <<"\n\n Your opponent has fired a missle at...\n";

  //Loop through each time the computer chooses a bad place to attack. This ganatees it will always shoot somewhere it has not attacked before
  while(true){
  
    xrand = (rand() % userBoard.boardState[0].size());
    yrand = (rand() % userBoard.boardState[0].size());

    if (xrand == 0){xrand++;}
    if (yrand == 0){yrand++;}

    if(userBoard.boardState[yrand][xrand] == " "){
      userBoard.boardState[yrand][xrand] = "O";
      printAttack(xrand,yrand,userBoard);
      std::cout<<"They Missed!\n";
      break;
    } else if(userBoard.boardState[yrand][xrand] == "O"||userBoard.boardState[yrand][xrand] == "X"){

    } else{
      userBoard.boardState[yrand][xrand] = "X";
      printAttack(xrand,yrand,userBoard);
      std::cout<<"They Hit!\n";
      break;
    }
  }

  //Display the board after the attack
  std::cout<<"Your Board...\n";
  userBoard.renderBoard();

  return userBoard;
} 

