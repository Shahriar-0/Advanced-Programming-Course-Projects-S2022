#include "audio.hpp"

void AudioPlayer::set_window(Window* _win) { win = _win; }
void AudioPlayer::play_theme() { win->play_music(AudioList[THEME]); }
void AudioPlayer::pause_theme() { win->pause_music(); }
void AudioPlayer::resume_theme() { win->resume_music(); }
void AudioPlayer::play_sound_effect(AudioListType type) { win->play_sound_effect(AudioList[type]); }