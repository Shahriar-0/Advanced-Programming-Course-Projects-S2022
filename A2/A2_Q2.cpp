#include <iostream>
#include <string>

bool interleaving(std::string first, std::string second, std::string key, 
                  int indexFirst = 0, int indexSecond = 0, int indexKey = 0) {

    if (indexKey == key.length())
        return true;

    if (key[indexKey] != first[indexFirst] && key[indexKey] != second[indexSecond])
        return false;

    bool foundInterleaving = false;

    if (key[indexKey] == first[indexFirst])
        foundInterleaving = interleaving(first, second, key, indexFirst + 1, indexSecond, indexKey + 1);
    if (!foundInterleaving && key[indexKey] == second[indexSecond])
        foundInterleaving = interleaving(first, second, key, indexFirst, indexSecond + 1, indexKey + 1);

    return foundInterleaving;
}

bool is_interleaving(std::string firstWord, std::string secondWord, std::string keyWord) {
    return firstWord.length() + secondWord.length() == keyWord.length() && 
           interleaving(firstWord, secondWord, keyWord);
}

int main(void) {
    std::string firstWord, secondWord, keyWord;
    std::cin >> firstWord >> secondWord >> keyWord;
    std::cout << (is_interleaving(firstWord, secondWord, keyWord) ? 
                  "Interleaving" : "Not Interleaving") << std::endl;
}
