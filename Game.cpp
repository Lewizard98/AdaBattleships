#include "headers/Game.h"
#include <iostream>

Game::Game(){
  p1Board.generateBoard();
  p1Board.renderBoard();

  p2Board.generateBoard();
  p2Board.renderBoard();
}

void Game::gameMode1(){
  // Player Vs Computer


}