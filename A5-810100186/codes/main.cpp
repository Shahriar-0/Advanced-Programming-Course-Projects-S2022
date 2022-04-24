#include <iostream>
#include "star_wars.hpp"
using namespace std;

constexpr int IMAGE_WIDTH  = 2250;
constexpr int IMAGE_HEIGHT = 1650;

int main(int argc, char* argv[]) {
	try {
		if (argc == 1)
			throw string("haven't passed a map");
		StarWars starwars(argv[1], new Window(IMAGE_WIDTH, IMAGE_HEIGHT, "a long walk home"));
	}
	catch (string exception) {
		cerr << exception << endl;
	}
	catch (...) {
		cerr << "sth unexpected happened" << endl;
	}
}