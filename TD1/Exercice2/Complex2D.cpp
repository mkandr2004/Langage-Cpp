#include "Complex2D.h"

#include <stdexcept>

Complex2D::Complex2D() : reel(0.0), imaginaire(0.0) {}

Complex2D::Complex2D(double r, double i) : reel(r), imaginaire(i) {}

Complex2D::Complex2D(double valeur) : reel(valeur), imaginaire(valeur) {}

Complex2D::Complex2D(const Complex2D& autre)
    : reel(autre.reel), imaginaire(autre.imaginaire) {}

double Complex2D::getReel() {
    return reel;
}

double Complex2D::getImaginaire() {
    return imaginaire;
}

void Complex2D::setReel(double r) {
    reel = r;
}

void Complex2D::setImaginaire(double i) {
    imaginaire = i;
}

Complex2D Complex2D::operator+(const Complex2D& autre) {
    return Complex2D(reel + autre.reel, imaginaire + autre.imaginaire);
}

Complex2D Complex2D::operator-(const Complex2D& autre) {
    return Complex2D(reel - autre.reel, imaginaire - autre.imaginaire);
}

Complex2D Complex2D::operator*(const Complex2D& autre) {
    return Complex2D(
        reel * autre.reel - imaginaire * autre.imaginaire,
        reel * autre.imaginaire + imaginaire * autre.reel
    );
}

Complex2D Complex2D::operator/(const Complex2D& autre) {
    const double denominateur = autre.reel * autre.reel
                               + autre.imaginaire * autre.imaginaire;
    if (denominateur == 0.0) {
        throw std::invalid_argument("Division par le nombre complexe nul");
    }

    return Complex2D(
        (reel * autre.reel + imaginaire * autre.imaginaire) / denominateur,
        (imaginaire * autre.reel - reel * autre.imaginaire) / denominateur
    );
}


bool Complex2D::operator<(const Complex2D& autre) {
    double module1 = reel * reel + imaginaire * imaginaire;
    double module2 = autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;
    return module1 < module2;
}

bool Complex2D::operator>(const Complex2D& autre) {
    double module1 = reel * reel + imaginaire * imaginaire;
    double module2 = autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;
    return module1 > module2;
}

bool Complex2D::operator==(const Complex2D& autre) {
    return reel == autre.reel && imaginaire == autre.imaginaire;
}
