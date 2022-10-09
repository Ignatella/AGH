#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

/**
 * 
 * LU decomposition 1938
 * A = LU
 * LUx = b 
 * L = macierz trojkatna dolna
 * U = macierz trojkatna gorna
 * 
 * LU: sprowadza sie do rozwiazania ukladu trojkatnego
 * 1) Ly = b
 * 2) Ux = y 
 * 
 * l_11 * y_1 = 
 */

int main()
{ 
    int n = 4, m = 4;

    gsl_matrix *A = gsl_matrix_calloc(n, m);
    gsl_vector *b = gsl_vector_calloc(n);
    
    double x[n];
    double sum;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j > i) 
                continue;

            gsl_matrix_set(A, i, j, 1 / (double)(1 + i + j));
        }

        gsl_vector_set(b, i, 2 * i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%f ", gsl_matrix_get(A, i, j));

        printf("\n");
    }

    printf("\n\n");
    

    for (int i = 0; i < n; i++)
        printf("%f\n", gsl_vector_get(b, i));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i-1; j++)
        {
            sum += gsl_matrix_get(A, i, j) * gsl_vector_get(b, i);
        }

        x[i] = (gsl_vector_get(b, i) - sum) / gsl_matrix_get(A, i, i);
    }


    printf("\n\n");
    printf("Solutions: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%f\n", x[i]);
    }

    return 0;
}