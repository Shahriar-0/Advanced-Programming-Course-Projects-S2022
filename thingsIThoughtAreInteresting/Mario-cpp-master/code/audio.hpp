#ifndef AUDIO_HPP
#define AUDIO_HPP
#include "defines.hpp"
class AudioPlayer {
public:
  AudioPlayer(Window *window);
  void play(AUDIO audio);
  void playMusic();
  void pauseMusic();

private:
  Window *window;
};
#endif
