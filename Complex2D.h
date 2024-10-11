//
// Created by MEHDI on 10/10/2024.
//

#pragma once
#include <bits/allocator.h>
#include <bits/char_traits.h>
#include <bits/stringfwd.h>

class Complex2D {

private:
        float real;
        float imag;

    public:
    // constructors
        Complex2D();
        Complex2D(float _re, float _im);
        Complex2D(float re_im);
        Complex2D(const Complex2D &c);
    // getters-setters
        float getReal() const;
        float getImag() const;
        void setReal(float _re);
        void setImag(float _im);

        Complex2D operator+(const Complex2D &to_add) const;

        Complex2D operator*(const Complex2D &to_multiply) const;

    Complex2D operator-(const Complex2D &to_substract) const;

    // operators
        friend Complex2D operator+(const Complex2D &c);
        friend Complex2D operator-(const Complex2D &c);
        friend Complex2D operator*(const Complex2D &c);
    friend Complex2D operator/(const Complex2D &c1, const Complex2D &c2);
        bool operator>(const Complex2D &c) const;
        bool operator<(const Complex2D &c) const;

        void print(std::string s) const;

    // transformations
        Complex2D rotation(float angle) const;

};


