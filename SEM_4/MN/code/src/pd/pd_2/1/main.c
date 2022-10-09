#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"

#include <matrix_helpers.h>
#include <gsl_helpers.h>

#define N 3
#define I 101

int is_diagonally_dominant(gsl_matrix *A)
{
    for (size_t i = 0; i < A->size1; i++)
    {
        double Aii = m_get(A, i, i);
        double sum = 0;

        for (size_t j = 0; j < A->size2; j++)
        {
            if (i == j)
                continue;

            sum += abs(m_get(A, i, j));
        }

        if (abs(Aii) < sum)
            return 0;
    }
    return 1;
}

void print_iteration(size_t i, gsl_vector *v);

int main()
{
    gsl_matrix *A = read_matrix_from_file("src/pd/pd_2/1/assets/A_matrix.txt", N, N);
    gsl_vector *b = read_vector_from_file("src/pd/pd_2/1/assets/b_vector.txt", N);
    gsl_vector *x = gsl_vector_calloc(N);

    printf("Macier wspolczynnikow A:\n");
    print_matrix(A);

    printf("Macier wyrazow wolnych b:\n");
    print_vector(b);

    if (!is_diagonally_dominant(A))
    {
        printf("Matrix should be diagonally dominant!\n\n");
        exit(EXIT_FAILURE);
    }

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

            v_set(x, k, newX);
        }

        if (i % 10 == 0)
            print_iteration(i, x);
    }

    printf("\n");

    printf("Rozwiązanie:\n");

    print_vector(x);

    gsl_matrix_free(A);
    gsl_vector_free(b);
    gsl_vector_free(x);

    return 0;
}

void print_iteration(size_t i, gsl_vector *v)
{
    printf("Iteration i = %lu.   x: (", i);

    for (size_t l = 0; l < v->size; l++)
        printf("%.3f   ", v_get(v, l));

    printf("\b\b\b)\n");
}
