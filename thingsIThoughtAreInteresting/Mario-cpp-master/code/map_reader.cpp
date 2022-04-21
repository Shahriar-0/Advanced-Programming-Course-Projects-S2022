#include "map_reader.hpp"
using namespace std;

void MapReader::readFile() {
  ifstream mapFile;
  mapFile.open(fileAddress);
  string temp;
  while (getline(mapFile, temp)) {
    mapWidth = temp.length();
    mapHeight++;
    map.push_back(temp);
  }
  mapHeight *= BLOCK_SIZE;
  mapWidth *= BLOCK_SIZE;
}

renderedMap MapReader::getMap() {
  readFile();
  translateMap();
  renderedMap result = {mapHeight, mapWidth, blocks, bonus,
                        gumbas,    koopas,   mario};
  return result;
}
void MapReader::translateMap() {
  int y = 0, x = 0, bonusNumber = 0;
  string line;
  for (int j = 0; j < map.size(); j++) {
    line = map[j];
    for (int i = 0; i < mapWidth / BLOCK_SIZE; i++) {
      x = i * BLOCK_SIZE;
      Position pos{x, y};
      if (line[i] == '.')
        continue;
      else if (line[i] == '#')
        blocks.push_back(Block(pos, CLAY));
      else if (line[i] == '@')
        blocks.push_back(Block(pos, BLOCK));
      else if (line[i] == 'b')
        blocks.push_back(Block(pos, BRICK, true));
      else if (line[i] == '|') {
        if (isRightPipe(line, i)) {
          blocks.push_back(Block(pos, j > 0 && map[j - 1][i] == '|'
                                          ? PIPE_RIGHT
                                          : PIPE_HEAD_RIGHT));
        } else
          blocks.push_back(Block(
              pos, j > 0 && map[j - 1][i] == '|' ? PIPE_LEFT : PIPE_HEAD_LEFT));
      } else if (line[i] == 'f')
        blocks.push_back(
            Block(pos, j > 0 && map[j - 1][i] == 'f' ? FLAG_BODY : FLAG_HEAD));
      else if (line[i] == '?' || line[i] == 'm' || line[i] == 'h') {
        bonus.push_back(Bonus(pos, line[i], bonusNumber));
        blocks.push_back(Block(pos, QUESTION_1, bonusNumber));
        bonusNumber++;
      } else if (line[i] == 'M') {
        mario = Position{x, y};
      } else if (line[i] == 'l') {
        gumbas.push_back(Gumba(pos));
      } else if (line[i] == 'k') {
        koopas.push_back(Koopa(pos));
      }
    }
    y += BLOCK_SIZE;
  }
}
bool MapReader::isRightPipe(string line, int i) {
  for (int j = i - 1; j > 0; j--) {
    if (line[j] != '|')
      return !((i - j) % 2);
  }
  return i % 2;
}
