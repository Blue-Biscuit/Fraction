#include "Solution/Solution.h"

#include "Fraction.h"

#include <iostream>

int main()
{

	cc::Fraction f(1, 2);
	cc::Fraction f2(1, 3);

	cc::Fraction r = f - f2;

	std::cout << "Numerator: " << r.getNumerator() << "\n";
	std::cout << "Denominator: " << r.getDenominator() << std::endl;

}