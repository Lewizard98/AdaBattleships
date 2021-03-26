#include "headers/Game.h"
#include <iostream>
#include "headers/IniParser.h"

//Constructor
Game::Game(){

  IniParser iniParser;
  iniParser.CheckFileExists();
  iniParser.getConfig();

  //Generate the two boards for each player
  p1Board.generateBoard(iniParser.boardConfig);
  p2Board.generateBoard(iniParser.boardConfig);

  //The list of ships and their sizes
  ships = iniParser.shipsConfig;
}

  // Player Vs Computer game mode
void Game::gameMode1(){
    //Declare Variables
    std::vector<std::string> destroyed;
    std::string inp;

  std::cout << std::endl << "You selected player Vs Computer" << std::endl;

    //First the enemy player is given a board and will place its ships
  std::cout << "Generating Enemy Board..."<<std::endl;
  compPlayer.setBoard(p2Board);
  compPlayer.placeShips(ships);
  std::cout << "...Complete"<<std::endl;

  //After that the Player will place their ships
  std::cout<<std::endl<<"It is your turn to place your ships"<<std::endl;
  userPlayer.setBoard(p1Board);
  userPlayer.placeShips(ships);

  //Play a turn, each turn is made up of the player turn and the computer turn
  while(true){

    //Before a turn begins the user is asked to enter a confirmation
    std::cout<<"Start Turn?(Any input)";
    std::cin>>inp;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"----------------YOUR TURN----------------------";

    //The user will take a turn, using the method, whic returns a new board state which is assigned to the enemy as their board
    compPlayer.compBoard = userPlayer.takeTurn(compPlayer.compBoard);
    destroyed = compPlayer.compBoard.destroyed(ships);

    //Display list of enemy ships destroyed
    std::cout<<"\nEnemy ships destroyed:\n";
    for(int i=0;i<destroyed.size();i++){
      std::cout<<destroyed[i]<<std::endl;
    }


    if(destroyed.size() == 0){
      std::cout<<"None\n";
    } else if(destroyed.size() == ships.size()){
      //If all enemy ships are destroyed then you are the winner and the turn loop ends
      std::cout<<"\nWINNER!!\n\n";
      break;
    }


    //Give confirmation before ending the turn
    std::cout<<"End Turn?(Any input)";
    std::cin>>inp;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"----------------ENEMY TURN----------------------";

    //This is the computer taking a turn and assigning the new board state to the player
    userPlayer.userBoard = compPlayer.takeTurn(userPlayer.userBoard);

    destroyed = userPlayer.userBoard.destroyed(ships);
    std::cout<<"\nYour ships destroyed:\n";
    for(int i=0;i<destroyed.size();i++){
      std::cout<<destroyed[i]<<std::endl;
    }

    if(destroyed.size() == 0){
      std::cout<<"None\n";
    } else if(destroyed.size() == ships.size()){
      //If all of your ships are destroyed you are the loser
      std::cout<<"\nLOSER!!\n\n";
      break;
    }
  }
}