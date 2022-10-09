//Extremely simple vector and matrix classes by Janusz Malinowski. 
#pragma once

#include <stdio.h>

class Matrix
{
public:
	double data[3][3];
	Matrix();
	void Print(void);
	Matrix operator*(const Matrix);
};

