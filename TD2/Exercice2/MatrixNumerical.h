#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"

template <typename T>
class MatrixNumerical;

template <typename T>
MatrixNumerical<T> getCofactor(
    const MatrixNumerical<T>& matrix,
    size_t removedRow,
    size_t removedCol
);

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical() : MatrixBase<T>() {}

    MatrixNumerical(size_t rows, size_t cols)
        : MatrixBase<T>(rows, cols) {}

    MatrixNumerical(const std::vector<std::vector<T>>& values)
        : MatrixBase<T>(values) {}

    double getDeterminant() const {
        if (this->rows != this->cols) {
            throw std::invalid_argument("Le determinant demande une matrice carree");
        }

        if (this->rows == 0) {
            return 1;
        }

        if (this->rows == 1) {
            return this->data[0][0];
        }

        if (this->rows == 2) {
            return this->data[0][0] * this->data[1][1]
                 - this->data[0][1] * this->data[1][0];
        }

        double determinant = 0;

        for (size_t col = 0; col < this->cols; col++) {
            MatrixNumerical<T> cofactor = getCofactor(*this, 0, col);
            double sign = col % 2 == 0 ? 1 : -1;
            determinant += sign * this->data[0][col]
                         * cofactor.getDeterminant();
        }

        return determinant;
    }

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const {
        if (this->rows != other.getRows() || this->cols != other.getCols()) {
            throw std::invalid_argument("Les matrices doivent avoir la meme taille");
        }

        MatrixNumerical<T> result(this->rows, this->cols);

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                result.addElement(i, j, this->data[i][j] + other.getElement(i, j));
            }
        }

        return result;
    }

    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const {
        if (this->rows != other.getRows() || this->cols != other.getCols()) {
            throw std::invalid_argument("Les matrices doivent avoir la meme taille");
        }

        MatrixNumerical<T> result(this->rows, this->cols);

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                result.addElement(i, j, this->data[i][j] - other.getElement(i, j));
            }
        }

        return result;
    }

    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const {
        if (this->cols != other.getRows()) {
            throw std::invalid_argument("Tailles incompatibles pour la multiplication");
        }

        MatrixNumerical<T> result(this->rows, other.getCols());

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < other.getCols(); j++) {
                T sum = 0;
                for (size_t k = 0; k < this->cols; k++) {
                    sum += this->data[i][k] * other.getElement(k, j);
                }
                result.addElement(i, j, sum);
            }
        }

        return result;
    }

    MatrixNumerical<double> getInverse() const {
        if (this->rows != this->cols) {
            throw std::invalid_argument("L'inverse demande une matrice carree");
        }

        double determinant = getDeterminant();

        if (determinant == 0) {
            throw std::invalid_argument("La matrice n'est pas inversible");
        }

        MatrixNumerical<double> inverse(this->rows, this->cols);

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                MatrixNumerical<T> cofactor = getCofactor(*this, i, j);
                double sign = (i + j) % 2 == 0 ? 1 : -1;
                double value = sign * cofactor.getDeterminant() / determinant;

                // On transpose directement la matrice des cofacteurs.
                inverse.addElement(j, i, value);
            }
        }

        return inverse;
    }

    MatrixNumerical<double> operator/(const MatrixNumerical<T>& other) const {
        MatrixNumerical<double> inverse = other.getInverse();

        if (this->cols != inverse.getRows()) {
            throw std::invalid_argument("Tailles incompatibles pour la division");
        }

        MatrixNumerical<double> result(this->rows, inverse.getCols());

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < inverse.getCols(); j++) {
                double sum = 0;
                for (size_t k = 0; k < this->cols; k++) {
                    sum += this->data[i][k] * inverse.getElement(k, j);
                }
                result.addElement(i, j, sum);
            }
        }

        return result;
    }

    static MatrixNumerical<T> getIdentity(int size) {
        if (size < 0) {
            throw std::invalid_argument("La taille doit etre positive");
        }

        MatrixNumerical<T> identity(size, size);

        for (int i = 0; i < size; i++) {
            identity.addElement(i, i, 1);
        }

        return identity;
    }
};

template <typename T>
MatrixNumerical<T> getCofactor(
    const MatrixNumerical<T>& matrix,
    size_t removedRow,
    size_t removedCol
) {
    MatrixNumerical<T> result(matrix.getRows() - 1, matrix.getCols() - 1);
    size_t resultRow = 0;

    for (size_t i = 0; i < matrix.getRows(); i++) {
        if (i == removedRow) {
            continue;
        }

        size_t resultCol = 0;

        for (size_t j = 0; j < matrix.getCols(); j++) {
            if (j == removedCol) {
                continue;
            }

            result.addElement(resultRow, resultCol, matrix.getElement(i, j));
            resultCol++;
        }

        resultRow++;
    }

    return result;
}

#endif
