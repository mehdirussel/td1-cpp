//
// Created by MEHDI on 18/10/2024.
//

#pragma once


#include <iostream>
#include <vector>
#include <stdexcept>

#include "MatrixBase.h"

using namespace std;

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}

    T getDeterminant() const {
        if (this->rows != this->cols) {
            throw logic_error("Determinant is not defined for non-square matrices");
        }

        size_t n = this->rows;
        vector<vector<T>> a = this->data;
        T det = 1.0;

        for (size_t i = 0; i < n; i++) {
            size_t pivot = i;
            for (size_t j = i + 1; j < n; j++) {
                if (abs(a[j][i]) > abs(a[pivot][i])) {
                    pivot = j;
                }
            }
            if (pivot != i) {
                swap(a[i], a[pivot]);
                det *= -1;
            }
            if (a[i][i] == 0) {
                return 0;
            }
            det *= a[i][i];
            for (size_t j = i + 1; j < n; j++) {
                T factor = a[j][i] / a[i][i];
                for (size_t k = i + 1; k < n; k++) {
                    a[j][k] -= factor * a[i][k];
                }
            }
        }
        return det;
    }

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw invalid_argument("Matrices dimensions must match for addition");
        }
        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw invalid_argument("Matrices dimensions must match for subtraction");
        }
        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                result.data[i][j] = this->data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const {
        if (this->cols != other.rows) {
            throw invalid_argument("Matrices dimensions must match for multiplication");
        }
        MatrixNumerical<T> result(this->rows, other.cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                result.data[i][j] = T();
                for (size_t k = 0; k < this->cols; ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};