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

		ll getNumerator() const;
		ll getDenominator() const;

		void setNumerator(ll n);
		void setDenominator(ll d);

	private:
		void _sign(ll numerator, ll denominator);

		ull _numerator;
		ull _denominator;
		bool _negative;

	};
}
