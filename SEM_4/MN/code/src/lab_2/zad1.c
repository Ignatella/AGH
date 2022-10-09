#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "../helpers/matrix_helpers.h"

int main()
{
    int n = 4;
    int sig = 2;

    gsl_matrix *A = read_matrix_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_2/matrix.txt", n, n);
    gsl_permutation *P = gsl_permutation_calloc(n);

    print_matrix(A);

    gsl_linalg_LU_decomp(A, P, &sig);

    print_permutation(P);
    // print_matrix(A);

    gsl_matrix *L = extractLMatrix(A);
    gsl_matrix *U = extractUMatrix(A);

    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, L, U, 0.0, A); 


    print_matrix(L);
    print_matrix(U);
    print_matrix(A);
    // gsl_matrix *B = gsl_matrix_calloc(n, n);

    // for (size_t i = 0; i < n; i++)
    // {
    //     for (size_t j = 0; j < n; j++)
    //     {
    //         double sum = 0;

    //         for (size_t r = 0; r < n; r++)
    //         {
    //             double l_el = 0, u_el = 0;

    //             if (r <= j)
    //                 u_el = gsl_matrix_get(A, r, j);

    //             if (i > r)
    //                 l_el = gsl_matrix_get(A, i, r);

    //             if (r == i)
    //                 l_el = 1;

    //             sum += l_el * u_el;
    //         }

    //         gsl_matrix_set(B, i, j, sum);
    //     }
    // }

    gsl_matrix *perm_matrix = get_permutation_matrix(P);

    gsl_matrix *AB = gsl_matrix_calloc(n, n);

    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, perm_matrix, A, 0.0, AB); 

    print_matrix(AB);

    gsl_matrix_free(perm_matrix);
    gsl_matrix_free(AB);
    gsl_matrix_free(A);
    gsl_permutation_free(P);

    return 0;
}

// HW (6 x 6)
// LUx = b
// PAx = Pb
//
//
// Ly = Pb
// Ux = y

// ceramrtr.ceramika.agh.edu.pl/~szyszkin