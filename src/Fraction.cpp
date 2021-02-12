#include "Fraction.h"

cc::Fraction::Fraction(ll numerator, ll denominator):
	_numerator(numerator), _denominator(denominator)
{
	_sign();
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

void cc::Fraction::_sign()
{
	_negative = _numerator * _denominator < 0;

	if (_numerator < 0)
	{
		_numerator = -_numerator;
	}
	if (_denominator < 0)
	{
		_denominator = -_denominator;
	}
}
