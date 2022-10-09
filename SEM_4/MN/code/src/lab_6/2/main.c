#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "matrix_helpers.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"
#include "math.h"

#define N 20
#define I 10000

#define w_max 1.6
#define w_step 0.05
#define w_min 0.2

#define e_vec                    \
    {                            \
        0.1, 0.01, 0.001, 0.0001 \
    }
#define e_vec_count 4

#define plot_for_e 0.0001

#define show_data_for_plot 1

void print_iteration(FILE *fp, size_t i, gsl_vector *v);

int main()
{
    gsl_matrix *A = read_matrix_from_file("src/lab_6/2/assets/matrix_A.txt", N, N);
    gsl_vector *b = read_vector_from_file("src/lab_6/2/assets/vector_B.txt", N);

    gsl_vector *rounds_for_plot = gsl_vector_calloc((w_max - w_min) / w_step + 1);

    for (float wi = w_min; wi <= w_max; wi += w_step)
    {
        char res[48];
        snprintf(res, 48, "src/lab_6/_results/SOR/%dx%d/output/w_%0.2f.txt", N, N, wi);

        FILE *fp = fopen(res, "w+");

        if (fp == NULL)
        {
            printf("File can't be opened\n");
            exit(1);
        }

        gsl_vector *x = gsl_vector_calloc(N);
        gsl_vector *x1 = gsl_vector_calloc(N);
        gsl_vector *dx = gsl_vector_calloc(N);

        double w = wi;

        fprintf(fp, "Metoda SOR\n\n");
        fprintf(fp, "w = %g\n\n", w);

        if (!linalg_is_diagonally_dominant(A))
        {
            fprintf(fp, "Macierz musi byc dominujaca przekatniowo!\n");
            return -1;
        }

        int exit = 0;

        double e_v[e_vec_count] = e_vec;
        int e_v_start_i = 0;

        // SOR
        for (size_t k = 0; k < I; k++)
        {
            for (size_t i = 0; i < N; i++)
            {
                double newX = 0;

                newX += v_get(b, i);

                for (size_t j = 0; j < N; j++)
                {
                    if (j < i)
                        newX -= m_get(A, i, j) * v_get(x1, j);

                    if (j > i)
                        newX -= m_get(A, i, j) * v_get(x, j);
                }

                newX = newX * w / m_get(A, i, i);

                newX += (1 - w) * v_get(x, i);

                v_set(x1, i, newX);
            }

            if (k % 10 == 0)
                print_iteration(fp, k, x);

            // check e
            for (size_t ei = e_v_start_i; ei < e_vec_count; ei++)
            {
                double e = e_v[ei];

                for (size_t i = 0; i < N; i++)
                {
                    v_set(dx, i, v_get(x1, i));
                }

                gsl_vector_sub(dx, x);

                if (gsl_blas_dnrm2(dx) <= e * gsl_blas_dnrm2(x))
                {
                    if (e == plot_for_e)
                    {
                        int i = round((wi - w_min) / w_step);
                        v_set(rounds_for_plot, i, k + 1);
                    }

                    fprintf(fp, "Possible exit due to e: %g, iteration: %ld\n", e, k + 1);
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

        gsl_vector_free(x);
        gsl_vector_free(x1);
        gsl_vector_free(dx);

        fclose(fp);
    }

#pragma region Show data for plot
    printf("DATA FOR PLOT:\n\n");

    printf("W\n");
    if (show_data_for_plot)
    {
        for (float wi = w_min; wi <= w_max; wi += w_step)
        {
            printf("%.2f, ", wi);
        }

        printf("\n\nITERACJE\n");

        for (float wi = w_min; wi <= w_max; wi += w_step)
        {
            int i = round((wi - w_min) / w_step);
            printf("%d, ", (int)v_get(rounds_for_plot, i));
        }
    }

    printf("\n");
#pragma endregion

    gsl_matrix_free(A);
    gsl_vector_free(b);
    gsl_vector_free(rounds_for_plot);

    return 0;
}

void print_iteration(FILE *fp, size_t i, gsl_vector *v)
{
    fprintf(fp, "Iteration i = %lu.   x: (", i);

    for (size_t l = 0; l < v->size; l++)
        fprintf(fp, "%.5f   ", v_get(v, l));

    fprintf(fp, "\b\b\b)\n");
}