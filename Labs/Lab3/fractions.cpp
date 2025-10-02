#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    //zero handling
    if (denominator == 0) {
        std::cout << "Error: Denominator cannot be 0, defaulting to 1" << std::endl;
        _denominator = 1;
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
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    return Fraction(0, 1);
}

void fractions::Fraction::simplify()
{
    int simplified = gcd(abs(_numerator), (abs(_denominator)));
    _numerator /= simplified;
    _denominator /= simplified;
}

int fractions::Fraction::gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    if (_numerator == frac._numerator && _denominator == frac._denominator) return true;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}