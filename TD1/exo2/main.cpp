#include <iostream>
#include "Complex2D.h"

int main() {
    Complex2D a(3, 4);
    Complex2D b(1, 2);

    // Addition
    Complex2D addition = a + b;
    std::cout << "Addition : "
              << addition.getReal() << " + "
              << addition.getImag() << "i" << std::endl;

    // Soustraction
    Complex2D subtraction = a - b;
    std::cout << "Soustraction : "
              << subtraction.getReal() << " + "
              << subtraction.getImag() << "i" << std::endl;

    // Multiplication
    Complex2D multiplication = a * b;
    std::cout << "Multiplication : "
              << multiplication.getReal() << " + "
              << multiplication.getImag() << "i" << std::endl;

    // Division
    Complex2D division = a / b;
    std::cout << "Division : "
              << division.getReal() << " + "
              << division.getImag() << "i" << std::endl;

    // Constructeur avec une seule valeur
    Complex2D c(5);
    std::cout << "Constructeur (5) : "
              << c.getReal() << " + "
              << c.getImag() << "i" << std::endl;

    // Constructeur par copie
    Complex2D d(a);
    std::cout << "Copie de a : "
              << d.getReal() << " + "
              << d.getImag() << "i" << std::endl;

    // Comparaison supérieure
    std::cout << "a > b : "
              << (a.compare_superior(b) ? "true" : "false")
              << std::endl;

    // Comparaison inférieure
    std::cout << "a < b : "
              << (a.compare_inferior(b) ? "true" : "false")
              << std::endl;

    return 0;
}