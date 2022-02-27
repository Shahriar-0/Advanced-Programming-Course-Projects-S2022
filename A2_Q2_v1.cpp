#include <iostream>
#include <string>

using namespace std;

bool is_interleaving(string first, string second, string key, int indexFirst = 0, int indexSecond = 0, int indexKey = 0) {
    bool foundInterleaving = false;

    if (indexFirst == first.length() && indexSecond == second.length()) {
        //when we reach to the end of both words
        if (indexKey == key.length())
            //if we found all of key then it's ok
            foundInterleaving = true;
        return foundInterleaving;
    }

    if (key[indexKey] != first[indexFirst] && key[indexKey] != second[indexSecond])
        //if none of them match with the looking character
        return false;

    if (key[indexKey] == first[indexFirst])
        foundInterleaving = is_interleaving(first, second, key, indexFirst + 1, indexSecond, indexKey + 1);
    if (key[indexKey] == second[indexSecond] && !foundInterleaving)
        //the second condition is for both of them match and
        //we have to check both of them
        foundInterleaving = is_interleaving(first, second, key, indexFirst, indexSecond + 1, indexKey + 1);

    return foundInterleaving;
}

int main(void) {
    string firstWord, secondWord, keyWord;
    cin >> firstWord >> secondWord >> keyWord;
    (is_interleaving(firstWord, secondWord, keyWord))? cout << "Interleaving\n" : cout << "Not Interleaving\n";
}
