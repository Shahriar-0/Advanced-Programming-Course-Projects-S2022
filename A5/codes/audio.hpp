#ifndef __AUDIO_HPP__
#define __AUDIO_HPP__
#include "rsdl.hpp"
#include <string>
#include <cstring>

enum AudioListType {
    THEME,
    SHOOTING, 
    EXPLOSION,
};

const std::string AudioList[] {
    "assets/musics/theme.mp3",
    "assets/musics/shot.wav", 
    "assets/musics/explosion.wav"
};

class AudioPlayer {
public:
    void play_sound_effect(AudioListType);
    void play_theme();
    void pause_theme();
    void resume_theme();
    void set_window(Window*);
private:
    Window* win;
};

#endif 