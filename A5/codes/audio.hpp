#ifndef __AUDIO_HPP__
#define __AUDIO_HPP__
#include "rsdl.hpp"
#include <string>
#include <cstring>

enum AudioListType {
    THEME,
    SHOOTING, 
    EXPLOSION,
    LEVEL
};

const std::string AudioList[] {
    "./assets/musics/theme.mp3",
    "./assets/musics/shot.wav", 
    "./assets/musics/explosion.wav",
    "./assets/musics/level.wav"
};

class AudioPlayer {
public:
    AudioPlayer(Window*);
    void play_sound_effect(AudioListType);
    void play_theme();
    void pause_theme();
    void resume_theme();
private:
    Window* win;
};

#endif 