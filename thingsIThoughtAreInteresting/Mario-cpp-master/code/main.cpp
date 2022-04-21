#include "../src/rsdl.hpp"
#include "game.hpp"
#include "iostream"
#include <string>
#define FILE_ADDRESS 1
using namespace std;

int main(int argc, char const *argv[]) {
  cout << " \n--------------\n  App running   \n--------------\n \n\n";

  Game mario(argv[FILE_ADDRESS]);
}
