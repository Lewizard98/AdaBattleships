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
  std::vector<std::string> destroyed;

  std::string inp;


  while(true){

    std::cout<<"Start Turn?(Any input)";
    std::cin>>inp;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"----------------YOUR TURN----------------------";

    compPlayer.compBoard = userPlayer.takeTurn(compPlayer.compBoard);

    destroyed = compPlayer.compBoard.destroyed(ships);

    std::cout<<"\nEnemy ships destroyed:\n";
    for(int i=0;i<destroyed.size();i++){
      std::cout<<destroyed[i]<<std::endl;
    }
    if(destroyed.size() == 0){
      std::cout<<"None\n";
    } else if(destroyed.size() == ships.size()){
      std::cout<<"\nWINNER!!\n\n";
      break;
    }



    std::cout<<"End Turn?(Any input)";
    std::cin>>inp;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"----------------ENEMY TURN----------------------";

    userPlayer.userBoard = compPlayer.takeTurn(userPlayer.userBoard);

    destroyed = userPlayer.userBoard.destroyed(ships);
    std::cout<<"\nYour ships destroyed:\n";
    for(int i=0;i<destroyed.size();i++){
      std::cout<<destroyed[i]<<std::endl;
    }
    if(destroyed.size() == 0){
      std::cout<<"None\n";
    } else if(destroyed.size() == ships.size()){
      std::cout<<"\nLOSER!!\n\n";
      break;
    }
  }

  

}