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

cc::Solution cc::Fraction::solve() const
{
	if (_denominator == 0)
	{
		return Solution(ExistenceType::Undefined);
	}
	else
	{
		return Solution(_numerator / _denominator);
	}
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
