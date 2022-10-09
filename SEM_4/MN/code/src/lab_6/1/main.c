#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "matrix_helpers.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"

#define N 20
#define I 500

#define e_vec                    \
    {                            \
        0.1, 0.01, 0.001, 0.0001 \
    }
#define e_vec_count 4

void print_iteration(FILE *fp, size_t i, gsl_vector *v);

int main()
{
    gsl_matrix *A = read_matrix_from_file("src/lab_6/1/assets/matrix_A.txt", N, N);
    gsl_vector *b = read_vector_from_file("src/lab_6/1/assets/vector_B.txt", N);
    gsl_vector *x = gsl_vector_calloc(N);
    gsl_vector *x1 = gsl_vector_calloc(N);
    gsl_vector *dx = gsl_vector_calloc(N);

    char res[61];
    snprintf(res, 61, "src/lab_6/_results/Gaussa–Seidela/%dx%d/output/output.txt", N, N);

    FILE *fp = fopen(res, "w+");

    if (fp == NULL)
    {
        printf("File can't be opened\n");
        exit(1);
    }

    fprintf(fp, "Metoda Gaussa–Seidela\n");

    if (!linalg_is_diagonally_dominant(A))
    {
        fprintf(fp, "Macierz musi byc dominujaca przekatniowo!\n");
        return -1;
    }

    int exit = 0;

    double e_v[e_vec_count] = e_vec;
    int e_v_start_i = 0;

    // Gaussa–Seidela
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

            v_set(x1, k, newX);
        }

        if (i % 10 == 0)
            print_iteration(fp, i, x);

        // check e
        for (size_t ei = e_v_start_i; ei < e_vec_count; ei++)
        {
            double e = e_v[ei];

            for (size_t k = 0; k < N; k++)
            {
                v_set(dx, k, v_get(x1, k));
            }

            gsl_vector_sub(dx, x);

            if (gsl_blas_dnrm2(dx) <= e * gsl_blas_dnrm2(x))
            {
                fprintf(fp, "Possible exit due to e: %g, iteration: %ld\n", e, i + 1);
                ++e_v_start_i;
            }

            if (e_v_start_i == e_vec_count)
            {
                fprintf(fp, "More presicion is not nedeed. Exit.\n");
                exit = 1;
                break;
            }
        }

        // copyt x1 to x
        for (size_t k = 0; k < N; k++)
        {
            v_set(x, k, v_get(x1, k));
        }

        if (exit)
            break;
    }

    fprintf(fp, "\n\nSolution:\n");
    print_vector(fp, x);

    fclose(fp);

    gsl_matrix_free(A);
    gsl_vector_free(b);
    gsl_vector_free(x);
    gsl_vector_free(x1);
    gsl_vector_free(dx);

    return 0;
}

void print_iteration(FILE *fp, size_t i, gsl_vector *v)
{
    fprintf(fp, "Iteration i = %lu.   x: (", i);

    for (size_t l = 0; l < v->size; l++)
        fprintf(fp, "%.3f   ", v_get(v, l));

    fprintf(fp, "\b\b\b)\n");
}