#include <iostream>
#include <vector>

class IniParser{
  public:
  IniParser();
  bool CheckFileExists();
  void getConfig();
  std::string fileName;
  std::string boardConfig;
  std::vector<std::string> shipsConfig;
};