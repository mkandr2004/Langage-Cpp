#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase() {
        rows = 0;
        cols = 0;
    }

    MatrixBase(size_t numberRows, size_t numberCols) {
        rows = numberRows;
        cols = numberCols;
        data.resize(rows, std::vector<T>(cols));
    }

    MatrixBase(const std::vector<std::vector<T>>& values) {
        data = values;
        rows = data.size();
        cols = rows == 0 ? 0 : data[0].size();

        for (size_t i = 0; i < rows; i++) {
            if (data[i].size() != cols) {
                throw std::invalid_argument("Les lignes doivent avoir la meme taille");
            }
        }
    }

    void addElement(size_t row, size_t col, T element) {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Position hors de la matrice");
        }
        data[row][col] = element;
    }

    T getElement(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Position hors de la matrice");
        }
        return data[row][col];
    }

    size_t getRows() const {
        return rows;
    }

    size_t getCols() const {
        return cols;
    }

    void Display() const {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

#endif
