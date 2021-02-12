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

		Solution solve() const override;

		ull getNumerator() const;
		ull getDenominator() const;

		//	True if the expression is positive (not negative and not zero).
		bool isPositive();

		//	True if the expression is negative.
		bool isNegative();

		void setNumerator(ll n);
		void setDenominator(ll d);


	private:
		//	Setup method which converts the ll's to ull's, while keeping
		//	track of the sign of the final expression.
		void _setup(ll numerator, ll denominator);

		ull _numerator;
		ull _denominator;
		bool _negative;

	};
}
