#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "../../helpers/matrix_helpers.h"
#include "../../helpers/gsl_helpers.h"

#define N 5

int main()
{
    int sig = 2;
    gsl_matrix *A = read_matrix_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_4/2/assets/matrix_A.txt", N, N);
    gsl_matrix *b_matrix = read_matrix_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_4/2/assets/matrix_b.txt", N, 1);
    gsl_vector *b = gsl_vector_alloc_col_from_matrix(b_matrix, 0);
    gsl_vector *lib_solution = gsl_vector_calloc(N);
    gsl_vector *tau = gsl_vector_calloc(N);

    print_matrix(A);
    print_vector(b);

    gsl_linalg_QR_decomp(A, tau);
    gsl_linalg_QR_solve(A, tau, b, lib_solution);

    print_vector(lib_solution);

    gsl_matrix_free(A);
    gsl_matrix_free(b_matrix);
    gsl_vector_free(b);
    gsl_vector_free(tau);
    gsl_vector_free(lib_solution);
    return 0;
}

// A = QR

// Q - ortogonalna
// R - trojkatna gorna
