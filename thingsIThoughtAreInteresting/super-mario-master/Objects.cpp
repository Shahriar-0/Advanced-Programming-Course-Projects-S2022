#include "Objects.h"

using namespace std;

Objects::Objects() {
    screenWidth = 0;
}

void Objects::addPipe(Pipe* pipe) {
    pipes.push_back(pipe);
    collisionHandler->addStaticObjects(pipe->getPositionPointer());
}

void Objects::addFlag(Flag* _flag) {
    flag = _flag;
    collisionHandler->addFlag(_flag->getPositionPointer());
}

void Objects::addNormalBlock(NormalBlock* normalBlock) {
    normalBlocks.push_back(normalBlock);
    collisionHandler->addStaticObjects(normalBlock->getPositionPointer());
}

void Objects::addQuestionBlock (QuestionBlock* qBlock) {
    questionBlocks.push_back(qBlock);
    collisionHandler->addQuestionBlock(qBlock);
}

void Objects::addBrickBlock(BrickBlock* brickBlock) {
    brickBlocks.push_back(brickBlock);
    collisionHandler->addBrickBlock(brickBlock);
}

void Objects::addKoopaTroopa(KoopaTroopa* koopa) {
    koopas.push_back(koopa);
    collisionHandler->addKoopa(koopa);
}

void Objects::addLittleGoomba(LittleGoomba* goomba) {
    goombas.push_back(goomba);
    collisionHandler->addGoomba(goomba);
}

void Objects::addMushroom(Mushroom* mushroom) {
    mushrooms.push_back(mushroom);
}

void Objects::update() {
    updateMushrooms();
    updateGoombas();
    updateKoopas();
}

void Objects::draw(Window* win, int winOffset, int step) {
    drawNormalBlocks(win, winOffset);
    drawBrickBlocks(win, winOffset);
    drawQuestionBlocks(win, winOffset, step);
    drawPipes(win, winOffset);
    drawFlag(win, winOffset);
    drawGoombas(win, winOffset, step);
    drawKoopas(win, winOffset, step);
    drawMushrooms(win, winOffset);
}

void Objects::updateKoopas() {
    for (int i = 0; i < koopas.size(); i++)
        koopas[i]->update();
}


void Objects::updateGoombas() {
    for (int i = 0; i < goombas.size(); i++) {
        goombas[i]->update();
    }
}

void Objects::updateMushrooms() {
    for (int i = 0; i < mushrooms.size(); i++)
        mushrooms[i]->update();
}

void Objects::drawNormalBlocks(Window* win, int winOffset) {
    for (int i = 0; i < normalBlocks.size(); i++) {
        normalBlocks[i]->draw(win, winOffset);
    }
}

void Objects::drawBrickBlocks(Window* win, int winOffset) {
    for (int i = 0; i < brickBlocks.size(); i++)
        brickBlocks[i]->draw(win, winOffset);
}

void Objects::drawQuestionBlocks(Window* win, int winOffset, int step) {
    for (int i = 0; i < questionBlocks.size(); i++)
        questionBlocks[i]->draw(win, winOffset, step);
}

void Objects::drawPipes(Window* win, int winOffset) {
    for (int i = 0; i < pipes.size(); i++) {
        pipes[i]->draw(win, winOffset);
    }
}

void Objects::drawFlag(Window* win, int winOffset) {
    flag->draw(win, winOffset);
}

void Objects::drawKoopas(Window* win, int winOffset, int step) {
    for (int i = 0; i < koopas.size(); i++) {
        koopas[i]->draw(win, winOffset, screenWidth, step);
    }
}

void Objects::drawGoombas(Window* win, int winOffset, int step) {
    for (int i = 0; i < goombas.size(); i++) {
        goombas[i]->draw(win, winOffset, screenWidth, step);
    }
}

void Objects::drawMushrooms(Window* win, int winOffset) {
    for (int i = 0; i < mushrooms.size(); i++)
        mushrooms[i]->draw(win, winOffset);
}

void Objects::setScreenWith(int w) {
    screenWidth = w;
}

void Objects::setCollisionHandler(CollisionHandler* cl) {
    collisionHandler = cl;
}