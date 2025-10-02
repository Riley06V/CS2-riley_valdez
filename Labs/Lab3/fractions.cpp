#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    //zero handling
    if (denominator == 0) {
        std::cout << "Error: Denominator cannot be 0, defaulting to 1" << std::endl;
        denominator = 1;
    }
    //negative handling
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    _numerator = numerator;
    _denominator = denominator;

    simplify();
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    int num = _numerator * frac._denominator + frac._denominator * frac._numerator;
    int denom = _denominator * frac._denominator;
    return Fraction(num, denom);
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    int num = _numerator * frac._denominator - frac._denominator * frac._numerator;
    int denom = _denominator * frac._denominator;
    return Fraction(num, denom);
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    int num = _numerator * frac._numerator;
    int denom = _denominator * frac._denominator;
    return Fraction(num, denom);
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    int num = _numerator * frac._denominator;
    int denom = _denominator * frac._numerator;
    return Fraction(num, denom);
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    int greatestCommonDiviser = gcd(abs(frac._numerator), abs(frac._denominator));
    int num = frac._numerator / greatestCommonDiviser;
    int denom = frac._denominator / greatestCommonDiviser;
    return Fraction(num, denom);
}

void fractions::Fraction::simplify()
{
    int simplified = gcd(abs(_numerator), (abs(_denominator)));
    _numerator /= simplified;
    _denominator /= simplified;
}

int fractions::Fraction::gcd(int a, int b) //This time without gcd
{
    int minVal = std::min(a, b);
    int gcd = 1;
    for (int i = 1; i <= minVal; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    if (_numerator == frac._numerator && _denominator == frac._denominator) {
        return true;
    } else {
        return false;
    }
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}