#include "block.hpp"
using namespace std;
Block::Block(Position _position, TYPE _type, int id)
    : position(_position), type(_type), bonusId(id), haveBonus(true) {}
Block::Block(Position _position, TYPE _type, bool _breakable)
    : position(_position), type(_type), breakable(_breakable) {}

void Block::breakMe() { broken = true; }
Position Block::getPosition() { return position; }
int Block::getBonusId() { return bonusId; }
bool Block::isBroken() { return broken; }

int Block::open(bool shouldBreak) {
  if (shouldBreak && breakable) {
    breakMe();
    return BREAK;
  }
  if (type == BRICK) {
    vy = -10;
    return MOVED_UP;
  }
  if (type != QUESTION_1)
    return NO_ACTION;
  type = QUESTION_EMPTY;
  picChanger = 0;
  return OPENED;
}
void Block::render(Window *window, int cameraX) {
  if (broken)
    return;
  if (type == BRICK)
    vy = min(vy + 1, 0);
  if (type == QUESTION_1)
    picChanger = (picChanger + 1) % (PIC_SPEED * 3);

  window->draw_img(OBJECTS_PIC_ADDRESS[((int)type) + picChanger / PIC_SPEED],
                   Rectangle(-cameraX + position.x, position.y + vy, BLOCK_SIZE,
                             BLOCK_SIZE));
}
bool Block::isIn(Position pos) { return Xin(pos.x) && Yin(pos.y); }
bool Block::Xin(int x) {
  if (x >= position.x && x <= position.x + BLOCK_SIZE)
    return true;
  return false;
}
bool Block::Yin(int y) {
  if (y >= position.y && y <= position.y + BLOCK_SIZE)
    return true;
  return false;
}
