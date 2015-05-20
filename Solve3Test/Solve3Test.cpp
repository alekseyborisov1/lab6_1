// Solve3Test.cpp: определяет точку входа для консольного приложения.
//
//для проверки результатов использован калькулятор http://www.1728.org/cubic.htm c точностью 2 знаков после запятой
#include "stdafx.h"
#include "../Solve3/QubicEquation.h"
#include <cmath>

struct EquationFixture
{
	EquationRoots3 result;
};

complex RoundNum(complex num)
{
	double x = boost::math::round(num.real() * 100.0) / 100.0;
	double y = boost::math::round(num.imag() * 100.0) / 100.0;

	return complex(x, y);
}
double RoundNum(double num)
{
	num = boost::math::round(num * 100.0) / 100.0;

	return num;
}

BOOST_FIXTURE_TEST_SUITE(Solve3FunctionTest, EquationFixture)

BOOST_AUTO_TEST_CASE(When_S_IsEqualZero)
{
	result = Solve3(1, 1, -1, -1);

	BOOST_CHECK_EQUAL(result.numRoots, 2);
	BOOST_CHECK_EQUAL(RoundNum(result.roots[0]), complex(-1.0, 0));
	BOOST_CHECK_EQUAL(RoundNum(result.roots[1]), complex(1.0, 0));
}

BOOST_AUTO_TEST_CASE(When_S_IsMoreZero)
{
	result = Solve3(3, 4, -7, 2);

	BOOST_CHECK_EQUAL(result.numRoots, 3);
	BOOST_CHECK_EQUAL(RoundNum(result.roots[0]), complex(-2.41, 0));
	BOOST_CHECK_EQUAL(RoundNum(result.roots[1]), complex(0.67, 0));
	BOOST_CHECK_EQUAL(RoundNum(result.roots[2]), complex(0.41, 0));
}

BOOST_AUTO_TEST_CASE(When_S_IsLessZero_and_Q_IsMoreZero)
{
	result = Solve3(6, 8, 1, 2);

	BOOST_CHECK_EQUAL(result.numRoots, 3);
	BOOST_CHECK_EQUAL(RoundNum(result.roots[0]), complex(-1.39, 0));
	BOOST_CHECK_EQUAL(RoundNum(result.roots[1]), complex(0.03, 0.49));
	BOOST_CHECK_EQUAL(RoundNum(result.roots[2]), complex(0.03, -0.49));
}

BOOST_AUTO_TEST_CASE(When_S_IsLessZero_and_Q_IsLessZero)
{
	result = Solve3(1, 1, 2, 4);

	BOOST_CHECK_EQUAL(result.numRoots, 3);
	BOOST_CHECK_EQUAL(RoundNum(result.roots[0]), complex(-1.48, 0));
	BOOST_CHECK_EQUAL(RoundNum(result.roots[1]), complex(0.24, 1.63));
	BOOST_CHECK_EQUAL(RoundNum(result.roots[2]), complex(0.24, -1.63));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(AreasinusFunctionTest)
{
	BOOST_CHECK_EQUAL(asinh(0.0), 0.0);
	BOOST_CHECK_EQUAL(RoundNum(asinh(1.0)), 0.88);
}

BOOST_AUTO_TEST_CASE(AreacosinusFunctionTest)
{
	BOOST_CHECK_EQUAL(boost::math::isnan(acosh(0.0)), true);
	BOOST_CHECK_EQUAL(RoundNum(acosh(1.0)), 0.0);
}

BOOST_AUTO_TEST_CASE(TestOutputFunction)
{
	{
		complex num(0.1, 0.12);
		std::ostringstream stream;
		stream << num;
		std::string str = stream.str();

		BOOST_CHECK_EQUAL(str, "0.1 + 0.12i");
	}
}