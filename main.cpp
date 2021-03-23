#include <iostream>
#include "headers/Menu.h"
#include "headers/Game.h"

int main() {
  int gameType;
  Menu menu;
  Game game;

  gameType = menu.getGameType();

  if (gameType == 0){
    std::cout << std::endl << "Okay, Thanks for playing Ada Battleships :)";
  } else if (gameType == 1){
    game.gameMode1();
  }

  return 0;
}