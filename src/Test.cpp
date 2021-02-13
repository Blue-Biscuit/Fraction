#include "Solution/Solution.h"

#include "Fraction.h"

#include <iostream>

int main()
{
	cc::Fraction x(1, 2);
	double y = .5;
	cc::Solution result = x / y;

	std::cout << result.getVal() << std::endl;
}