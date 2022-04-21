#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "Game.h"

using namespace std;

vector<vector<char>> readFile(string fileAdress);

int main(int argc, char* argv[]){
    Game game(argv[1]);
    game.run();
    return 0;
}
