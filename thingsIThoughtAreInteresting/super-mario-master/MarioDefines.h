#define X_SPEED 10
#define JUMP_SPEED 40
#define X_ACCELERATION 1
#define COIN "COINS:"
#define LIVES "LIVES:"
#define FONT "FreeSans.ttf"
#define DEAD_HAS_LIVES 50
#define INVINCIBLE 50
#define IN_AIR_R 0
#define IN_AIR_L 1
#define IDLE_R 0
#define IDLE_L 1
#define WALKING_R 0
#define WALKING_L 1

#define MARIO_NORMAL_STAND_R "assets/sprites/mario/normal/standing-right.png"
#define MARIO_NORMAL_STAND_L "assets/sprites/mario/normal/standing-left.png"
#define MARIO_NORMAL_WALK_R_1 "assets/sprites/mario/normal/walking-right-1.png"
#define MARIO_NORMAL_WALK_R_2 "assets/sprites/mario/normal/walking-right-2.png"
#define MARIO_NORMAL_WALK_R_3 "assets/sprites/mario/normal/walking-right-3.png"
#define MARIO_NORMAL_WALK_L_1 "assets/sprites/mario/normal/walking-left-1.png"
#define MARIO_NORMAL_WALK_L_2 "assets/sprites/mario/normal/walking-left-2.png"
#define MARIO_NORMAL_WALK_L_3 "assets/sprites/mario/normal/walking-left-3.png"
#define MARIO_NORMAL_JUMP_R "assets/sprites/mario/normal/jumping-right.png"
#define MARIO_NORMAL_JUMP_L "assets/sprites/mario/normal/jumping-left.png"
#define MARIO_NORMAL_DEAD "assets/sprites/mario/normal/dead.png"
#define MARIO_NORMAL_SLIDING_L "assets/sprites/mario/normal/sliding-left.png"
#define MARIO_NORMAL_SLIDING_R "assets/sprites/mario/normal/sliding-right.png"

#define MARIO_BIG_STAND_R "assets/sprites/mario/big/standing-right.png"
#define MARIO_BIG_STAND_L "assets/sprites/mario/big/standing-left.png"
#define MARIO_BIG_WALK_R_1 "assets/sprites/mario/big/walking-right-1.png"
#define MARIO_BIG_WALK_R_2 "assets/sprites/mario/big/walking-right-2.png"
#define MARIO_BIG_WALK_R_3 "assets/sprites/mario/big/walking-right-3.png"
#define MARIO_BIG_WALK_L_1 "assets/sprites/mario/big/walking-left-1.png"
#define MARIO_BIG_WALK_L_2 "assets/sprites/mario/big/walking-left-2.png"
#define MARIO_BIG_WALK_L_3 "assets/sprites/mario/big/walking-left-3.png"
#define MARIO_BIG_JUMP_R "assets/sprites/mario/big/jumping-right.png"
#define MARIO_BIG_JUMP_L "assets/sprites/mario/big/jumping-left.png"
#define MARIO_BIG_DEAD "assets/sprites/mario/big/dead.png"
#define MARIO_BIG_SLIDING_L "assets/sprites/mario/big/sliding-left.png"
#define MARIO_BIG_SLIDING_R "assets/sprites/mario/big/sliding-right.png"

const std::array<std::string, 3> NORMAL_WALK_RIGHT_PNG = {
    MARIO_NORMAL_WALK_R_1,
    MARIO_NORMAL_WALK_R_2,
    MARIO_NORMAL_WALK_R_3
};

const std::array<std::string, 3> NORMAL_WALK_LEFT_PNG = {
    MARIO_NORMAL_WALK_L_1,
    MARIO_NORMAL_WALK_L_2,
    MARIO_NORMAL_WALK_L_3
};

const std::array<std::array<std::string, 3>, 2> NORMAL_WALK_PNG = {
    NORMAL_WALK_LEFT_PNG,
    NORMAL_WALK_RIGHT_PNG
};

const std::array<std::string, 2> NORMAL_JUMP_PNG = {
    MARIO_NORMAL_JUMP_L,
    MARIO_NORMAL_JUMP_R
};

const std::array<std::string, 2> NORMAL_STAND_PNG = {
    MARIO_NORMAL_STAND_L,
    MARIO_NORMAL_STAND_R
};

const std::array<std::string, 2> NORMAL_SLIDING_PNG = {
    MARIO_NORMAL_SLIDING_L,
    MARIO_NORMAL_SLIDING_R
};

const std::array<std::string, 3> BIG_WALK_RIGHT_PNG = {
    MARIO_BIG_WALK_R_1,
    MARIO_BIG_WALK_R_2,
    MARIO_BIG_WALK_R_3
};

const std::array<std::string, 3> BIG_WALK_LEFT_PNG = {
    MARIO_BIG_WALK_L_1,
    MARIO_BIG_WALK_L_2,
    MARIO_BIG_WALK_L_3
};

const std::array<std::array<std::string, 3>, 2> BIG_WALK_PNG = {
    BIG_WALK_LEFT_PNG,
    BIG_WALK_RIGHT_PNG
};

const std::array<std::string, 2> BIG_JUMP_PNG = {
    MARIO_BIG_JUMP_L,
    MARIO_BIG_JUMP_R
};

const std::array<std::string, 2> BIG_STAND_PNG = {
    MARIO_BIG_STAND_L,
    MARIO_BIG_STAND_R
};

const std::array<std::string, 2> BIG_SLIDING_PNG = {
    MARIO_BIG_SLIDING_L,
    MARIO_BIG_SLIDING_R
};

const std::array<std::string, 2> DEAD_PNG {
    MARIO_BIG_DEAD,
    MARIO_NORMAL_DEAD
};

const std::array<std::array<std::array<std::string, 3>, 2>, 2>  WALK_PNG {
    BIG_WALK_PNG,
    NORMAL_WALK_PNG
};

const std::array<std::array<std::string, 2>, 2>  JUMP_PNG {
    BIG_JUMP_PNG,
    NORMAL_JUMP_PNG
};

const std::array<std::array<std::string, 2>, 2>  STAND_PNG {
    BIG_STAND_PNG,
    NORMAL_STAND_PNG
};

const std::array<std::array<std::string, 2>, 2>  SLIDING_PNG {
    BIG_SLIDING_PNG,
    NORMAL_SLIDING_PNG
};

const Point HEADER_TEXT_POINT(50, 10);
const Point HEADER_COUNT_POINT(80, 35);