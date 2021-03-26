#include "headers/IniParser.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> splitFileLine(std::string fileLine){
  std::vector<std::vector<std::string>> splitLine = {};

  for(int i=0; i <fileLine.length();i++){
    
  }
}

IniParser::IniParser(){
  fileName = "adaship_config.ini";
}

bool IniParser::CheckFileExists(){
  struct stat buf;
  if (stat(IniParser::fileName.c_str(), &buf) == 0) {
    return true;
  }
  return false;
}

void IniParser::getConfig(){
  std::string line;
  std::vector<std::string> parsedFile;
  std::ifstream fileobject;
  fileobject.open(fileName);

  while (!fileobject.eof()) {
    getline(fileobject, line);
    parsedFile.push_back(line);
  }

  fileobject.close();

  boardConfig = parsedFile[0];
  parsedFile.erase(parsedFile.begin());
  shipsConfig = parsedFile;
}