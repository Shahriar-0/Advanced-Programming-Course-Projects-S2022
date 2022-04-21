#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(Objects* _objects): 
    objects(_objects) {

}

void CollisionHandler::setMario(Mario* _mario) {
    mario.mario = _mario;
    mario.position = mario.mario->getPositionPointer();
    mario.collidesDown = mario.mario->getDownCollisionPointer();
}

#include <iostream>

CollisionHandler::CollisionType CollisionHandler::collides(Rectangle* mainObj, int vx, int vy, Rectangle* obj) {
    if ((mainObj->y >= obj->y && mainObj->y < getBy(obj))
    || (getBy(mainObj) <= getBy(obj) && getBy(mainObj) > obj->y)
    ||  (getBy(mainObj) + vy > obj->y && vy > 0) ) {
        if (getRx(mainObj) <= obj->x && getRx(mainObj) + vx >= obj->x) {
            mainObj->x = obj->x - mainObj->w;
            return RIGHT;
        }
        if (mainObj->x >= getRx(obj) && mainObj->x + vx < getRx(obj)) {
            mainObj->x = obj->x + obj->w;
            return LEFT;
        }
    }
    if ((mainObj->x >= obj->x && mainObj->x < getRx(obj))
    || (getRx(mainObj) <= getRx(obj) && getRx(mainObj) > obj->x)) {
        if (getBy(mainObj) <= obj->y && getBy(mainObj) + vy >= obj->y) {
            mainObj->y = obj->y - mainObj->h;
            return DOWN;
        }
        if (mainObj->y >= getBy(obj) && mainObj->y + vy <= getBy(obj)) {
            mainObj->y = obj->y + obj->h;
            return UP;
        }
    }
    return NONE;
}

CollisionHandler::CollisionType CollisionHandler::movingObjectsCollide(Rectangle* obj2, bool collidesDown2, int vx2, int vy2, Rectangle* obj1, bool collidesDown1, int vx1, int vy1) {
    Rectangle nextObj2Pos = Rectangle(obj2->x + vx2, obj2->y + vy2, obj2->w, obj2->h);
    Rectangle nextObj1Pos = Rectangle(obj1->x + vx1, obj1->y + vy1, obj1->w, obj1->h);
    if (collidesDown1 && collidesDown2 && getBy(obj1) == getBy(obj2)) {
        if (getRx(obj1) < obj2->x && getRx(&nextObj1Pos) >= nextObj2Pos.x) {
            obj1->x = nextObj2Pos.x - obj1->w;
            return LEFT;
        }
        if (obj1->x >= getRx(obj2) && nextObj1Pos.x <= getRx(&nextObj2Pos)) {
            obj1->x = getRx(&nextObj2Pos);
            return RIGHT;
        }
    }
    else if (getBy(obj1) <= obj2->y && getBy(&nextObj1Pos) > nextObj2Pos.y ) {
        if (vx2 > 0 
        && ( (nextObj1Pos.x > obj2->x && nextObj1Pos.x < getRx(&nextObj2Pos)) 
        || ( getRx(&nextObj1Pos) > obj2->x && getRx(&nextObj1Pos) < getRx(&nextObj2Pos) ) )) {
            obj1->y = nextObj2Pos.y - obj1->h;
            return UP;
        }
        if (vx2 < 0 
        && ( (nextObj1Pos.x > nextObj2Pos.x && nextObj1Pos.x < getRx(obj2)) 
        || ( getRx(&nextObj1Pos) > nextObj2Pos.x && getRx(&nextObj1Pos) < getRx(obj2) ) )) {
            obj1->y = nextObj2Pos.y - obj1->h;
            return UP;
        }
    }
    return NONE;
}

int CollisionHandler::getRx(Rectangle* rect) {
    return rect->x + rect->w;
}

int CollisionHandler::getBy(Rectangle* rect) {
    return (rect->y + rect->h);
}

void  CollisionHandler::handleMario(CollisionType collision) {
    switch (collision) {
            case RIGHT:
            case LEFT:
                mario.mario->setVx(0);
                break;
            case UP:
                mario.mario->setVy(0);
                break;
            case DOWN:
                mario.mario->setVy(0);
                *mario.collidesDown = true;
                break; 
        }
}

