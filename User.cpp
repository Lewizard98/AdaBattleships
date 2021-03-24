#include <iostream>
#include <stdlib.h>
#include <vector>
#include "headers/User.h"

User::User(){
}

void User::setBoard(Board inpBoard){
  userBoard = inpBoard;
}

void User::placeShips(std::vector<std::vector<std::string>> ships){
  std::cout<<std::endl<<"This is your current board..."<<std::endl;
  userBoard.renderBoard();
  std
}
