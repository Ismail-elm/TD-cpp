#include "Complex2D.h"
#include <cmath>

Complex2D::Complex2D() {}

Complex2D::Complex2D(double v)
    : real_(v), imag_(v) {}

Complex2D::Complex2D(double real, double imag)
    : real_(real), imag_(imag) {}

Complex2D::Complex2D(const Complex2D& other)
    : real_(other.real_), imag_(other.imag_) {}

double Complex2D::getReal() {
    return real_;
}

double Complex2D::getImag() {
    return imag_;
}

Complex2D Complex2D::operator+(const Complex2D& other) {
    return Complex2D(real_ + other.real_, imag_ + other.imag_);
}

Complex2D Complex2D::operator-(const Complex2D& other) {
    return Complex2D(real_ - other.real_, imag_ - other.imag_);
}

Complex2D Complex2D::operator*(const Complex2D& other) {
    double real_part = real_ * other.real_ - imag_ * other.imag_;
    double imag_part = real_ * other.imag_ + imag_ * other.real_;

    return Complex2D(real_part, imag_part);
}

Complex2D Complex2D::operator/(const Complex2D& other) {
    double denominator = other.real_ * other.real_ + other.imag_ * other.imag_;

    double real_part =
        (real_ * other.real_ + imag_ * other.imag_) / denominator;

    double imag_part =
        (imag_ * other.real_ - real_ * other.imag_) / denominator;

    return Complex2D(real_part, imag_part);
}

bool Complex2D::compare_superior(const Complex2D& other) {
    double this_module = std::sqrt(real_ * real_ + imag_ * imag_);
    double other_module = std::sqrt(other.real_ * other.real_ +
                                    other.imag_ * other.imag_);

    return this_module > other_module;
}

bool Complex2D::compare_inferior(const Complex2D& other) {
    double this_module = std::sqrt(real_ * real_ + imag_ * imag_);
    double other_module = std::sqrt(other.real_ * other.real_ +
                                    other.imag_ * other.imag_);

    return this_module < other_module;
}