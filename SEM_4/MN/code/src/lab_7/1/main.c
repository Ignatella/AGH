#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include "gsl_helpers.h"

#define n 5

void print_vector_h(gsl_vector *v);

int main(void)
{
    double A[n * n];
    double B[n * n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[n * i + j] = 1 + (i + j) + 1.0 * cos(i * j) / (1.5 + sin(i + j));
            B[n * i + j] = A[n * i + j];
        }
    }

    gsl_vector *wart_wlasne = gsl_vector_alloc(n);
    gsl_matrix *wekt_wlasne = gsl_matrix_alloc(n, n);
    gsl_matrix_view A_mv = gsl_matrix_view_array(A, n, n);
    gsl_matrix_view B_mv = gsl_matrix_view_array(B, n, n);
    gsl_eigen_symmv_workspace *wsp = gsl_eigen_symmv_alloc(n);
    gsl_eigen_symmv(&A_mv.matrix, wart_wlasne, wekt_wlasne, wsp);
    gsl_eigen_symmv_free(wsp);
    gsl_eigen_symmv_sort(wart_wlasne, wekt_wlasne, GSL_EIGEN_SORT_ABS_DESC);

    // print solution
    {
        printf("Solution: \n");
        for (int i = 0; i < n; i++)
        {
            double wart_i = gsl_vector_get(wart_wlasne, i);
            gsl_vector_view wekt_i = gsl_matrix_column(wekt_wlasne, i);
            printf("%lf -> ", wart_i);
            print_vector_h(&wekt_i.vector);
        }
    }

    // check solution
    {
        printf("\n\nCheck solution:");

        for (int i = 0; i < n; i++)
        {
            gsl_vector wekt_i = gsl_matrix_column(wekt_wlasne, i).vector;
            double wart_i = gsl_vector_get(wart_wlasne, i);

            gsl_vector *res = gsl_vector_calloc(n);
            gsl_blas_dgemv(CblasNoTrans, 1, &B_mv.matrix, &wekt_i, 0, res);
            gsl_vector_scale(&wekt_i, wart_i);

            printf("\n");
            print_vector_h(res);
            print_vector_h(&wekt_i);

            gsl_vector_free(res);
        }
    }

    gsl_vector_free(wart_wlasne);
    gsl_matrix_free(wekt_wlasne);

    return 0;
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