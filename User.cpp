#include <iostream>
#include <stdlib.h>
#include <vector>
#include "headers/User.h"

int User::startGameMenu(std::vector<std::vector<std::string>> ships){
  while(true){
        std::cout<<"\n\nAre you happy with this ship placement?\n1.Start Game\n2.Reset Ships\n3.Quit\nInput: ";

        int continueInp;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(std::cin>> continueInp){
          if(continueInp ==1){
            return 1;
          } else if(continueInp ==2){
            return 2;
          } else if(continueInp ==3){
            return 3;
          } else{
            std::cout<<"\nPlease enter a valid input...";
          }

        } else {
          std::cout<<"\nPlease enter a valid input...";
        }
        }
        return 0;
}

//The function for checking if the location is clear for the ship to be placed, takes the start position, the length of the ship and the current state of the board
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

//This function removes whitespace from an input string - This is part of a bug fix
std::string removeWhitespace(std::string str){
  std::string newstr;

  for(int i=0;i<str.length();i++){
    if(str[i] != ' '){
      newstr = newstr + str[i];
    }
  }
  return newstr;
}

//This function checks if a position is a valid x position on the board
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

//This function checks if a position is a valid y position on the board
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

//Empty Constructor
User::User(){
}

//Giving the board a new state
void User::setBoard(Board inpBoard){
  userBoard = inpBoard;
}

//Function to place the ships
int User::placeShips(std::vector<std::vector<std::string>> ships){
  int selectShip;
  int direction;
  std::string startPos;
  int autoPlaceQ;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout<< "\nWould you like to auto-place ships?\n0-9. Auto-place\nAny other Key. I want to place them\nInput: ";
  if(std::cin >> autoPlaceQ){
    autoPlaceShips(ships);
    userBoard.renderBoard();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return startGameMenu(ships);
  }

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout<<std::endl<<"This is your current board..."<<std::endl;
  userBoard.renderBoard();

  while(ships.size() > 0){
    
    bool shipPlaced = false;

    while(shipPlaced == false){

      std::cout<<std::endl<<std::endl<<"Please select which ship you want to place:\n";
    
    for(int i=1;i<=ships.size();i++){
      std::cout<< i << ". " << ships[i-1][0] << " Size:" << ships[i-1][1] <<std::endl;
    }
    std::cout<< "0. Auto-place ships\n";

      std::string startPosx;
      std::string strPosx;
      std::string startPosy;
      std::string strPosy;
      std::vector<std::string> topLine;
      int intxpos;
      if(!(std::cin >> selectShip)){
        std::cout<<"\nPlease enter a valid input...\n";
      }else if(selectShip == 0){
        autoPlaceShips(ships);
        userBoard.renderBoard();
        return startGameMenu(ships);
      }else if(selectShip <= ships.size()){
        std::vector<std::string> selectedShip = ships[selectShip-1]; 
        
        do{
          std::cout << "Please choose a place for the " << selectedShip[0] << std::endl;
          std::cout << "Example: a1\nInput: ";
      
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          std::cin >> startPos;

          startPosx = startPos.substr(0,1);
          strPosx = removeWhitespace(startPosx);
          startPosy = startPos.substr(1);
          strPosy = removeWhitespace(startPosy);
          topLine = userBoard.toplineAlpha;

          for(int k=0;k<topLine.size();k++){
            if(topLine[k] == strPosx){
              intxpos = k+1;
            }
          }

          try{
            if(stoi(startPosy) <= 10 && intxpos != 0){
              break;
          }
          } catch(std::invalid_argument& e){}

          std::cout<< "\nInvalid Input, please enter a location on the board...\n";
        }while(true);

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

            } else{
              std::cout<<std::endl<<"No space here, try a different ship or position/direction...\n\n";
            }
          } else if(direction == 1){
            if(isClearUser(stoi(removeWhitespace(selectedShip[1])), stoi(startPosy), intxpos, userBoard.boardState, "y-")){
              for(int j=0;j<stoi(selectedShip[1]);j++){
                userBoard.boardState[stoi(strPosy)+j][intxpos] = selectedShip[0].substr(0,1);
            }
            shipPlaced = true;
            }else{
              std::cout<<std::endl<<"No space here, try a different ship or position/direction...\n\n";
            }
          } else if(direction == 2){
            if(isClearUser(stoi(removeWhitespace(selectedShip[1])), stoi(startPosy), intxpos, userBoard.boardState, "-x")){
              for(int j=stoi(selectedShip[1]);j>0;j--){
                userBoard.boardState[stoi(strPosy)][intxpos-j+1] = selectedShip[0].substr(0,1);
              }
              shipPlaced = true;
            }else{
              std::cout<<std::endl<<"No space here, try a different ship or position/direction...\n\n";
            }
          } else if(direction == 3){
            if(isClearUser(stoi(removeWhitespace(selectedShip[1])), stoi(startPosy), intxpos, userBoard.boardState, "x-")){
              for(int j=0;j<stoi(selectedShip[1]);j++){
                userBoard.boardState[stoi(strPosy)][intxpos+j] = selectedShip[0].substr(0,1);
              }
              shipPlaced = true;
            }else{
              std::cout<<std::endl<<"No space here, try a different ship or position/direction...\n\n";
            }
          } else {
            std::cout<<"\nPlease enter a valid input...\n";
          }
        } else{
          std::cout<<"\nPlease enter a valid input...\n";
        }

      

      }else {
        std::cout<<"\nPlease enter a valid input...\n";
        break;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      userBoard.renderBoard();
      if(shipPlaced){
        ships.erase(ships.begin()+(selectShip-1));
      }
    }
  }

  return startGameMenu(ships);
}

