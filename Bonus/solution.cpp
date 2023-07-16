#include <iostream>
#include <vector>

using namespace std;

#define NUM_OF_MOVES 4

long int sum_of_a_row(const vector<int>& row) {
    long int sum = 0;
    for (int i = 0; i < row.size(); i++)
        sum += row[i];
    return sum;
}

long int sum_of_a_column(const vector<vector<int>>& farm, int column) {
    long int sum = 0;
    for (int i = 0; i < farm.size(); i++)
        sum += farm[i][column];
    return sum;
}

long int find_max_row(const vector<vector<int>>& farm, int rowCount, int& rowIndex) {
    long int answer = INT32_MIN;

    for (int i = 0; i < rowCount; i++) {
        long int currentSum = sum_of_a_row(farm[i]);

        if (currentSum > answer) {
            rowIndex = i;
            answer = currentSum;
        }
    }

    return answer;
}

long int find_max_column(const vector<vector<int>>& farm, int columnCount, int& columnIndex) {
    long int answer = INT32_MIN;

    for (int i = 0; i < columnCount; i++) {
        long int currentSum = sum_of_a_column(farm, i);

        if (currentSum > answer) {
            columnIndex = i;
            answer = currentSum;
        }
    }

    return answer;
}

void harvest_a_row(vector<vector<int>>& farm,  int rowIndex, int columnCount) {
    for (int i = 0; i < columnCount; i++)
        farm[rowIndex][i] = 0;
}

void harvest_a_column(vector<vector<int>>& farm,  int columnIndex, int rowCount) {
    for (int i = 0; i < rowCount; i++)
        farm[i][columnIndex] = 0;
}

long int find_most_profitables(int rowCount, int columnCount,vector<vector<int>>& farm, int numOfMoves) {
    int maxRow, maxColumn, rowIndex, columnIndex;
    long int harvested = 0;

    for (int move = 0; move < numOfMoves; move++) {
        maxRow = find_max_row(farm, rowCount, rowIndex);
        maxColumn = find_max_column(farm, columnCount, columnIndex);

        if (maxRow > maxColumn) {
            harvested += maxRow;
            harvest_a_row(farm, rowIndex, columnCount);
        }
        else {
            harvested += maxColumn;
            harvest_a_column(farm, columnIndex, rowCount);
        }
    }

    return harvested;
}

vector<vector<int>> get_input(int rowCount, int columnCount) {
    vector<vector<int>> result(rowCount, vector<int>(columnCount));
    
    for (int i = 0; i < rowCount; i++) 
        for (int j = 0; j < columnCount; j++) 
            cin >> result[i][j];
        
    return result;
}

int main() {
    int rowCount, columnCount;
    cin >> rowCount >> columnCount;
    
    vector<vector<int>> farm = get_input(rowCount, columnCount);

    long int harvested = find_most_profitables(rowCount, columnCount, farm, NUM_OF_MOVES);
    
    cout << harvested << endl;
    return 0;
}
