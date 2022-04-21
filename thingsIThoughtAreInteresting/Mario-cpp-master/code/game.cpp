#include "game.hpp"
#define RIGHT 1
#define LEFT -1
using namespace std;

Game::Game(string _mapFileAddress) : mapFileAddress(_mapFileAddress) {
  try {
    setup();
    while (1) {
      handleCrashes();
      handleEvents();
      checkWin();
      if (isWin || isLost)
        continue;
      view->nextFrame();
    }
  } catch (string err) {
    cout << endl << "Error Occured :" << err << endl;
  } catch (...) {
    cout << "Error Occured , That's all we know" << endl;
    throw;
  }
}
void Game::checkWin() {
  for (auto b : map.blocks) {
    if (b.getType() == FLAG_BODY) {
      if (b.getPosition().x - mario.getX() < BLOCK_SIZE * 1.5)
        win();
    }
  }
}
void Game::handleCrashes() {
  if (!isMarioCrash())
    mario.setGround(getGround(mario.getRect()));
  setGroundToBonuses();
  setGroundToGumba();
  setGroundToKoopa();
  mushroomHandler();
  gumbaHandler();
  koopaHandler();
  handleFall();
}
void Game::setup() {
  map = MapReader(mapFileAddress).getMap();
  scoreboard = ScoreBoard();
  mario = Mario(map.mario);
  view = new View(&map, &mario, &scoreboard);
  window = view->getWindow();
  audioPlayer = new AudioPlayer(window);
  audioPlayer->playMusic();
}
void Game::handleFall() {
  if (mario.getY() > map.height + BLOCK_SIZE) {
    audioPlayer->play(A_MARIO_DEATH);
    die(true);
  }
}
void Game::handleEvents() {
  Event event = window->poll_for_event();
  if (event.get_type() == Event::KEY_PRESS) {
    char pressed_key = event.get_pressed_key();
    if (pressed_key == 'd')
      mario.move(RIGHT);
    else if (pressed_key == 'a')
      mario.move(LEFT);
    else if (pressed_key == 'w')
      if (mario.jump())
        audioPlayer->play(A_JUMP_SUPER);
  }
  if (event.get_type() == Event::KEY_RELEASE) {
    char releasedKey = event.get_pressed_key();
    if (releasedKey == 'a' || releasedKey == 'd')
      mario.stopMoving();
  }
  if (event.get_type() == Event::QUIT)
    exit(0);
}
void Game::win() {
  isWin = true;
  view->win();
  audioPlayer->pauseMusic();
  audioPlayer->play(A_LEVEL_CLEAR);
}
bool Game::isMarioCrash() {
  static int counter = 0;
  mario.setX(max(view->getCameraX(), mario.getX()));
  for (int i = 0; i < map.blocks.size(); i++) {
    Block *b = &(map.blocks[i]);
    if (b->isBroken())
      continue;
    if (isConflict(
            Rect{mario.getPosition(), mario.getWidth(), mario.getHeight() - 1},
            Rect{b->getPosition(), BLOCK_SIZE, BLOCK_SIZE})) {
      if (mario.getLastPosition().y >= b->getPosition().y + BLOCK_SIZE) {
        hitBlock(b);
      }
      mario.setVy(max(0, mario.getVy()));
      mario.setPosition(mario.getLastPosition());
      return true;
    }
  }
  return false;
}

void Game::hitBlock(Block *b) {
  int state = b->open(mario.isBig());
  if (state == OPENED) {
    Bonus *bns = &(map.bonus[b->getBonusId()]);
    bns->appear();
    if (bns->getType() == COIN) {
      scoreboard.addCoin();
      audioPlayer->play(A_COIN);
    } else
      audioPlayer->play(A_POWERUP_APPEARS);
  } else if (state == BREAK)
    audioPlayer->play(A_BRICK_SMASH);
  else if (state == MOVED_UP)
    audioPlayer->play(A_BUMP);
}

