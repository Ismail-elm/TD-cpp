#include <iostream>
#include "Matrix.h"

int main() {
    MatrixNumerical<double> A({{2, 1, 3}, {0, -1, 4}, {1, 2, 5}});
    MatrixNumerical<double> B({{1, 0, 2}, {3, 1, 0}, {0, 4, 1}});

    std::cout << "A =\n";  A.Display();
    std::cout << "B =\n";  B.Display();
    std::cout << "det(A) = " << A.getDeterminant() << "\n\n";

    std::cout << "A + B =\n"; (A + B).Display();
    std::cout << "A - B =\n"; (A - B).Display();
    std::cout << "A * B =\n"; (A * B).Display();

    auto inv = A.getInverse();
    std::cout << "A^-1 =\n"; inv.Display();
    std::cout << "A * A^-1 =\n"; (A * inv).Display();

    std::cout << "A / B =\n"; (A / B).Display();
    std::cout << "I4 =\n"; MatrixNumerical<int>::getIdentity(4).Display();

    MatrixNumerical<int> M({{1, 2, 3, 4}, {0, 1, 5, 6}, {2, 0, 1, 7}, {1, 1, 0, 1}});
    std::cout << "det(M 4x4, int) = " << M.getDeterminant() << "\n";

    try {
        MatrixNumerical<double>({{1, 2}, {2, 4}}).getInverse();
    } catch (const std::exception& e) {
        std::cout << "Erreur attendue : " << e.what() << "\n";
    }
    return 0;
}
