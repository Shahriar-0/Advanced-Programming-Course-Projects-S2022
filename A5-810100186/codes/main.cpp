#include <iostream>
#include "rsdl.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	Window* win = new Window(1500, 1100, "a long walk home");
	win->draw_img("../assets/pictures/background/galaxy.jpeg");
	win->update_screen();
	delay(2000);
}
