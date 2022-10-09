#include "vecmat.h"

Matrix::Matrix()
{
	data[0][0] = 0.0; data[0][1] = 0.0; data[0][2] = 0.0;
	data[1][0] = 0.0; data[1][1] = 0.0; data[1][2] = 0.0;
	data[2][0] = 0.0; data[2][1] = 0.0; data[2][2] = 0.0;
}

void Matrix::Print(void)
{
	printf("\n|%2.3lf,%2.3lf,%2.3lf|\n", data[0][0], data[0][1], data[0][2]);
	printf("|%2.3lf,%2.3lf,%2.3lf|\n", data[1][0], data[1][1], data[1][2]);
	printf("|%2.3lf,%2.3lf,%2.3lf|\n", data[2][0], data[2][1], data[2][2]);
}

Matrix Matrix::operator* (const Matrix gMatrix)
{
	int i, j, k;
	Matrix tmp;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			tmp.data[i][j] = 0.0;
			for (k = 0; k < 3; k++)
				tmp.data[i][j] = tmp.data[i][j] + (data[i][k] * gMatrix.data[k][j]);
		}
	return tmp;
}
