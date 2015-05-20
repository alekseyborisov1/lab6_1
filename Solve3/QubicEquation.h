#pragma once
#include "stdafx.h"

//ареакосинус
double acosh(double num);

//ареасинус
double asinh(double num);

//сигнум
template <typename T> int sgn(T val);

//вывод комплексного числа
std::ostream & operator << (std::ostream &stream, complex const & num);

//функция решения кубического уравнения
EquationRoots3 Solve3(double a, double b, double c, double d);