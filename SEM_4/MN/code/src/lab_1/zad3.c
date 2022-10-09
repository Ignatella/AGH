#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

int main()
{ 
    int n = 4, m = 4;

    gsl_matrix *A = gsl_matrix_calloc(n, m);
    gsl_vector *b = gsl_vector_calloc(n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            gsl_matrix_set(A, i, j, 1 / (double)(1 + i + j));
            printf("%f ", gsl_matrix_get(A, i, j));
        }

        printf("\n");
        gsl_vector_set(b, i, 2 * i);
    }

    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%f\n", gsl_vector_get(b, i));
    }

    return 0;
}