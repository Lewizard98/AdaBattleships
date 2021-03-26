#include <iostream>
#include <vector>

class IniParser{
  public:
  IniParser();
  bool CheckFileExists();
  void getConfig();
  void setConfig();
  std::string BuildNewConfigBoard(std::string);
  std::string fileName;
  std::vector<std::string> boardConfig;
  std::vector<std::vector<std::string>> shipsConfig;
};