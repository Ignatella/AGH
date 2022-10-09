#include <stdio.h>
#include "math.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"
#include "matrix_helpers.h"

#define N 6

int main(void)
{
    double xa[N] = {-2, -0.5, 0.7, 1.3, 2, 6};
    double ya[N] = {7, 1, 3, -2, 8, 0};

    gsl_vector *x = gsl_vector_calloc(N);
    gsl_vector *y = gsl_vector_calloc(N);

    for (size_t i = 0; i < N; i++)
    {
        v_set(x, i, xa[i]);
        v_set(y, i, ya[i]);
    }

    gsl_matrix *A = gsl_matrix_calloc(N, N);

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            m_set(A, i, j, pow(v_get(x, i), j));
        }
    }

    gsl_vector *a = linalg_solve_LU(A, y);

    print_vector(stdout, a);

    printf("\n\n");

    for (size_t i = 0; i < N; i++)
    {
        double yi = 0;

        for (size_t j = 0; j < N; j++)
        {
            yi += v_get(a, j) * pow(v_get(x, i), j);
        }

        printf("%f\n", yi);
    }

    gsl_vector_free(x);
    gsl_vector_free(y);
    gsl_matrix_free(A);
    gsl_vector_free(a);
}
