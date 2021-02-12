#include "Fraction.h"

cc::Fraction::Fraction(ll numerator, ll denominator)
{
	_setup(numerator, denominator);
}

cc::Fraction::Fraction(ll numerator):
	Fraction(numerator, 1)
{
}

cc::Fraction::Fraction():
	Fraction(0)
{
}

cc::Solution cc::Fraction::solve() const
{
	return Solution();
}

cc::ull cc::Fraction::getNumerator() const
{
	return _numerator;
}

cc::ull cc::Fraction::getDenominator() const
{
	return _denominator;
}

bool cc::Fraction::isPositive()
{
	return !_negative && _numerator != 0;
}

bool cc::Fraction::isNegative()
{
	return _negative;
}

void cc::Fraction::setNumerator(ll n)
{
	_setup(n, _denominator);
}

void cc::Fraction::setDenominator(ll d)
{
	_setup(_numerator, d);
}

void cc::Fraction::_setup(ll numerator, ll denominator)
{
	//	Find the final sign of the expression through multiplication.
	_negative = numerator * denominator < 0;

	//	Find the absolute value of the numerator and denominator and set it to our private fields.
	if (numerator < 0)
	{
		numerator = -numerator;
	}
	if (denominator < 0)
	{
		denominator = -denominator;
	}

	_numerator = numerator;
	_denominator = denominator;
}
