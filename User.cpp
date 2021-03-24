#include <iostream>
#include <stdlib.h>
#include <vector>
#include "headers/User.h"

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

std::string removeWhitespace(std::string str){
  std::string newstr;

  for(int i=0;i<str.length();i++){
    if(str[i] != ' '){
      newstr = newstr + str[i];
    }
  }
  return newstr;
}

bool validXPosition(std::string startPos, Board userBoard){
  std::string startPosL = startPos.substr(0,1);
  std::string strPos = removeWhitespace(userBoard.boardState[1][0]);
  bool xmatch = false;

  for(int i=0;i < userBoard.boardState[0].size();i++){
    if(strPos.compare(startPosL) == 0){
      xmatch = true;
    }
  }
  return xmatch;
}

bool validYPosition(std::string startPos, Board userBoard){
  std::string startPosN = startPos.substr(1);
  std::string strPos = removeWhitespace(userBoard.boardState[1][0]);
  bool ymatch = false;

  for(int i=0;i < userBoard.boardState[0].size();i++){
    if(strPos.compare(startPosN) == 0){
      ymatch = true;
    }
  }
  return ymatch;
}

User::User(){
}

void User::setBoard(Board inpBoard){
  userBoard = inpBoard;
}

void User::placeShips(std::vector<std::vector<std::string>> ships){
  int selectShip;
  int direction;
  std::string startPos;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout<<std::endl<<"This is your current board..."<<std::endl;
  userBoard.renderBoard();
  std::cout<<std::endl<<std::endl<<"Please select which ship you want to place:\n";

  while(ships.size() > 0){
    bool shipPlaced = false;
    for(int i=0;i<ships.size();i++){
      std::cout<< i << ". " << ships[i][0] << " Size:" << ships[i][1] <<std::endl;
    }
    if(std::cin >> selectShip){
      std::vector<std::string> selectedShip = ships[selectShip]; 

      std::cout << "Please choose a place for the " << selectedShip[0] << std::endl;
      std::cout << "Example: a1\n";
      
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cin >> startPos;

      std::string startPosx = startPos.substr(0,1);
      std::string strPosx = startPosx;
      std::string startPosy = startPos.substr(1);
      std::string strPosy = startPosy;

      std::cout<<"What direction shoult it face:\n0.Up\n1.Down\n2.Left\n3.Right";

      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if(std::cin>>direction){
        std::vector<std::string> directions = {"-y","y-","-x","-y"};
        std::string dirStr = directions[direction];

        if(direction == 0){
          if(isClear(stoi(selectedShip[1]), stoi(startPosy), stoi(startPosx), userBoard.boardState, "-y")){
            
          }
        } else if(direction == 1){
          if(isClear(stoi(selectedShip[1]), stoi(startPosy), stoi(startPosx), userBoard.boardState, "y-")){
            if(isClear(stoi(selectedShip[1]), stoi(startPosy), stoi(startPosx), userBoard.boardState, "x-")){
              for(int j=0;j<stoi(selectedShip[1]);j++){
                userBoard.boardState[stoi(strPosy)][stoi(strPosx)+j] = selectedShip[0].substr(0,1);
              }
            }
          }
        } else if(direction == 2){
          if(isClear(stoi(selectedShip[1]), stoi(startPosy), stoi(startPosx), userBoard.boardState, "-x")){
            if(isClear(stoi(selectedShip[1]), stoi(startPosy), stoi(startPosx), userBoard.boardState, "x-")){
              for(int j=stoi(selectedShip[1]);j>0;j--){
                userBoard.boardState[stoi(strPosy)][stoi(strPosx)-j] = selectedShip[0].substr(0,1);
              }
          }
          }
        } else if(direction == 3){
          if(isClear(stoi(selectedShip[1]), stoi(startPosy), stoi(startPosx), userBoard.boardState, "x-")){
            for(int j=0;j<stoi(selectedShip[1]);j++){
            userBoard.boardState[stoi(strPosy)][stoi(strPosx)+j] = selectedShip[0].substr(0,1);
            }
          }
        }
      } else{
        std::cout<<"\nPlease enter a valid input...\n";
      }

      

    } else {
      std::cout<<"\nPlease enter a valid input...\n";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}
