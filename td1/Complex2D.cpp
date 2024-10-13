//
// Created by MEHDI on 10/10/2024.
//


#include "Complex2D.h"

#include <cmath>
#include <iostream>
using namespace std;

Complex2D::Complex2D() : real(0), imag(0) {}

Complex2D::Complex2D(float _re, float _im) {
    real = _re;
    imag = _im;
}

Complex2D::Complex2D(float re_im) {
    real = re_im;
    imag = re_im;
}

Complex2D::Complex2D(const Complex2D &c) {
    real = c.real;
    imag = c.imag;
}

float Complex2D::getReal() const {
    return real;
}

float Complex2D::getImag() const {
    return imag;
}

void Complex2D::setImag(float _im) {
    imag = _im;
}

void Complex2D::setReal(float _re) {
    real = _re;
}

Complex2D Complex2D::operator+(const Complex2D &to_add) const {
    return Complex2D(real + to_add.getReal(), imag + to_add.imag);
}

Complex2D Complex2D::operator*(const Complex2D &to_add) const {
    return Complex2D(
            real * to_add.getReal() - imag * to_add.getImag(),
            real * to_add.getImag() + imag * to_add.getReal()
    );
}

Complex2D operator/(const Complex2D &c1, const Complex2D &c2) {
    float denominator = c2.getReal() * c2.getReal() + c2.getImag() * c2.getImag();
    return Complex2D(
        (c1.getReal() * c2.getReal() + c1.getImag() * c2.getImag()) / denominator,
        (c1.getImag() * c2.getReal() - c1.getReal() * c2.getImag()) / denominator
    );
}



    void Complex2D::print(const string s) const {
        cout << s << ": (" << real << ", " << imag << "i)" << endl;
    }

Complex2D Complex2D::rotation(float angle) const {
    float new_real = real * cos(angle) - imag * sin(angle);
    float new_imag = real * sin(angle) + imag * cos(angle);
    return Complex2D(new_real, new_imag);
}


bool Complex2D::operator>(const Complex2D &c) const {
    return (real * real + imag * imag) > (c.real * c.real + c.imag * c.imag);
}

bool Complex2D::operator<(const Complex2D &c) const {
    return (real * real + imag * imag) < (c.real * c.real + c.imag * c.imag);
}