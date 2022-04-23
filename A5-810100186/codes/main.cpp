#include <iostream>
#include "rsdl.hpp"
#include "audio.hpp"
using namespace std;

int main(int argc, char* argv[]) {
	Window* win = new Window(1500, 1100, "a long walk home");
	win->draw_img("assets/pictures/background/galaxy.jpeg");
	AudioPlayer player(win);
	win->update_screen();
	player.play_theme();
	delay(10000);
}