#include "view.hpp"
using namespace std;
View::View(string fileAddress) {
  cameraX = 0;
  readMapfile(fileAddress);
  createWindow();
  drawMap();
}

void View::createWindow() { window = new Window(WIDTH, mapHeight, TITLE_NAME); }
int View::getSurface(int x, int y) {
  int result = 0;
  x = 745;
  // cout << " - - -- - - Height" << mapHeight << " - - - - - - " << endl;
  // cout << result << "/";
  for (auto c : clays)
    if (c.getY() > mario.getY() && c.getX() <= x &&
        c.getX() + BLOCK_SIZE >= x) {
      result = max(result, c.getY());
      // cout << "Clay" << c.getX() << "/" << c.getY() << endl;
    }
  // cout << result << "/";

  for (auto p : pipes)
    if (p.getY() > mario.getY() && p.getX() <= x &&
        p.getX() + BLOCK_SIZE >= x) {
      result = max(result, p.getY());
      // cout << "pipe";
    }
  for (auto b : bricks)
    if (b.getY() > mario.getY() && b.getX() <= x &&
        b.getX() + BLOCK_SIZE >= x) {
      result = max(result, b.getY());
      // cout << "brick";
    }
  // cout << result << "/";

  for (auto b : blocks)
    if (b.getY() > mario.getY() && b.getX() <= x &&
        b.getX() + BLOCK_SIZE >= x) {
      result = max(result, b.getY());
      // cout << "block";
    }
  // cout << result << "/";

  for (auto q : questions)
    if (q.getY() > mario.getY() && q.getX() <= x &&
        q.getX() + BLOCK_SIZE >= x) {
      result = max(result, q.getY());
      // cout << "que";
    }
  // cout << result << "/" << endl;

  // cout << result << endl;
  return result;
}
void View::drawObjects() {

  int y = 0, x = 0;
  string line;
  for (int j = 0; j < map.size(); j++) {
    line = map[j];
    for (int i = 0; i < mapWidth; i++) {
      x = i * BLOCK_SIZE - cameraX;

      if (line[i] == '.')
        continue;
      else if (line[i] == '#') {
        Clay clay(x, y);
        clays.push_back(clay);
        clay.draw(window);
      } else if (line[i] == '@') {
        Block block(x, y);
        blocks.push_back(block);
        block.draw(window);
      } else if (line[i] == 'b') {
        Brick brick(x, y);
        bricks.push_back(brick);
        brick.draw(window);
      } else if (line[i] == '|') {
        Pipe pipe(x, y, j == 0 ? true : map[j - 1][i] != '|',
                  i == 0 ? true : line[i - 1] != '|');
        if (i > 0 && line[i - 1] == '|')
          line[i] = '/';
        pipes.push_back(pipe);
        pipe.draw(window);

      } else if (line[i] == 'f') {
        Flag flag(x, y, j == 0 ? true : map[j - 1][i] != 'f');
        flags.push_back(flag);
        flag.draw(window);

      } else if (line[i] == '?' || line[i] == 'm' || line[i] == 'h') {
        Question question(x, y, line[i]);
        questions.push_back(question);
        question.draw(window);
      }
    }
    y += BLOCK_SIZE;
  }
}
void View::drawMap() {
  window->clear();
  drawBackground();
  drawObjects();
  mario.setY(getSurface(mario.getX(), mario.getY()));
  // cout << mario.getX() << "/" << mario.getY() << endl;
  mario.draw(window);
  window->update_screen();
}
void View::moveMario(int dir) {
  if (dir > 0 && mario.getX() + 100 > mapHeight) {
    cameraX += getWidth() - 800 < cameraX ? 0 : 2;
    mario.move(0);
  } else {
    if (mario.getX() <= 2 && dir < 0)
      return;
    mario.move(dir * 2);
  }
}
void View::drawBackground() {
  for (int i = 0; i < mapWidth / mapHeight; i++)
    window->draw_img("assets/background_image.png",
                     Rectangle(-cameraX / 2 + i * mapHeight * 2, 0,
                               mapHeight * 2, mapHeight));
}
void View::readMapfile(string mapFileAddress) {
  ifstream mapFile;
  mapFile.open(mapFileAddress);
  string temp;
  mapHeight = 0;
  while (getline(mapFile, temp)) {
    mapWidth = temp.length();
    mapHeight++;
    map.push_back(temp);
  }
  mapHeight *= BLOCK_SIZE;
  mapWidth *= BLOCK_SIZE;
}
