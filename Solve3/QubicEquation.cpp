#include "stdafx.h"
#include "QubicEquation.h"


std::ostream & operator << (std::ostream &stream, complex const & num)
{
	if (num.imag() > 0)
	{
		return stream << num.real() << " + " << num.imag() << "i" ;
	}
	else if (num.imag() < 0)
	{
		return stream << num.real() << " - " << -num.imag() << "i" ;
	}
	else
	{
		return stream << num.real();
	}
}

double acosh(double num)
{
	return log(num + sqrt( num * num - 1));
}


double asinh(double num)
{
	return log(num + sqrt( num * num + 1));
}


template <typename T> int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

EquationRoots3 Solve3(double a, double b, double c, double d)
{
	b /= a;
	c /= a;
	d /= a;
	a = b;
	b = c;
	c = d;

	EquationRoots3 structure;

	double Q = (pow(a, 2) - 3 * b) / 9;

	double R = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;

	double S = pow(Q, 3) - pow(R, 2);

	if (S > 0)
	{
		structure.numRoots = 3;

		double phi = (acos(R / pow(Q, 1.5))) / 3;

		structure.roots[0] = -2 * pow(Q, 0.5) * cos(phi) - a / 3;
		structure.roots[1] = -2 * pow(Q, 0.5) * cos(phi + (2 * M_PI) / 3) - a / 3;
		structure.roots[2] = -2 * pow(Q, 0.5) * cos(phi - (2 * M_PI) / 3) - a / 3;

	}
	else if (S < 0)
	{
		structure.numRoots = 3;

		if (Q > 0)
		{
			double phi = (acosh(abs(R) / sqrt(pow(abs(Q), 3)))) / 3;

			structure.roots[0] = -2 * sgn(R) * sqrt(Q) * cosh(phi) - (a / 3);
			structure.roots[1] = complex(sgn(R) * sqrt(Q) * cosh(phi) - (a / 3), sqrt(3) * sqrt(Q) * sinh(phi));
			structure.roots[2] = complex(sgn(R) * sqrt(Q) * cosh(phi) - (a / 3), -sqrt(3) * sqrt(Q) * sinh(phi));
		}
		else if (Q < 0)
		{
			double phi = (asinh(abs(R) / sqrt(pow(abs(Q), 3)))) / 3;

			structure.roots[0] = -2 * sgn(R) * sqrt(abs(Q)) * sinh(phi) - (a / 3);
			structure.roots[1] = complex(sgn(R) * sqrt(abs(Q)) * sinh(phi) - (a / 3), sqrt(3) * sqrt(abs(Q)) * cosh(phi));
			structure.roots[2] = complex(sgn(R) * sqrt(abs(Q)) * sinh(phi) - (a / 3), -sqrt(3) * sqrt(abs(Q)) * cosh(phi));
		}
		else
		{
			structure.numRoots = 2;

			structure.roots[0] = complex(c - (pow(a, 3) / 27), 1 / 3)  - (a / 3);
			double x = structure.roots[0].real();
			structure.roots[1] = complex(-((a + x) / 2) , sqrt(abs((a - 3 * x) * (a + x) - 4 * b)) / 2);
		}
	}
	else
	{
		structure.numRoots = 2;

		structure.roots[0] = sgn(R) * sqrt(Q) - (a / 3);
		structure.roots[1] = -2 * sgn(R) * sqrt(Q) - (a / 3);
	}

	return structure;
}
