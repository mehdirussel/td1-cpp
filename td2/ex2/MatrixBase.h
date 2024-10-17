//
// Created by MEHDI on 11/10/2024.
//

#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class MatrixBase {
protected:
    size_t rows;
    size_t cols;
    vector<vector<T>> data;

public:
    MatrixBase(size_t r, size_t c) : rows(r), cols(c), data(r, vector<T>(c)) {}

    void addElement(T e, size_t r, size_t c) {
        if (r >= rows || c >= cols) {
            throw out_of_range("Index out of range");
        }
        data[r][c] = e;
    }

    T getElement(size_t r, size_t c) const {
        if (r >= rows || c >= cols) {
            throw out_of_range("Index out of range");
        }
        return data[r][c];
    }

    vector<T> getRows(size_t r) const {
        if (r >= rows) {
            throw out_of_range("Index out of range");
        }
        return data[r];
    }

    vector<T> getCols(size_t c) const {
        if (c >= cols) {
            throw out_of_range("Index out of range");
        }
        vector<T> col(rows);
        for (size_t i = 0; i < rows; ++i) {
            col[i] = data[i][c];
        }
        return col;
    }

    void Display() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};