void Game::gumbaHandler() {
  for (int i = 0; i < map.gumbas.size(); i++) {
    Gumba *gumba = &(map.gumbas[i]);
    if (!gumba->isAlive())
      continue;
    if (isConflict(Rect{gumba->getPosition(), GUMBA_SIZE, GUMBA_SIZE},
                   Rect{Position{mario.getPosition().x - FIVE_PIXELS,
                                 mario.getPosition().y},
                        mario.getWidth() + TEN_PIXELS, mario.getHeight()})) {
      if (mario.getLastPosition().y + mario.getHeight() <=
          gumba->getPosition().y) {
        mario.setVy(MARIO_REACT);
        audioPlayer->play(A_ENEMY_STOMP);
        gumba->die();
      } else {
        die();
      }
    }
  }
}
void Game::koopaHandler() {
  for (int i = 0; i < map.koopas.size(); i++) {
    Koopa *koopa = &(map.koopas[i]);
    if (isConflict(Rect{koopa->getPosition(), KOOPA_SIZE, KOOPA_SIZE},
                   Rect{Position{mario.getPosition().x - FIVE_PIXELS,
                                 mario.getPosition().y},
                        mario.getWidth() + TEN_PIXELS, mario.getHeight()})) {
      if (mario.getLastPosition().y + mario.getHeight() <=
          koopa->getPosition().y) {
        mario.setVy(MARIO_REACT);
        audioPlayer->play(A_ENEMY_STOMP);
        if (koopa->isMoving() && !koopa->isAlive())
          die();
        else if (koopa->isAlive())
          koopa->die();
        else
          koopa->shoot(mario.getLastPosition().x > koopa->getPosition().x);
      } else {
        die();
      }
    }
  }
  koopaVsGumbaHandler();
}
void Game::koopaVsGumbaHandler() {
  for (int i = 0; i < map.koopas.size(); i++) {
    Koopa *koopa = &(map.koopas[i]);
    if (koopa->isAlive() || !koopa->isMoving())
      continue;
    for (int i = 0; i < map.gumbas.size(); i++) {
      Gumba *gumba = &(map.gumbas[i]);
      if (!gumba->isAlive())
        continue;
      if (isConflict(Rect{koopa->getPosition(), KOOPA_SIZE, KOOPA_SIZE},
                     Rect{gumba->getPosition(), GUMBA_SIZE, GUMBA_SIZE})) {
        audioPlayer->play(A_ENEMY_STOMP);
        gumba->die();
      }
    }
  }
}
void Game::lost() {
  isLost = true;
  view->lost();
  audioPlayer->play(A_GAMEOVER);
  audioPlayer->pauseMusic();
}
void Game::die(bool forceDie) {
  if (mario.isDieHard() && !forceDie)
    return;
  if (!mario.isBig()) {
    audioPlayer->play(A_MARIO_DEATH);
    scoreboard.decreaseLive();
    mario.toggleDead();
    for (int i = 0; i < 20; i++) {
      mario.goDown();
      view->nextFrame();
    }
    mario.toggleDead();
  }

  mario.die(forceDie);
  if (scoreboard.isDied()) {
    lost();
  }
  if (!mario.isBig() || forceDie)
    view->reset();
}
void Game::setGroundToBonuses() {
  for (int i = 0; i < map.bonus.size(); i++) {
    Bonus *b = &map.bonus[i];
    if (!b->isMoving())
      continue;
    b->setGround(getGround(Rect{b->getPosition(), BLOCK_SIZE, BLOCK_SIZE}));
    if (hasConflict(Rect{b->calculateNextMove(), BLOCK_SIZE, BLOCK_SIZE}))
      b->isCrash();
  }
}
void Game::setGroundToGumba() {
  for (int i = 0; i < map.gumbas.size(); i++) {
    Gumba *b = &map.gumbas[i];
    if (!b->isMoving())
      continue;
    b->setGround(getGround(Rect{b->getPosition(), GUMBA_SIZE, GUMBA_SIZE}));
    if (hasConflict(Rect{b->calculateNextMove(), GUMBA_SIZE, GUMBA_SIZE})) {
      b->isCrash();
    }
  }
}
void Game::setGroundToKoopa() {
  for (int i = 0; i < map.koopas.size(); i++) {
    Koopa *b = &map.koopas[i];
    if (!b->isMoving())
      continue;
    b->setGround(getGround(Rect{b->getPosition(), KOOPA_SIZE, KOOPA_SIZE}));
    if (hasConflict(Rect{b->calculateNextMove(), KOOPA_SIZE, KOOPA_SIZE})) {
      b->isCrash();
    }
  }
}
bool Game::hasConflict(Rect rect) {
  for (auto bl : map.blocks) {
    if (bl.isBroken())
      continue;
    if (isConflict(rect, Rect{bl.getPosition(), BLOCK_SIZE, BLOCK_SIZE}))
      return true;
  }
  return false;
}
void Game::mushroomHandler() {
  for (int i = 0; i < map.bonus.size(); i++) {
    Bonus *b = &(map.bonus[i]);
    if (!b->isVisible() || !b->isReady())
      continue;
    if (isConflict(Rect{b->getPosition(), BLOCK_SIZE, BLOCK_SIZE},
                   mario.getRect())) {
      b->disappear();
      if (b->getType() == H_MUSH)
        getHealthMush();
      if (b->getType() == RED_MUSH)
        getRedMush();
    }
  }
}
void Game::getHealthMush() {
  audioPlayer->play(A_POWERUP);
  scoreboard.addLive();
}
void Game::getRedMush() {
  audioPlayer->play(A_POWERUP);
  mario.getBig();
  mario.setGround(getGround(mario.getRect()));
}
int Game::getGround(Rect rect) {
  for (int y = rect.position.y; y <= map.height; y++)
    for (auto b : map.blocks) {
      if (b.isBroken())
        continue;
      if (b.isIn(Position{rect.position.x + 1, y + rect.height}) ||
          b.isIn(Position{rect.position.x + rect.width - 1, y + rect.height})) {
        return (b.getPosition().y - rect.height);
      }
    }
  return map.height + 2 * BLOCK_SIZE;
}

bool Game::isConflict(Rect rect1, Rect rect2) {
  Position pos1 = rect1.position, pos2 = rect2.position;
  int width1 = rect1.width, width2 = rect2.width;
  int height1 = rect1.height, height2 = rect2.height;

  if ((pos1.x < pos2.x + width2 && pos1.x > pos2.x ||
       pos1.x + width1 < pos2.x + width2 && pos1.x + width1 > pos2.x) &&
      (pos1.y <= pos2.y + height2 && pos1.y >= pos2.y ||
       pos1.y + height1 <= pos2.y + height2 && pos1.y + height1 >= pos2.y))
    return true;
  return false;
};
