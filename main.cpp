#include <iostream>
#include "headers/Menu.h"
#include "headers/Game.h"
#include "headers/IniParser.h"

int main() {



  //Declaring variables 
  int gameType;

  //Initilising class
  Menu menu;


  //A loot so the user can keep playing games untill they choose to quit
  while(true){

    IniParser iniParser;
    iniParser.CheckFileExists();
    iniParser.getConfig();
    //Run the menu method to get the game type
    gameType = menu.getGameType();

    //Depending on the type of game the user wants to play or to quit
    if (gameType == 0){
      std::cout << std::endl << "Okay, Thanks for playing Ada Battleships :)";
      break;
    } else if (gameType == 1){
      //I do this class here so it can be reset each loop
      Game game;
      game.gameMode1(false);
    } else if (gameType == 5){
      iniParser.setConfig();
    } else if (gameType == 2){
      Game game;
      game.gameMode1(true);
    } else if (gameType == 3){
      Game game;
      game.gameMode2(false);
    } else if (gameType == 4){
      Game game;
      game.gameMode2(true);
    }
    std::cout<<"\n\nReturning to menu...\n\n";
  }

  return 0;
}