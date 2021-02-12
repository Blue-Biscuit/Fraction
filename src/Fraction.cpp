#include "Fraction.h"

cc::Fraction::Fraction(ll numerator, ll denominator):
	_numerator(numerator), _denominator(denominator)
{
}

cc::Fraction::Fraction(ll numerator):
	Fraction(numerator, 1)
{
}

cc::Fraction::Fraction():
	Fraction(0)
{
}

cc::Fraction cc::Fraction::operator+(const Fraction&)
{
	return Fraction();
}

cc::Fraction cc::Fraction::operator-(const Fraction&)
{
	return Fraction();
}

cc::Solution cc::Fraction::solve() const
{
	return Solution();
}

cc::ll cc::Fraction::getNumerator() const
{
	return _numerator;
}

cc::ll cc::Fraction::getDenominator() const
{
	return _denominator;
}

void cc::Fraction::setNumerator(ll n)
{
	_numerator = n;
}

void cc::Fraction::setDenominator(ll d)
{
	_denominator = d;
}
