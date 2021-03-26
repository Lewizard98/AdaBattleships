#include "headers/IniParser.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <vector>

std::string removeWhitespaceParser(std::string str){
  std::string newstr;

  for(int i=0;i<str.length();i++){
    if(str[i] != ' '){
      newstr = newstr + str[i];
    }
  }
  return newstr;
}

std::vector<std::string> splitFileLine(std::string fileLine){
  std::vector<std::string> splitLine = {};
  std::string lineData1 = "";
  std::string lineData2 = "";
  int section = 1;

  for(int i=0; i <fileLine.length();i++){
    if(fileLine[i] == ':'|| fileLine[i] == ','|| fileLine[i] == 'x'){
      section++;
    } else if(section == 2){
      lineData1 += fileLine[i];
    } else if(section == 3){
      lineData2 += fileLine[i];
    }
  }

  splitLine.push_back(removeWhitespaceParser(lineData1));
  splitLine.push_back(removeWhitespaceParser(lineData2));

  return splitLine;
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
  std::vector<std::vector<std::string>> splitFile = {};
  std::ifstream fileobject;
  fileobject.open(fileName);

  while (!fileobject.eof()) {
    getline(fileobject, line);
    parsedFile.push_back(line);
  }

  fileobject.close();

  for(int i=0;i< parsedFile.size();i++){
    splitFile.push_back(splitFileLine(parsedFile[0]));
  }

  boardConfig = splitFile[0];
  parsedFile.erase(parsedFile.begin());
  
  for(int i=0;i< parsedFile.size();i++){
    shipsConfig.push_back(splitFileLine(parsedFile[i]));
  }
}