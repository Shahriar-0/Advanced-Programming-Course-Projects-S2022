#include <iostream>
#include <vector>
using namespace std;

bool can_be_weighted(vector<int>& listOfWeights, int goal, int index = 0, int sum = 0) {
    if (index == listOfWeights.size())
        return abs(sum) == goal;
    bool foundAnswer = false;
    //there's only three possible choice
    foundAnswer = foundAnswer || can_be_weighted(listOfWeights, goal, index + 1, sum + listOfWeights[index]);
    foundAnswer = foundAnswer || can_be_weighted(listOfWeights, goal, index + 1, sum);
    foundAnswer = foundAnswer || can_be_weighted(listOfWeights, goal, index + 1, sum - listOfWeights[index]);
    return foundAnswer;
}

int main(void) {
    int numOfStones, goalWeight;
    cin >> numOfStones >> goalWeight;
    vector<int> listOfWeights(numOfStones);
    for (int i = 0; i < numOfStones; i++)
        cin >> listOfWeights[i];
    (can_be_weighted(listOfWeights, goalWeight))? cout << "True\n" : cout << "False\n";
}