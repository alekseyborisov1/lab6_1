// Solve3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "QubicEquation.h"


int _tmain(int argc, _TCHAR* argv[])
{
	EquationRoots3 result;

	double A, B, C, D;

	std::cout << "A: ";
	std::cin >> A;
	try
	{
		if (A == 0)
		{
			throw std::invalid_argument("Coefficient A cant be zero. Try enter something else.\n");
		}
	}
	catch(std::invalid_argument &e)
	{
		std::cerr << e.what();
		system("pause");
		exit(1);
	}
	
	std::cout << "B: ";
	std::cin >> B;
	std::cout << "C: ";
	std::cin >> C;
	std::cout << "D: ";
	std::cin >> D;

	result = Solve3(A, B, C, D);

	std::cout << result.roots[0] << std::endl;
	std::cout << result.roots[1] << std::endl;
	if (result.numRoots == 3)
	{
		std::cout << result.roots[2] << std::endl;
	}

	system("pause");
	return 0;
}

