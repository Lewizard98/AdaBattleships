#include "headers/Game.h"
#include <iostream>

Game::Game(){
  p1Board.generateBoard();
  p1Board.renderBoard();

  p2Board.generateBoard();
  p2Board.renderBoard();

  ships = {{"C","5"},{"B","4"},{"D","3"},{"S","3"},{"P","2"}};
}

void Game::gameMode1(){
  // Player Vs Computer
  compPlayer.setBoard(p2Board);
  compPlayer.placeShips(ships);
  
}