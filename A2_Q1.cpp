#include <iostream>
#include <math.h>
using namespace std;

int num_of_changes(int index) {
    if (index == 1)
        return 0;
    //if it's divisible by two then it's the opposite of ceil(index / 2)
    //if not the same
    return !(index % 2) + num_of_changes(ceil(index / 2.0));
}

int main(void) {
    int numOfLevel, index;
    cin >> numOfLevel >> index;
    cout << (num_of_changes(index) % 2) << endl; 
}
