#include "Sound.h"

using namespace std;

void Sound::setCamera(Camera* _camera) {
    camera = _camera;
    playBackgroundMusic();
}

void Sound::playEffect(string fileName) {
    camera->getWindow()->play_sound_effect(fileName);
}

void Sound::playBackgroundMusic() {
    camera->getWindow()->play_music(BACKGROUND_MUSIC);
}

void Sound::pauseBackgroudnMusic() {
    camera->getWindow()->pause_music();
}

void Sound::continueBackgroundMusic() {
    playBackgroundMusic();
}

void Sound::playJump(bool isMarioBig) {
    if (isMarioBig)
        playEffect(BIG_JUMP_SOUND);
    else
        playEffect(NORMAL_JUMP_SOUND);
}

void Sound::playCoin() {
    playEffect(COIN_SOUND);
}

void Sound::playGameOver() {
    playEffect(GAME_OVER_SOUND);
}

void Sound::playWinEffect() {
    playEffect(WIN_SOUND);
}

void Sound::playDeathEffect() {
    playEffect(DEATH_SOUND);
}

void Sound::playEatMushroomEffect() {
    playEffect(EAT_MUSHROOM_SOUND);
}

void Sound::playMushroomAppearEffect() {
    playEffect(MUSHROOM_APPEAR_SOUND);
}

void Sound::playBrickSmashSound() {
    playEffect(BRICK_BREAK_SOUND);
}

void Sound::playKillEnemyEffect() {
    playEffect(KILL_ENEMY_SOUND);
}