void CollisionHandler::handleCollisions() {
    checkGoombas();
    checkKoopas();
    checkMushrooms();
    if (!mario.mario->isAlive())
        return;
    *mario.collidesDown = false;
    checkWin();
    handleMarioQBlocksCollision();
    handleMarioStaticObjectsCollision();
    handleMarioBricksCollision();
    checkKoopasGoombasCollision();
    checkKoopaKoopaCollision();
}

void CollisionHandler::handleMarioStaticObjectsCollision() {
    for (int i = 0; i < staticObjects.size(); i++) {
        CollisionType collision = collides(mario.position, mario.mario->getVx(), mario.mario->getVy(), staticObjects[i]);
        handleMario(collision);
    }
}

void CollisionHandler::handleMarioQBlocksCollision() {
    for (int i = 0; i < questionBlocks.size(); i++) {
        CollisionType collision = collides(mario.position, mario.mario->getVx(), mario.mario->getVy(), questionBlocks[i]->position);
        handleMario(collision);
        if (collision == UP) {
            char blockType = questionBlocks[i]->QBlock->hit();
            switch (blockType) {
                case COIN_BLOCK:
                    mario.mario->addCoin();
                    break;
                case RED_MUSHROOM_BLOCK:
                case HEALTH_MUSHROOM:
                    addNewMushroom(blockType,
                        Rectangle(Point(questionBlocks[i]->position->x,
                        questionBlocks[i]->position->y - BLOCK_SIZE), BLOCK_SIZE, BLOCK_SIZE)
                    );
            }
        }
    }
}

void CollisionHandler::addNewMushroom(char type, Rectangle position) {
    sound->playMushroomAppearEffect();
    Mushroom* mushroom = new Mushroom(position, type);
    ColMushroom* colMushroom = new ColMushroom;
    colMushroom->collidesDown = mushroom->getDownCollisionPointer();
    colMushroom->mushroom = mushroom;
    colMushroom->position = mushroom->getPositionPointer();
    mushrooms.push_back(colMushroom);
    objects->addMushroom(mushroom);
}

void CollisionHandler::handleMarioBricksCollision() {
    for (int i = 0; i < brickBlocks.size(); i++) {
        CollisionType collision = collides(mario.position, mario.mario->getVx(), mario.mario->getVy(), brickBlocks[i]->position);
        handleMario(collision);
        if (collision == UP) {
            if (!mario.mario->isMarioNormal())
                sound->playBrickSmashSound();
            brickBlocks[i]->brickBlock->hit(!mario.mario->isMarioNormal());
        }
    }
}

void CollisionHandler::handleGoomba(ColGoomba* goomba, CollisionType collision) {
    switch (collision) {
        case LEFT:
        case RIGHT:
            goomba->goomba->setVx(-goomba->goomba->getVx());
            break;
        case DOWN:
            *goomba->collidesDown = true;
            goomba->goomba->setVy(0);
            break;
    }
}

void CollisionHandler::checkGoombas() {
    for (int i = 0; i < goombas.size(); i++) {
        if(goombas[i]->goomba->isDead())
            continue;
        *goombas[i]->collidesDown = false;
        handleGoombasStaticObjsCollision(goombas[i]);
        handleGoombasQBlocksCollision(goombas[i]);
        handleGoombasBricksCollision(goombas[i]);
        handleGoombaMarioCollision(goombas[i]);
    }
}


void CollisionHandler::handleGoombasStaticObjsCollision(ColGoomba* goomba) {
    for (int i = 0; i < staticObjects.size(); i++) {
        CollisionType collision = collides(goomba->position, goomba->goomba->getVx(), goomba->goomba->getVy(), staticObjects[i]);
        handleGoomba(goomba , collision);
    }
}

void CollisionHandler::handleGoombasQBlocksCollision(ColGoomba* goomba) {
    for (int i = 0; i < questionBlocks.size(); i++) {
        CollisionType collision = collides(goomba->position, goomba->goomba->getVx(), goomba->goomba->getVy(), questionBlocks[i]->position);
        handleGoomba(goomba , collision);
    }
}

void CollisionHandler::handleGoombasBricksCollision(ColGoomba* goomba) {
    for (int i = 0; i < brickBlocks.size(); i++) {
        CollisionType collision = collides(goomba->position, goomba->goomba->getVx(), goomba->goomba->getVy(), brickBlocks[i]->position);
        handleGoomba(goomba , collision);
    }
}

