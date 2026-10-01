#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
private:
    double real_;
    double imag_;

public:
    Complex2D();
    Complex2D(double v);
    Complex2D(double real, double imag);
    Complex2D(const Complex2D& other);

    double getReal();
    double getImag();

    Complex2D operator+(const Complex2D& other);
    Complex2D operator-(const Complex2D& other);
    Complex2D operator*(const Complex2D& other);
    Complex2D operator/(const Complex2D& other);

    bool compare_superior(const Complex2D& other);
    bool compare_inferior(const Complex2D& other);
};

#endif