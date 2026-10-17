#include <iostream>

#include "MatrixBase.h"
#include "MatrixNumerical.h"

int main() {
    std::cout << "=== MATRIX BASE ===" << std::endl;
    MatrixBase<int> base(2, 2);
    base.addElement(0, 0, 1);
    base.addElement(0, 1, 2);
    base.addElement(1, 0, 3);
    base.addElement(1, 1, 4);
    base.Display();

    std::cout << "Lignes : " << base.getRows() << std::endl;
    std::cout << "Colonnes : " << base.getCols() << std::endl;
    std::cout << "Element [1][0] : " << base.getElement(1, 0) << std::endl;

    MatrixNumerical<double> matrixA({{4, 7}, {2, 6}});
    MatrixNumerical<double> matrixB({{1, 2}, {3, 4}});

    std::cout << "\n=== MATRICE A ===" << std::endl;
    matrixA.Display();

    std::cout << "\n=== MATRICE B ===" << std::endl;
    matrixB.Display();

    std::cout << "\nDeterminant de A : "
              << matrixA.getDeterminant() << std::endl;

    std::cout << "\n=== A + B ===" << std::endl;
    MatrixNumerical<double> sum = matrixA + matrixB;
    sum.Display();

    std::cout << "\n=== A - B ===" << std::endl;
    MatrixNumerical<double> difference = matrixA - matrixB;
    difference.Display();

    std::cout << "\n=== A * B ===" << std::endl;
    MatrixNumerical<double> product = matrixA * matrixB;
    product.Display();

    std::cout << "\n=== INVERSE DE A ===" << std::endl;
    MatrixNumerical<double> inverse = matrixA.getInverse();
    inverse.Display();

    std::cout << "\n=== A / B ===" << std::endl;
    MatrixNumerical<double> division = matrixA / matrixB;
    division.Display();

    std::cout << "\n=== IDENTITE 3 x 3 ===" << std::endl;
    MatrixNumerical<double> identity =
        MatrixNumerical<double>::getIdentity(3);
    identity.Display();

    return 0;
}
