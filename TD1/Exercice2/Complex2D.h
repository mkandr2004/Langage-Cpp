#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
private:
    double reel;
    double imaginaire;

public:
        Complex2D();
        Complex2D(double r, double i);
        Complex2D(double valeur);
        Complex2D(const Complex2D& autre);

        double getReel() ;

        double getImaginaire() ;

        void setReel(double r);

        void setImaginaire(double i);

        Complex2D operator+(const Complex2D& autre) ;

        Complex2D operator-(const Complex2D& autre) ;

        Complex2D operator*(const Complex2D& autre) ;

        Complex2D operator/(const Complex2D& autre) ;

        bool operator<(const Complex2D& autre) ;

        bool operator>(const Complex2D& autre) ;

        bool operator==(const Complex2D& autre) ;

};

#endif
