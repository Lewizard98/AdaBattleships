#include "Menu.h"
#include <iostream>

void invalidInput(){
  std::cout << std::endl << "Please enter a valid number for a menu item" << std::endl;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Menu::Menu(){
  int menuInput;


  std::cout << "Welcome to Ada Battleships!..." << std::endl 
  << "Please choose an option using by inputing a number" << std::endl;

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

  if(menuInput == 0){
    std::cout << std::endl << "Thanks for playing :)" << std::endl;
  } else if(menuInput == 1){
    std::cout << std::endl << "Great! Let's play!" << std::endl;
  }

  
}