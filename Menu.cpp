#include "headers/Menu.h"
#include <iostream>

//A function I use to stop repeting code for invalid input message
void invalidInput(){
  std::cout << std::endl << "Please enter a valid number for a menu item" << std::endl;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//The contrustor prints out the welcome message
Menu::Menu(){
  std::cout << "Welcome to Ada Battleships!..." << std::endl;
}

//This method displays the opening menu and returns the game type the user selected
int Menu::getGameType(){
  int menuInput;

  std::cout << "Please choose an option using by inputing a number" << std::endl;

  while(true){
    std::cout << "[1]. Single Player Vs Computer" << std::endl
    << "[2]. Single Player Vs Computer(Salvo Mode)" << std::endl
    << "[3]. Change Settings (config)" << std::endl
    << "[0]. Quit" << std::endl << "Input: ";

    //Get the user input and check if it is valid. If it is break out of the loop
    if(std::cin >> menuInput){
      if(menuInput <=3){
        break;
      }
      invalidInput();
    } else {
      invalidInput();
    }
  }

  //Return the user input for the gametype
  return menuInput;
}