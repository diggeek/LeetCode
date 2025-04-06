#include "problems.hpp"

void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::unordered_set<int> zero_rows, zero_column;
    for (size_t i=0; i<matrix.size(); ++i) {
        for (size_t j=0; j<matrix[i].size(); ++j) {
            if (matrix[i][j] == 0) {
                zero_rows.insert(i);
                zero_column.insert(j);
            }
        }
    }

    for (auto row : zero_rows) {
        std::fill(matrix[row].begin(), matrix[row].end(), 0);
    }

    for (auto column : zero_column) {
        for (size_t row=0; row<matrix.size(); ++row) {
            matrix[row][column] = 0;
        }
    }

}
