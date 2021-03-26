#include <iostream>
#include <vector>

class IniParser{
  public:
  IniParser();
  bool CheckFileExists();
  void getConfig();
  std::string fileName;
  std::vector<std::string> boardConfig;
  std::vector<std::vector<std::string>> shipsConfig;
};