//Method to auto place the ships, this is similar to the method to auto place the ships on the Comp class
void User::autoPlaceShips(std::vector<std::vector<std::string>> ships){
  srand((unsigned int)time(NULL));
  int xrand;
  int yrand;
  int xOry;

  for(int i=0;i<ships.size();i++){
    xrand = rand() % userBoard.boardState[0].size();
    yrand = rand() % userBoard.boardState[0].size();

    bool placed = false;

    while(!placed){
      xOry = rand() % 2;

      if(xOry != 1){
        if(xrand + stoi(ships[i][1]) <= 10 && isClearUser(stoi(ships[i][1]),yrand,xrand,    userBoard.boardState,"x-")){
          for(int j=0;j<stoi(ships[i][1]);j++){
            userBoard.boardState[yrand][xrand+j] = ships[i][0].substr(0,1);
          }
          placed = true;
        } else if(isClearUser(stoi(ships[i][1]),yrand,xrand,userBoard.boardState,"-x")) {
          for(int j=stoi(ships[i][1]);j>0;j--){
            userBoard.boardState[yrand][xrand-j] = ships[i][0].substr(0,1);
          }
          placed = true;
        }
      } else{
        if(yrand + stoi(ships[i][1]) <= 10 && isClearUser(stoi(ships[i][1]),yrand,xrand,        userBoard.boardState,"y-")){
          for(int j=0;j<stoi(ships[i][1]);j++){
            userBoard.boardState[yrand+j][xrand] = ships[i][0].substr(0,1);
          }
          placed = true;
        } else if(isClearUser(stoi(ships[i][1]),yrand,xrand,userBoard.boardState,"-y")){
          for(int j=stoi(ships[i][1]);j>0;j--){
            userBoard.boardState[yrand-j][xrand] = ships[i][0].substr(0,1);
          }
          placed = true;
        }
      }
      xrand = rand() % userBoard.boardState[0].size();
      yrand = rand() % userBoard.boardState[0].size();
    }
  }
}

//User take the turn Method
Board User::takeTurn(Board compBoard){
  std::cout << "\nIt is your turn...\nThe opponents board looks like this:\n\n";
  compBoard.renderOtherBoard();

  std::string attack;
  std::string attackx;
  std::string strAttackx;
  std::string attacky;
  std::string strAttacky;
  int intxpos = 0;

  do{
  std::cout <<"\n\n Please enter a location to fire a missle at...\nInput: ";
  std::cin >> attack;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  attackx = attack.substr(0,1);
  strAttackx = removeWhitespace(attackx);
  attacky = attack.substr(1);
  strAttacky = removeWhitespace(attacky);
  std::vector<std::string> topLine = userBoard.toplineAlpha;
  
  for(int k=0;k<topLine.size();k++){
          if(topLine[k] == strAttackx){
            intxpos = k+1;
          }
        }
        try{
          if(stoi(strAttacky) <= 10 && intxpos != 0){
            break;
          }
        } catch(std::invalid_argument& e){}
        std::cout<<"\nInvalid input...\n";
  }while(true);

    std::string target = compBoard.boardState[stoi(strAttacky)][intxpos];
    if( target != " "){
      if(target == "X" || target == "O"){
        std::cout<<"\nYou have already attacked that location... so this is a MISS!!\n\n";
      } else {
        std::cout <<"\nHIT!!\n\n";
        compBoard.boardState[stoi(strAttacky)][intxpos] = "X";
        for(int i=0;i<compBoard.boardState.size();i++){
          for(int j=0;j<compBoard.boardState[i].size();j++){
            
          }
        }
      }
  } else {
    compBoard.boardState[stoi(strAttacky)][intxpos] = "O";
    std::cout <<"\nMISS!!\n\n";
  }

  std::cout<<"Enemy Boared...\n";
  compBoard.renderOtherBoard();

  return compBoard;
  
}
