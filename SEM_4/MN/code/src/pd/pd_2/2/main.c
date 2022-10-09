#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"

#include <matrix_helpers.h>
#include <gsl_helpers.h>
#include <linalg_helpers.h>

#define N 6
#define I 101

int main()
{
    gsl_matrix *A = read_matrix_from_file("src/pd/pd_2/2/assets/A_matrix.txt", N, N);
    gsl_matrix *A_1 = gsl_matrix_calloc(N, N);

    printf("Macierz A:\n");
    print_matrix(A);

    for (size_t i = 0; i < N; i++)
    {
        gsl_vector *e_i = gsl_vector_calloc(N);
        v_set(e_i, i, 1);

        gsl_vector *x = linalg_solve_jacobi(A, e_i, I);
        gsl_matrix_set_col(A_1, i, x);

        gsl_vector_free(e_i);
        gsl_vector_free(x);
    }

    printf("Odworocona macierz A_1:\n");
    print_matrix(A_1);

    gsl_matrix *I_ = gsl_matrix_calloc(N, N);
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, A, A_1, 0.0, I_);

    printf("Wynik mnozenia macierzy A i A_1:\n");
    print_matrix(I_);

    save_matrix_to_file("src/pd/pd_2/2/assets/result.txt", I_);

    gsl_matrix_free(A);
    gsl_matrix_free(A_1);
    gsl_matrix_free(I_);

    return 0;
}
