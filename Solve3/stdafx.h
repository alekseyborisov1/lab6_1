// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <math.h>
#include <complex>
#define M_PI 3.14159265358979323846

typedef std::complex <double> complex;

struct EquationRoots3
	{
		int numRoots;
		complex roots[3];
	};




// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