void CollisionHandler::handleGoombaMarioCollision(ColGoomba* goomba) {
    CollisionType collision = movingObjectsCollide(goomba->position, goomba->collidesDown, goomba->goomba->getVx(), goomba->goomba->getVx(),
            mario.position, *mario.collidesDown, mario.mario->getVx(), mario.mario->getVy());
    switch (collision) {
        case LEFT:
        case RIGHT:
        case DOWN:
            mario.mario->die();
            break;
        case UP:
            mario.mario->setVy(-20);
            goomba->goomba->die();
            sound->playKillEnemyEffect();
    }
}

void CollisionHandler::checkKoopas() {
    for (int i = 0; i < koopas.size(); i++) {
        *koopas[i]->collidesDown = false;
        handleKoopasStaticObjsCollision(koopas[i]);
        handleKoopasQBlocksCollision(koopas[i]);
        handleKoopasBricksCollision(koopas[i]);
        handleKoopasMarioCollision(koopas[i]);
    }
}

void CollisionHandler::handleKoopa(ColKoopa* koopa, CollisionType collision) {
    switch (collision) {
        case LEFT:
        case RIGHT:
            koopa->koopa->setVx(-koopa->koopa->getVx());
            break;
        case DOWN:
            *koopa->collidesDown = true;
            koopa->koopa->setVy(0);
            break;
    }
}
void CollisionHandler::handleKoopasStaticObjsCollision(ColKoopa* koopa) {
    for (int i = 0; i < staticObjects.size(); i++) {
        CollisionType collision = collides(koopa->position, koopa->koopa->getVx(), koopa->koopa->getVy(), staticObjects[i]);
        handleKoopa(koopa , collision);
    }
}

void CollisionHandler::handleKoopasQBlocksCollision(ColKoopa* koopa) {
    for (int i = 0; i < questionBlocks.size(); i++) {
        CollisionType collision = collides(koopa->position, koopa->koopa->getVx(), koopa->koopa->getVy(), questionBlocks[i]->position);
        handleKoopa(koopa , collision);
    }
}       


void CollisionHandler::handleKoopasBricksCollision(ColKoopa* koopa) {
    for (int i = 0; i < brickBlocks.size(); i++) {
        CollisionType collision = collides(koopa->position, koopa->koopa->getVx(), koopa->koopa->getVy(), brickBlocks[i]->position);
        handleKoopa(koopa , collision);
    }
}

void CollisionHandler::handleKoopasMarioCollision(ColKoopa* koopa) {
    CollisionType collision = movingObjectsCollide(koopa->position, koopa->collidesDown, koopa->koopa->getVx(), koopa->koopa->getVx(),
        mario.position, *mario.collidesDown, mario.mario->getVx(), mario.mario->getVy());
    switch (collision) {
        case LEFT:
        case RIGHT:
        case DOWN:
            mario.mario->die();
            break;
        case UP:
            sound->playKillEnemyEffect();
            mario.mario->setVy(-20);
            koopa->koopa->die();
            
    }
}

void CollisionHandler::handleMushroom(ColMushroom* mushroom, CollisionType collision) {
    switch (collision) {
        case LEFT:
        case RIGHT:
            mushroom->mushroom->setVx(-mushroom->mushroom->getVx());
            break;
        case DOWN:
            *mushroom->collidesDown = true;
            mushroom->mushroom->setVy(0);
            break;
    }
}

void CollisionHandler::handleMushroomsStaticObjsCollision(ColMushroom* mushroom) {
    *mushroom->collidesDown = false;
    for (int i = 0; i < staticObjects.size(); i++) {
        CollisionType collision = collides(mushroom->position, mushroom->mushroom->getVx(), mushroom->mushroom->getVy(), staticObjects[i]);
        handleMushroom(mushroom , collision);
    }
}

void CollisionHandler::handleMushroomsQBlocksCollision(ColMushroom* mushroom) {
    for (int i = 0; i < questionBlocks.size(); i++) {
        CollisionType collision = collides(mushroom->position, mushroom->mushroom->getVx(), mushroom->mushroom->getVy(), questionBlocks[i]->position);
        handleMushroom(mushroom , collision);
    }
}

void CollisionHandler::handleMushroomsBricksCollision(ColMushroom* mushroom) {
    for (int i = 0; i < brickBlocks.size(); i++) {
        CollisionType collision = collides(mushroom->position, mushroom->mushroom->getVx(), mushroom->mushroom->getVy(), brickBlocks[i]->position);
        handleMushroom(mushroom , collision);
    }
}

