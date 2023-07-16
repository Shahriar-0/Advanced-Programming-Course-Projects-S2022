#include <iostream>
#include <vector>

bool can_be_weighted(std::vector<int>& listOfWeights, int goal, int index = 0, int sum = 0) {
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
    std::cin >> numOfStones >> goalWeight;
    std::vector<int> listOfWeights(numOfStones);
    for (int i = 0; i < numOfStones; i++)
        std::cin >> listOfWeights[i];
    std::cout << (can_be_weighted(listOfWeights, goalWeight)? "True" : "False") << std::endl;
}