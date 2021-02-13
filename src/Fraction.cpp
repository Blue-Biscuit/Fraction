#include "Fraction.h"

cc::ull __gcd_helper(cc::ull x, cc::ull y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return __gcd_helper(y, x % y);
	}
}

cc::ull __lcm_helper(cc::ull x, cc::ull y)
{
	return (x * y) / __gcd_helper(x, y);
}


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

cc::Fraction cc::Fraction::multiplicativeInverse() const
{
	return Fraction(_denominator, _numerator);
}

bool cc::Fraction::undefined() const
{
	return _denominator == 0;
}

cc::Fraction cc::Fraction::operator+(const Fraction& o) const
{
	//	1. Error check; we can't add with any denominators of zero.
	//	2. Find the common denominator between the two numbers.
	//	3. Adjust the numerator based upon the new denominator.
	//	4. Perform the sum, making sure to account for the sign of the fractions.

	//	1. Error check; we can't add with any denominators of zero.
	if (undefined() || o.undefined())
	{
		return Fraction(0, 0);
	}

	//	2. Find the common denominator between the two numbers.
	ull den = __lcm_helper(_denominator, o._denominator);

	//	3. Adjust the numerator based upon the new denominator.
	ll numx = _numerator * (den / _denominator);
	ll numy = o._numerator * (den / o._denominator);

	//	4. Perform the sum, making sure to account for the sign of the fractions.
	if (isNegative())
	{
		numx *= -1;
	}
	if (o.isNegative())
	{
		numy *= -1;
	}

	return Fraction(numx + numy, den);
}

cc::Fraction cc::Fraction::operator*(const Fraction& o) const
{
	ll numx = _numerator;
	ll numy = o._numerator;
	if (isNegative())
	{
		numx *= -1;
	}
	if (o.isNegative())
	{
		numy *= -1;
	}

	return Fraction(numx * numy, _denominator * o._denominator);
}

cc::Fraction cc::Fraction::operator/(const Fraction& o) const
{
	return *this * o.multiplicativeInverse();
}

cc::Fraction cc::Fraction::operator-(const Fraction& o) const
{
	return *this + (-o);
}

cc::Fraction cc::Fraction::operator-() const
{
	return Fraction(-(ll)_numerator, _denominator);
}

cc::Solution cc::Fraction::operator+(double x) const
{
	return solve() + x;
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

cc::ull cc::Fraction::getNumerator() const
{
	return _numerator;
}

cc::ull cc::Fraction::getDenominator() const
{
	return _denominator;
}

bool cc::Fraction::isPositive() const
{
	return !_negative && _numerator != 0;
}

bool cc::Fraction::isNegative() const
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

const cc::Fraction cc::Fraction::PI = cc::Fraction(355, 113);
const cc::Fraction cc::Fraction::E = cc::Fraction(106, 39);

cc::Solution cc::operator+(double x, const Fraction& y)
{
	return y + x;
}
