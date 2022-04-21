#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include "../src/rsdl.hpp"
#include <iostream>
#include <string>
#include <vector>
#define GRAVITY 2
#define WIDTH 800
#define BLOCK_SIZE 32
#define FIVE_PIXELS 5
#define TEN_PIXELS 10
using namespace std;
struct Position {
  int x;
  int y;
};

enum TYPE {
  BLOCK = 0,
  BRICK,
  CLAY,
  BLOCK_DEBRIS,
  FLAG_BODY,
  FLAG_HEAD,
  PIPE_HEAD_LEFT,
  PIPE_HEAD_RIGHT,
  PIPE_LEFT,
  PIPE_RIGHT,

  QUESTION_1,
  QUESTION_2,
  QUESTION_3,
  QUESTION_EMPTY,

  COIN,
  FLOWER,
  RED_MUSH,
  H_MUSH,

  GUMBA1,
  GUMBA2,
  GUMBA_DEAD,

  BONUS_DEFAULT
};
const string OBJECTS_PIC_ADDRESS[] = {
    "assets/sprites/objects/bricks_blocks/block.png",
    "assets/sprites/objects/bricks_blocks/brick.png",
    "assets/sprites/objects/bricks_blocks/clay.png",
    "assets/sprites/objects/bricks_blocks/brick-debris.png",

    "assets/sprites/objects/flag/body.png",
    "assets/sprites/objects/flag/head.png",

    "assets/sprites/objects/pipe/head-left.png",
    "assets/sprites/objects/pipe/head-right.png",
    "assets/sprites/objects/pipe/left.png",
    "assets/sprites/objects/pipe/right.png",

    "assets/sprites/objects/bricks_blocks/question-1.png",
    "assets/sprites/objects/bricks_blocks/question-2.png",
    "assets/sprites/objects/bricks_blocks/question-3.png",
    "assets/sprites/objects/bricks_blocks/question-empty.png",

    "assets/sprites/objects/coin.png",
    "assets/sprites/objects/flower.png",
    "assets/sprites/objects/mushroom/red.png",
    "assets/sprites/objects/mushroom/health.png",

    "assets/sprites/enemies/little_goomba/walking-1.png",
    "assets/sprites/enemies/little_goomba/walking-2.png",
    "assets/sprites/enemies/little_goomba/dead.png"};

enum AUDIO {
  A_1UP,
  A_ENEMY_STOMP,
  A_JUMP_SUPER,
  A_POWERUP_APPEARS,
  A_BRICK_SMASH,
  A_FIREBALL,
  A_LEVEL_CLEAR,
  A_POWERUP,
  A_BUMP,
  A_GAMEOVER,
  A_MARIO_DEATH,
  A_COIN,
  A_JUMP_SMALL,
  A_PAUSE,
  MUSIC
};
const string Audio_address[] = {
    "assets/sounds/sound_effects/1-up.wav",
    "assets/sounds/sound_effects/enemy-stomp.wav",
    "assets/sounds/sound_effects/jump-super.wav",
    "assets/sounds/sound_effects/powerup-appears.wav",
    "assets/sounds/sound_effects/brick-smash.wav",
    "assets/sounds/sound_effects/fireball.wav",
    "assets/sounds/sound_effects/level-clear.wav",
    "assets/sounds/sound_effects/powerup.wav",
    "assets/sounds/sound_effects/bump.wav",
    "assets/sounds/sound_effects/gameover.wav",
    "assets/sounds/sound_effects/mario-death.wav",
    "assets/sounds/sound_effects/coin.wav",
    "assets/sounds/sound_effects/jump-small.wav",
    "assets/sounds/sound_effects/pause.wav",
    "assets/sounds/Super Mario Bros. theme music.mp3"};

struct Rect {
  Position position;
  int width;
  int height;
};
#endif
