#include <iostream>
#include "headers/Menu.h"
#include "headers/Game.h"

int main() {
  int gameType;
  Menu menu;

  while(true){
    gameType = menu.getGameType();

    if (gameType == 0){
      std::cout << std::endl << "Okay, Thanks for playing Ada Battleships :)";
      break;
    } else if (gameType == 1){
      Game game;
      game.gameMode1();
    }
    std::cout<<"\n\nReturning to menu...\n\n";
  }

  

  return 0;
}