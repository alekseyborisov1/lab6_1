#pragma once
#include "stdafx.h"

//�����������
double acosh(double num);

//���������
double asinh(double num);

//������
template <typename T> int sgn(T val);

//����� ������������ �����
std::ostream & operator << (std::ostream &stream, complex const & num);

//������� ������� ����������� ���������
EquationRoots3 Solve3(double a, double b, double c, double d);