#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "matrix_helpers.h"
#include "gsl_helpers.h"
#include "wolfram_alpha_helpers.h"
#include "linalg_helpers.h"

#define N 3
#define I 11

void print_iteration(size_t i, gsl_vector *v)
{
    printf("Iteration i = %lu.   x: (", i);

    for (size_t l = 0; l < v->size; l++)
        printf("%.3f   ", v_get(v, l));

    printf("\b\b\b)\n");
}

int main()
{
    gsl_matrix *A = read_matrix_from_file("assets/matrix_A.txt", N, N);
    gsl_vector *b = read_vector_from_file("assets/matrix_b.txt", N);
    gsl_vector *x = gsl_vector_calloc(N);
    gsl_vector *x1 = gsl_vector_calloc(N);
    gsl_vector *x2 = gsl_vector_calloc(N);

    printf("Metoda Gaussa-Seidlea\n");

    for (size_t i = 0; i < I; i++)
    {
        for (size_t k = 0; k < N; k++)
        {
            double sum = 0;
            for (size_t j = 0; j < N; j++)
            {
                if (j == k)
                    continue;

                sum += m_get(A, k, j) * v_get(x1, j);
            }

            double newX = (v_get(b, k) - sum) / m_get(A, k, k);

            v_set(x1, k, newX);
        }

        print_iteration(i, x1);
    }

    printf("Metoda Jacobiego\n");

    for (size_t i = 0; i < I; i++)
    {
        for (size_t k = 0; k < N; k++)
        {
            double sum = 0;
            for (size_t j = 0; j < N; j++)
            {
                if (j == k)
                    continue;

                sum += m_get(A, k, j) * v_get(x, j);
            }

            double newX = (v_get(b, k) - sum) / m_get(A, k, k);

            v_set(x2, k, newX);
        }

        for (size_t i = 0; i < N; i++)
        {
            v_set(x, i, v_get(x2, i));
        }

        print_iteration(i, x2);
    }

    gsl_matrix_free(A);
    gsl_vector_free(b);
    gsl_vector_free(x);
    gsl_vector_free(x1);
    gsl_vector_free(x2);

    return 0;
}
