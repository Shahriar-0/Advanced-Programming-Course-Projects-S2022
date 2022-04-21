#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "Objects.h"
#include "rsdl.hpp"
#include <vector>
#include "Mario.h"
#include "QuestionBlock.h"
#include "BrickBlock.h"
#include "Mushroom.h"
#include "Sound.h"
#include "LittleGoomba.h"


#define ESTIMATION_Y 20
#define ESTIMATION_X 3

class Mario;
class Sound;
class Objects;

class CollisionHandler {
public:
    CollisionHandler(Objects* _objects);
    enum CollisionType {
        RIGHT,
        LEFT,
        UP,
        DOWN,
        DIE,
        NONE
    };
    void setMario(Mario* _mario);
    void addStaticObjects(Rectangle* position);
    void addFlag(Rectangle* _flag);
    void addNormalBlock(Rectangle* position);
    void addQuestionBlock(QuestionBlock* _QBlock);
    void addBrickBlock(BrickBlock* _brickBlock);
    void addGoomba(LittleGoomba* _goomba);
    void addKoopa(KoopaTroopa* _koopa);
    void handleCollisions();
    void addSound(Sound* _sound);

private:
    struct ColMario {
        Mario* mario;
        Rectangle* position;
        bool* collidesDown;
    };
    struct ColQBlock {
        QuestionBlock* QBlock;
        Rectangle* position;
    };
    struct ColBrickBlock {
        BrickBlock* brickBlock;
        Rectangle* position;
    };
    struct ColGoomba {
        LittleGoomba* goomba;
        Rectangle* position;
        bool* collidesDown;
    };
    struct ColKoopa {
        KoopaTroopa* koopa;
        Rectangle* position;
        bool* collidesDown;
    };
    struct ColMushroom {
        Mushroom* mushroom;
        Rectangle* position;
        bool* collidesDown;
    };

    CollisionType collides(Rectangle* mainObj, int vx, int vy, Rectangle* obj);
    CollisionType movingObjectsCollide(Rectangle* obj2, bool collidesDown2, int vx2, int vy2, Rectangle* obj1, bool collidesDown1, int vx1, int vy1);
    int getRx(Rectangle* rect);
    int getBy(Rectangle* rect);
    void checkWin();
    void handleMarioStaticObjectsCollision();
    void handleMarioQBlocksCollision();
    void handleMarioBricksCollision();
    void handleMario(CollisionType collision);
    void checkGoombas();
    void handleGoomba(ColGoomba* goomba, CollisionType collision);
    void handleGoombasStaticObjsCollision(ColGoomba* goomba);
    void handleGoombasQBlocksCollision(ColGoomba* goomba);
    void handleGoombasBricksCollision(ColGoomba* goomba);
    void handleGoombaMarioCollision(ColGoomba* goomba);
    void checkKoopas();
    void handleKoopa(ColKoopa* koopa, CollisionType collision);
    void handleKoopasStaticObjsCollision(ColKoopa* koopa);
    void handleKoopasQBlocksCollision(ColKoopa* koopa);
    void handleKoopasBricksCollision(ColKoopa* koopa);
    void handleKoopasMarioCollision(ColKoopa* koopa);
    void checkMushrooms();
    void handleMushroom(ColMushroom* mushroom, CollisionType collision);
    void handleMushroomsStaticObjsCollision(ColMushroom* mushroom);
    void handleMushroomsQBlocksCollision(ColMushroom* mushroom);
    void handleMushroomsBricksCollision(ColMushroom* mushroom);
    void handleMushroomMarioCollision(ColMushroom* mushroom);
    void addNewMushroom(char type, Rectangle Position);
    void checkKoopasGoombasCollision();
    void checkKoopaKoopaCollision();

    Objects* objects;
    Sound* sound;
    ColMario mario;
    std::vector<Rectangle*> staticObjects;
    std::vector<ColQBlock*> questionBlocks;
    std::vector<ColBrickBlock*> brickBlocks;
    std::vector<ColGoomba*> goombas;
    std::vector<ColKoopa*> koopas; 
    std::vector<ColMushroom*> mushrooms;
    Rectangle* flag;   
};


#endif