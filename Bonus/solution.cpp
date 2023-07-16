#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define NUM_OF_MOVES 4

long int sum_of_a_row(const std::vector<int>& row) {
    return std::accumulate(row.begin(), row.end(), 0);
}

long int sum_of_a_column(const std::vector<std::vector<int>>& farm, int column) {
    return std::accumulate(farm.begin(), farm.end(), 0,
                           [column](long int sum, const std::vector<int>& row) { return sum + row[column]; });
}

long int find_max_row(const std::vector<std::vector<int>>& farm, int rowCount, int& rowIndex) {
    auto maxRow = std::max_element(farm.begin(), farm.end(),
                                   [](const std::vector<int>& row1, const std::vector<int>& row2) {
                                       return sum_of_a_row(row1) < sum_of_a_row(row2);
                                   });

    rowIndex = maxRow - farm.begin();
    return sum_of_a_row(*maxRow);
}

long int find_max_column(const std::vector<std::vector<int>>& farm, int columnCount, int& columnIndex) {
    auto maxColumn = std::max_element(farm[0].begin(), farm[0].end(),
                                      [&farm, columnCount](int column1, int column2) {
                                          return sum_of_a_column(farm, column1) < sum_of_a_column(farm, column2);
                                      });

    columnIndex = maxColumn - farm[0].begin();
    return sum_of_a_column(farm, *maxColumn);
}

void harvest_a_row(std::vector<std::vector<int>>& farm, int rowIndex, int columnCount) {
    std::fill(farm[rowIndex].begin(), farm[rowIndex].end(), 0);
}

void harvest_a_column(std::vector<std::vector<int>>& farm, int columnIndex, int rowCount) {
    for (int i = 0; i < rowCount; i++)
        farm[i][columnIndex] = 0;
}

long int find_most_profitable(int rowCount, int columnCount, std::vector<std::vector<int>>& farm, int numOfMoves) {
    int maxRow, maxColumn, rowIndex, columnIndex;
    long int harvested = 0;

    for (int move = 0; move < numOfMoves; move++) {
        maxRow = find_max_row(farm, rowCount, rowIndex);
        maxColumn = find_max_column(farm, columnCount, columnIndex);

        if (maxRow > maxColumn) {
            harvested += maxRow;
            harvest_a_row(farm, rowIndex, columnCount);
        } else {
            harvested += maxColumn;
            harvest_a_column(farm, columnIndex, rowCount);
        }
    }

    return harvested;
}

std::vector<std::vector<int>> get_input(int rowCount, int columnCount) {
    std::vector<std::vector<int>> result(rowCount, std::vector<int>(columnCount));

    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < columnCount; j++)
            std::cin >> result[i][j];

    return result;
}

int main() {
    int rowCount, columnCount;
    std::cin >> rowCount >> columnCount;

    std::vector<std::vector<int>> farm = get_input(rowCount, columnCount);

    long int harvested = find_most_profitable(rowCount, columnCount, farm, NUM_OF_MOVES);

    std::cout << harvested << std::endl;
    return 0;
}
