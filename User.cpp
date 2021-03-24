#include <iostream>
#include <stdlib.h>
#include <vector>
#include "headers/User.h"

bool isClearUser(int shipSize,int ypos,int xpos, std::vector<std::vector<std::string>> board,std::string direction){
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

  while(ships.size() > 0){
    std::cout<<std::endl<<std::endl<<"Please select which ship you want to place:\n";
    bool shipPlaced = false;
    for(int i=0;i<ships.size();i++){
      std::cout<< i << ". " << ships[i][0] << " Size:" << ships[i][1] <<std::endl;
    }

    while(shipPlaced == false){
      if(std::cin >> selectShip && selectShip < ships.size()){
        std::vector<std::string> selectedShip = ships[selectShip]; 

        std::cout << "Please choose a place for the " << selectedShip[0] << std::endl;
        std::cout << "Example: a1\n";
      
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> startPos;

        std::string startPosx = startPos.substr(0,1);
        std::string strPosx = removeWhitespace(startPosx);
        std::string startPosy = startPos.substr(1);
        std::string strPosy = removeWhitespace(startPosy);
        std::vector<std::string> topLine = userBoard.toplineAlpha;
        int intxpos;
      
        for(int k=0;k<topLine.size();k++){
          if(topLine[k] == strPosx){
            intxpos = k+1;
          }
        }

        std::cout<<"What direction shoult it face:\n0.Up\n1.Down\n2.Left\n3.Right\nInput:";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(std::cin>>direction){

          if(direction == 0){
            if(isClearUser(stoi(removeWhitespace(selectedShip[1])), stoi(startPosy), intxpos, userBoard.boardState, "-y")){
              for(int j=stoi(selectedShip[1]);j>0;j--){
                userBoard.boardState[stoi(strPosy)-j+1][intxpos] = selectedShip[0].substr(0,1);
              }
              shipPlaced = true;
            }
          } else if(direction == 1){
            if(isClearUser(stoi(removeWhitespace(selectedShip[1])), stoi(startPosy), intxpos, userBoard.boardState, "y-")){
              for(int j=0;j<stoi(selectedShip[1]);j++){
                userBoard.boardState[stoi(strPosy)+j][intxpos] = selectedShip[0].substr(0,1);
            }
            shipPlaced = true;
            }
          } else if(direction == 2){
            if(isClearUser(stoi(removeWhitespace(selectedShip[1])), stoi(startPosy), intxpos, userBoard.boardState, "-x")){
              for(int j=stoi(selectedShip[1]);j>0;j--){
                userBoard.boardState[stoi(strPosy)][intxpos-j+1] = selectedShip[0].substr(0,1);
              }
              shipPlaced = true;
            }
          } else if(direction == 3){
            if(isClearUser(stoi(removeWhitespace(selectedShip[1])), stoi(startPosy), intxpos, userBoard.boardState, "x-")){
              for(int j=0;j<stoi(selectedShip[1]);j++){
                userBoard.boardState[stoi(strPosy)][intxpos+j] = selectedShip[0].substr(0,1);
              }
              shipPlaced = true;
            }
          } else {
            std::cout<<"\nPlease enter a valid input...\n";
          }
        } else{
          std::cout<<"\nPlease enter a valid input...\n";
        }

      

      } else {
        std::cout<<"\nPlease enter a valid input...\n";
        break;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      userBoard.renderBoard();
      if(shipPlaced){
        ships.erase(ships.begin()+selectShip);
      }
    }
  }
}
