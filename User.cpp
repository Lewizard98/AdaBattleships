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
  int selectShip;

  std::cout<<std::endl<<"This is your current board..."<<std::endl;
  userBoard.renderBoard();
  std::cout<<std::endl<<std::endl<<"Please select which ship you want to place:\n";

  while(ships.size() > 0){
    for(int i=0;i<ships.size();i++){
      std::cout<< i << ". " << ships[i][0] << " Size:" << ships[i][1] <<std::endl;
    }
    if(std::cin >> selectShip){

    } else {
      std::cout<<"\nPlease enter a valid input...\n";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}
