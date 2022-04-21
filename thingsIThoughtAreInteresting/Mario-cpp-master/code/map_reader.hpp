#ifndef MAP_READER_HPP
#define MAP_READER_HPP
#include "block.hpp"
#include "bonus.hpp"
#include "defines.hpp"
#include "gumba.hpp"
#include "koopa.hpp"
#include <fstream>
using namespace std;
struct renderedMap {
  int height;
  int width;
  vector<Block> blocks;
  vector<Bonus> bonus;
  vector<Gumba> gumbas;
  vector<Koopa> koopas;
  Position mario;
};
class MapReader {
public:
  MapReader(string _fileAddress) : fileAddress(_fileAddress){};
  renderedMap getMap();

private:
  string fileAddress;
  int mapWidth = 0;
  int mapHeight = 0;
  Position mario;
  vector<string> map;
  vector<Block> blocks;
  vector<Bonus> bonus;
  vector<Gumba> gumbas;
  vector<Koopa> koopas;
  void readFile();
  void translateMap();
  bool isRightPipe(string line, int i);
};

#endif
