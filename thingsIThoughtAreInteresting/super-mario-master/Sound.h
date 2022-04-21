#ifndef SOUND_H
#define SOUND_H

#include "rsdl.hpp"
#include "Camera.h"

#define BACKGROUND_MUSIC "assets/sounds/Super Mario Bros. theme music.mp3"
#define NORMAL_JUMP_SOUND "assets/sounds/sound_effects/jump-small.wav"
#define BIG_JUMP_SOUND "assets/sounds/sound_effects/jump-super.wav"
#define COIN_SOUND "assets/sounds/sound_effects/coin.wav"
#define GAME_OVER_SOUND "assets/sounds/sound_effects/gameover.wav"
#define WIN_SOUND "assets/sounds/sound_effects/level-clear.wav"
#define DEATH_SOUND "assets/sounds/sound_effects/mario-death.wav"
#define EAT_MUSHROOM_SOUND "assets/sounds/sound_effects/powerup.wav"
#define MUSHROOM_APPEAR_SOUND "assets/sounds/sound_effects/powerup-appears.wav"
#define BRICK_BREAK_SOUND "assets/sounds/sound_effects/brick-smash.wav"
#define KILL_ENEMY_SOUND "assets/sounds/sound_effects/enemy-stomp.wav"

class Camera;

class Sound {
public:
    void setCamera(Camera* _camera);
    void playJump(bool isMarioBig);
    void playCoin();
    void playGameOver();
    void pauseBackgroudnMusic();
    void continueBackgroundMusic();
    void playDeathEffect();  
    void playWinEffect();
    void playEatMushroomEffect();
    void playMushroomAppearEffect();
    void playBrickSmashSound();
    void playKillEnemyEffect();

private:
    void playBackgroundMusic();
    void playEffect(std::string fileName);

    Camera* camera;

};

#endif