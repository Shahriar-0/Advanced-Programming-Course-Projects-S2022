#include <iostream>
#include "star_wars.hpp"
using namespace std;

int main(int argc, char* argv[]) {
    srand(time(NULL));
	try {
		if (argc == 1)
			throw string("haven't passed a map");
		StarWars starwars(argv[1], new Window(IMAGE_WIDTH, IMAGE_HEIGHT, "a long walk home"));
		starwars.run();
	}
	catch (string exception) {
		cerr << exception << endl;
	}
	catch (...) {
		cerr << "sth unexpected happened" << endl;
	}
}