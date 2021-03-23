#include "headers/Menu.h"
#include <iostream>

void invalidInput(){
  std::cout << std::endl << "Please enter a valid number for a menu item" << std::endl;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Menu::Menu(){
  std::cout << "Welcome to Ada Battleships!..." << std::endl;
}

int Menu::getGameType(){
  int menuInput;

  std::cout << "Please choose an option using by inputing a number" << std::endl;

  while(true){
    std::cout << "[1]. Single Player Vs Computer" << std::endl
    << "[0]. Quit" << std::endl << "Input: ";

    if(std::cin >> menuInput){
      if(menuInput <=2){
        break;
      }
      invalidInput();
    } else {
      invalidInput();
    }
  }

  return menuInput;
}