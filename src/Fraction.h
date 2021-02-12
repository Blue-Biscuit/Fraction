#pragma once

//	STDLIB INCLUDES

//	LIBRARY INCLUDES
#include "Solution/Solvable.h"
#include "Solution/Solution.h"


namespace cc
{
	typedef long long ll;


	class Fraction : public Solvable
	{
	public:
		Fraction(ll numerator, ll denominator);
		Fraction(ll numerator);
		Fraction();

		Fraction operator+(const Fraction&);
		Fraction operator-(const Fraction&);

		Solution solve() const override;

		ll getNumerator() const;
		ll getDenominator() const;

		void setNumerator(ll n);
		void setDenominator(ll d);

	private:
		ll _numerator;
		ll _denominator;

	};
}
