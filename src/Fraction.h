#pragma once

//	STDLIB INCLUDES

//	LIBRARY INCLUDES
#include "Solution/Solvable.h"
#include "Solution/Solution.h"


namespace cc
{
	typedef long long ll;
	typedef unsigned long long ull;


	class Fraction : public Solvable
	{
	public:
		Fraction(ll numerator, ll denominator);
		Fraction(ll numerator);
		Fraction();

	//	METHODS

		//	Gets the multiplicative inverse of the fraction.
		Fraction multiplicativeInverse() const;

		//	True if the fraction is a div by zero.
		bool undefined() const;

	//	MAIN OPERATORS

		//	Addition opeartor for Fractions.
		//
		//	If the add fails, returns 0/0.
		Fraction operator+(const Fraction&) const;

		//	subtraction operator for Fractions.
		//
		//	If the subtract fails, returns 0/0.
		Fraction operator-(const Fraction&) const;

		//	Multiplication opeartor for Fractions.
		Fraction operator*(const Fraction&) const;

		//	Division operator for Fractions.
		Fraction operator/(const Fraction&) const;

		//	negate operator for Fractions.
		Fraction operator-() const;

	//	SECONDARY OPERATORS

		Solution operator+(double) const;
		friend Solution operator+(double, const Fraction&);

		Solution operator-(double) const;
		friend Solution operator-(double, const Fraction&);

		Solution operator*(double) const;
		friend Solution operator*(double, const Fraction&);

		Solution operator/(double) const;
		friend Solution operator/(double, const Fraction&);

	//	OVERRIDES

		//	Gets the approximate solution to the ratio.
		Solution solve() const override;

	//	ACCESSORS

		ull getNumerator() const;
		ull getDenominator() const;

		//	True if the expression is positive (not negative and not zero).
		bool isPositive() const;

		//	True if the expression is negative.
		bool isNegative() const;

		void setNumerator(ll n);
		void setDenominator(ll d);

	//	STATIC CONSTS

		//	A rational approximation for Pi.
		static const Fraction PI;

		//	A ration approximation for Euler's Number.
		static const Fraction E;


	private:
		//	Setup method which converts the ll's to ull's, while keeping
		//	track of the sign of the final expression.
		void _setup(ll numerator, ll denominator);

		ull _numerator;
		ull _denominator;
		bool _negative;

	};



}