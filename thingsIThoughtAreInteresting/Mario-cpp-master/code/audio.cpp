#include "audio.hpp"

AudioPlayer::AudioPlayer(Window *win) : window(win){};
void AudioPlayer::play(AUDIO audio) {
  window->play_sound_effect(Audio_address[audio]);
}
void AudioPlayer::playMusic() { window->play_music(Audio_address[MUSIC]); }
void AudioPlayer::pauseMusic() { window->stop_music(); }