void CollisionHandler::handleMushroomMarioCollision(ColMushroom* mushroom) {
    CollisionType collision = movingObjectsCollide(mushroom->position, mushroom->collidesDown, mushroom->mushroom->getVx(), mushroom->mushroom->getVx(),
        mario.position, *mario.collidesDown, mario.mario->getVx(), mario.mario->getVy());
    if (collision != NONE) {
        mushroom->mushroom->beEaten();
        mario.mario->eatMushroom(mushroom->mushroom->getType());
    }
}

void CollisionHandler::checkMushrooms() {
    for (int i = 0; i < mushrooms.size(); i++) {
        if(mushrooms[i]->mushroom->isEaten())
            continue;
        *mushrooms[i]->collidesDown = false;
        handleMushroomsStaticObjsCollision(mushrooms[i]);
        handleMushroomsQBlocksCollision(mushrooms[i]);
        handleMushroomsBricksCollision(mushrooms[i]);
        handleMushroomMarioCollision(mushrooms[i]);
    }
}

void CollisionHandler::addFlag(Rectangle* _flag) {
    flag = _flag;
}

void CollisionHandler::addStaticObjects(Rectangle* position) {
    staticObjects.push_back(position);
}

void CollisionHandler::addQuestionBlock(QuestionBlock* _QBlock) {
    ColQBlock* QBlock = new ColQBlock;
    QBlock->QBlock = _QBlock;
    QBlock->position = _QBlock->getPositionPointer();
    questionBlocks.push_back(QBlock);
}

void CollisionHandler::addBrickBlock(BrickBlock* _brickBlock) {
    ColBrickBlock* brickBlock = new ColBrickBlock;
    brickBlock->brickBlock = _brickBlock;
    brickBlock->position = brickBlock->brickBlock->getPositionPointer();
    brickBlocks.push_back(brickBlock);
}

void CollisionHandler::addGoomba(LittleGoomba* _goomba) {
    ColGoomba* goomba = new ColGoomba;
    goomba->goomba = _goomba;
    goomba->position = goomba->goomba->getPositionPointer();
    goomba->collidesDown = goomba->goomba->getDownCollisionPointer();
    goombas.push_back(goomba);
}

void CollisionHandler::addKoopa(KoopaTroopa* _koopa) {
    ColKoopa* koopa = new ColKoopa;
    koopa->koopa = _koopa;
    koopa->collidesDown = _koopa->getDownCollisionPointer();
    koopa->position = _koopa->getPositionPointer();
    koopas.push_back(koopa);
}

void CollisionHandler::checkWin() {
    if (collides(mario.position, mario.mario->getVx(), mario.mario->getVy(), flag) != NONE)
        mario.mario->won();
}

void CollisionHandler::checkKoopasGoombasCollision() {
    CollisionType collision;
    for (int i = 0; i < koopas.size(); i++) {
        if(!koopas[i]->koopa->isDead())
            continue;
        for (int j = 0; j < goombas.size(); j++) {
            if(goombas[j]->goomba->isDead())
                continue;
            collision = movingObjectsCollide(goombas[j]->position, goombas[j]->collidesDown,
                goombas[j]->goomba->getVx(), goombas[j]->goomba->getVx(),
                koopas[i]->position, koopas[i]->collidesDown,
                koopas[i]->koopa->getVx(),koopas[i]->koopa->getVy());
            if (collision != NONE)
                goombas[j]->goomba->die();
        }
    }
}

void CollisionHandler::checkKoopaKoopaCollision() {
    CollisionType collision;
    for (int i = 0; i < koopas.size(); i++) {
        if (!koopas[i]->koopa->isDead())
            continue;
        for (int j = 0; j < koopas.size(); j++) {
            if(koopas[j]->koopa->isDead())
                continue;
            collision = movingObjectsCollide(koopas[j]->position, koopas[j]->collidesDown,
                koopas[j]->koopa->getVx(), koopas[j]->koopa->getVx(),
                koopas[i]->position, koopas[i]->collidesDown,
                koopas[i]->koopa->getVx(),koopas[i]->koopa->getVy());
            if (collision != NONE)
                koopas[j]->koopa->dieByKoopa();
        }
    }
}

void CollisionHandler::addSound(Sound* _sound) {
    sound = _sound;
}