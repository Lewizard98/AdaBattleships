#include "headers/Game.h"
#include <iostream>

Game::Game(){
  p1Board.generateBoard();

  p2Board.generateBoard();

  ships = {{"C","5"},{"B","4"},{"D","3"},{"S","3"},{"P","2"}};
}

void Game::gameMode1(){
  // Player Vs Computer
  std::cout << std::endl << "You selected player Vs Computer" << std::endl;

  std::cout << "Generating Enemy Board..."<<std::endl;
  compPlayer.setBoard(p2Board);
  compPlayer.placeShips(ships);
  std::cout << "...Complete"<<std::endl;

  std::cout<<std::endl<<"It is your turn to place your ships"<<std::endl;
  userPlayer.setBoard(p1Board);
  userPlayer.placeShips(ships);
}