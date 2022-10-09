#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include "gsl_helpers.h"
#include "matrix_helpers.h"

#define N 6
#define Rayleigha     // zakomentowac dla metody potegowania wlasnego
#define dnrmx dnrminf // norm that is being used. Possible values are: dnrm1 dnrm2 dnrminf
#define d 0.00001

double dnrm1(gsl_vector *v);
double dnrm2(gsl_vector *v);
double dnrminf(gsl_vector *v);

void print_vector_h(gsl_vector *v);
int vector_equal(gsl_vector *v1, gsl_vector *v2, double delta);

int main(void)
{
    const char *matrix = "src/lab_7/2/assets/matrix_B.txt";

    gsl_matrix *A = read_matrix_from_file(matrix, N, N);
    gsl_matrix *B = read_matrix_from_file(matrix, N, N);

    gsl_vector *wart_wlasne = gsl_vector_alloc(N);
    gsl_matrix *wekt_wlasne = gsl_matrix_alloc(N, N);

    // QR
    {
        gsl_eigen_symmv_workspace *wsp = gsl_eigen_symmv_alloc(N);
        gsl_eigen_symmv(A, wart_wlasne, wekt_wlasne, wsp);
        gsl_eigen_symmv_free(wsp);
        gsl_eigen_symmv_sort(wart_wlasne, wekt_wlasne, GSL_EIGEN_SORT_ABS_DESC);
    }

    // print QR solution
    {
        printf("QR solution: \n");
        for (int i = 0; i < N; i++)
        {
            double wart_i = gsl_vector_get(wart_wlasne, i);
            gsl_vector_view wekt_i = gsl_matrix_column(wekt_wlasne, i);
            printf("%.5lf -> ", wart_i);
            print_vector_h(&wekt_i.vector);
        }
    }

    // Find first value & vector
    {
        printf("\n\nFind first vector: \n");

        gsl_vector *v = gsl_vector_calloc(N);
        for (size_t i = 0; i < N; i++)
            v_set(v, i, i + 1);

        gsl_vector_scale(v, 1. / dnrmx(v));

        int k = 500;
        float r = 0;

        double target_value = v_get(wart_wlasne, 0);
        gsl_vector target_vector = gsl_matrix_column(wekt_wlasne, 0).vector;
        gsl_vector_scale(&target_vector, 1. / dnrmx(&target_vector));

        for (size_t i = 0; i < k; i++)
        {
            gsl_vector *u = gsl_vector_calloc(N);
            gsl_blas_dgemv(CblasNoTrans, 1, B, v, 0, u);

#ifndef Rayleigha
            r = (v_get(u, 0) + v_get(u, N - 1)) / (v_get(v, 0) + v_get(v, N - 1)); // can be different
#endif

#ifdef Rayleigha
            double ddot = 0;
            gsl_blas_ddot(u, v, &ddot);
            r = ddot / dnrm2(v) / dnrm2(v);
#endif

            vector_cpvv(u, v);
            gsl_vector_scale(v, 1. / dnrmx(v));

            gsl_vector_free(u);

            if (fabs(v_get(wart_wlasne, 0) - r) < d && vector_equal(&target_vector, v, d))
            {
                printf("\nResult found within %f error in %ld iterations. Exit.\n\n", d, i + 1);
                break;
            }
        }

        // results
        {
            printf("Vector found = ");
            print_vector_h(v);
            printf("Vector by QR = ");
            print_vector_h(&target_vector);

            printf("\n\nMy wart wlasna = %.5f\n", r);
            printf("QR wart wlasna = %.5f\n\n", target_value);
        }

        gsl_vector_free(v);
    }

    gsl_matrix_free(A);
    gsl_matrix_free(B);
    gsl_matrix_free(wekt_wlasne);
    gsl_vector_free(wart_wlasne);

    return 0;
}

double dnrm1(gsl_vector *v)
{
    double sum = 0;
    for (size_t i = 0; i < v->size; i++)
    {
        sum += v_get(v, i);
    }

    return sum;
}

double dnrm2(gsl_vector *v)
{
    return gsl_blas_dnrm2(v);
}

double dnrminf(gsl_vector *v)
{
    double max = v_get(v, 0);

    for (size_t i = 1; i < v->size; i++)
    {
        if (v_get(v, i) > max)
            max = v_get(v, i);
    }

    return max;
}

void print_vector_h(gsl_vector *v)
{
    printf("[");
    for (size_t i = 0; i < v->size; i++)
    {
        printf("%.5f, ", v_get(v, i));
    }

    if (v->size)
        printf("\b\b");

    printf("]\n");
}

int vector_equal(gsl_vector *v1, gsl_vector *v2, double delta)
{
    if (v1->size != v2->size)
        return 0;

    for (size_t i = 0; i < v1->size; i++)
    {
        if (fabs(v_get(v1, i) - v_get(v2, i) > delta))
            return 0;
    }

    return 1;
}
