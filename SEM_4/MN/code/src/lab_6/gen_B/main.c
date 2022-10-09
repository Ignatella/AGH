#include "stdio.h"

#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "/usr/include/gsl/gsl_cblas.h"

#include "matrix_helpers.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"

#define N 20

int main()
{
    gsl_matrix *A = read_matrix_from_file("src/lab_6/gen_A/assets/matrix_A.txt", N, N);
    gsl_vector *x = read_vector_from_file("src/lab_6/gen_X/assets/vector_X.txt", N);
    gsl_vector *b = gsl_vector_calloc(N);

    gsl_blas_dgemv(CblasNoTrans, 1, A, x, 0, b);

    save_vector_to_file("src/lab_6/gen_B/assets/vector_B.txt", b);

    printf("SUCCESSFULLY GENERATED\n");

    gsl_matrix_free(A);
    gsl_vector_free(x);
    gsl_vector_free(b);

    return 0;
}
