#include <iostream>

#include "Complex2D.h"

int main() {
    double reel1, imaginaire1;
    double reel2, imaginaire2;

    std::cout << "Partie reelle de z1 : ";
    std::cin >> reel1;

    std::cout << "Partie imaginaire de z1 : ";
    std::cin >> imaginaire1;

    std::cout << "Partie reelle de z2 : ";
    std::cin >> reel2;

    std::cout << "Partie imaginaire de z2 : ";
    std::cin >> imaginaire2;

    Complex2D z1(reel1, imaginaire1);
    Complex2D z2(reel2, imaginaire2);

    Complex2D somme = z1 + z2;
    Complex2D difference = z1 - z2;
    Complex2D produit = z1 * z2;
    Complex2D quotient = z1 / z2;

    std::cout << "\nz1 + z2 = (" << somme.getReel()
              << ", " << somme.getImaginaire() << ")" << std::endl;

    std::cout << "z1 - z2 = (" << difference.getReel()
              << ", " << difference.getImaginaire() << ")" << std::endl;

    std::cout << "z1 * z2 = (" << produit.getReel()
              << ", " << produit.getImaginaire() << ")" << std::endl;

    std::cout << "z1 / z2 = (" << quotient.getReel()
              << ", " << quotient.getImaginaire() << ")" << std::endl;

    std::cout << std::boolalpha;
    std::cout << "\nz1 > z2 : " << (z1 > z2) << std::endl;
    std::cout << "z1 < z2 : " << (z1 < z2) << std::endl;
    std::cout << "z1 == z2 : " << (z1 == z2) << std::endl;

    return 0;
}
