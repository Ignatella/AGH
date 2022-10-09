#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "matrix_helpers.h"
#include "gsl_helpers.h"

#define I 101
#define N 3

void print_iteration(size_t i, gsl_vector *v)
{
    printf("Iteration i = %lu.   x: (", i);

    for (size_t l = 0; l < v->size; l++)
        printf("%.3f   ", v_get(v, l));

    printf("\b\b\b)\n");
}

int main()
{
    int sig = 2;
    gsl_matrix *A = read_matrix_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_5/2/assets/matrix_A.txt", N, N);
    gsl_vector *b = read_vector_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_5/2/assets/matrix_b.txt", N);
    gsl_vector *x = gsl_vector_calloc(N);
    double w = 1.5;

    for (size_t k = 0; k < I; k++)
    {
        for (size_t i = 0; i < N; i++)
        {
            double newX = 0;

            newX += v_get(b, i);

            for (size_t j = 0; j < N; j++)
            {
                if (j != i)
                    newX -= m_get(A, i, j) * v_get(x, j);
            }

            newX = newX * w / m_get(A, i, i);

            newX += (1 - w) * v_get(x, i);

            v_set(x, i, newX);
        }

        if (k % 10 == 0)
            print_iteration(k, x);
    }

    gsl_matrix_free(A);
    gsl_vector_free(b);
    gsl_vector_free(x);
    return 0;
}
