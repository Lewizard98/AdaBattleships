#include "headers/Game.h"
#include <iostream>

Game::Game(){
  p1Board.generateBoard();

  p2Board.generateBoard();

  ships = {{"Carrier","5"},{"Battleship","4"},{"Destroyer","3"},{"Submarine","3"},{"Patrol Boat","2"}};

  p1Points = 0;
  p2Points = 0;
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

  int winner = 0;

  while(winner == 0){

    userPlayer.takeTurn(compPlayer.compBoard);
    if(userPlayer.winner){
      std::cout<<"\nWINNER\n";
    }
    compPlayer.takeTurn(userPlayer.userBoard);
    if(compPlayer.winner){
      std::cout<<"\nLOSER\n";
    }
  }
}