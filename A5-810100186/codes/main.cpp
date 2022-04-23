#include <iostream>
#include "star_wars.hpp"
using namespace std;

int main(int argc, char* argv[]) {
	try {
		if (argc == 1)
			throw "haven't passed a map";
		StarWars starwars(argv[1], new Window(1500, 1100, "a long walk home"));
	}
	catch (string exception) {
		cerr << exception << endl;
	}
	catch (...) {
		cerr << "sth unexpected happened" << endl;
	}
}