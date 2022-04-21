#ifndef OBJECTS_H
#define OBJECTS_H

#include <vector>
#include "Pipe.h"
#include "KoopaTroopa.h"
#include "NormalBlock.h"
#include "LittleGoomba.h"
#include "QuestionBlock.h"
#include "BrickBlock.h"
#include "Flag.h"
#include "Mushroom.h"
#include "CollisionHandler.h"

class CollisionHandler;
class Mushroom;

class Objects {
public:
    Objects ();
    void addPipe (Pipe* pipe);
    void addFlag (Flag* _flag);
    void addNormalBlock (NormalBlock* normalBlock);
    void addQuestionBlock (QuestionBlock* qBlock);
    void addBrickBlock(BrickBlock* brickBlock);
    void addKoopaTroopa(KoopaTroopa* koopa);
    void addLittleGoomba(LittleGoomba* goomba);
    void addMushroom(Mushroom* mushroom);
    void draw (Window* win, int winOffset, int step);
    void setScreenWith(int w);
    void update();
    void setCollisionHandler(CollisionHandler* cl);

private:
    void drawNormalBlocks(Window* win, int winOffset);
    void drawPipes(Window* win, int winOffset);
    void drawFlag(Window* win, int winOffset);
    void drawBrickBlocks(Window* win, int winOffset);
    void drawQuestionBlocks(Window* win, int winOffset, int step);
    void drawKoopas(Window* win, int winOffset, int step);
    void drawGoombas(Window* win, int winOffset, int step);
    void drawMushrooms(Window* win, int winOffset);
    void updateGoombas();
    void updateKoopas();
    void updateMushrooms();

    int screenWidth;
    CollisionHandler* collisionHandler;
    std::vector<Pipe*> pipes;
    std::vector<KoopaTroopa*> koopas;
    std::vector<NormalBlock*> normalBlocks;
    std::vector<LittleGoomba*> goombas;
    std::vector<QuestionBlock*> questionBlocks;
    std::vector<BrickBlock*> brickBlocks;
    std::vector<Mushroom*> mushrooms;
    Flag* flag;

};

#endif
