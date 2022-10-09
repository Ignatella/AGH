#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "/usr/include/gsl/gsl_permute.h"
#include "/usr/include/gsl/gsl_permute_vector.h"
#include "../../helpers/matrix_helpers.h"

gsl_permutation *createInversePermutation(int n)
{
    gsl_permutation *result = gsl_permutation_calloc(n);

    for (size_t i = 0; i < n; i++)
        result->data[i] = n - i - 1;

    return result;
}

int main()
{
    int n = 5;
    int sig = 1;

    gsl_matrix *A = read_matrix_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/pd/pd_1/assets/A_matrix.txt", n, n);
    gsl_matrix *b_matrix = read_matrix_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/pd/pd_1/assets/b_matrix.txt", n, 1);
    gsl_permutation *p = gsl_permutation_calloc(n);
    gsl_vector *b = gsl_vector_alloc_col_from_matrix(b_matrix, 0);
    gsl_vector *lib_solution = gsl_vector_calloc(n);

    printf("Matrix A:\n");
    print_matrix(A);

    printf("Vector b:\n");
    print_vector(b);

    gsl_linalg_LU_decomp(A, p, &sig);

    printf("Matrix A after LU decomposition:\n");
    print_matrix(A);

    gsl_linalg_LU_solve(A, p, b, lib_solution);

    printf("Library solution:\n");
    print_vector(lib_solution);

    // region custom solution
    printf("Step by step solution:\n");

    gsl_permute_vector(p, b); // this gives us `pb` multiplication and saves it to b

    gsl_matrix *L = extractLMatrix(A); // get L matrix
    gsl_matrix *U = extractUMatrix(A); // get U matrix

    gsl_permutation *inv_perm = createInversePermutation(n);   // permutation, that reorder columns 0 1 2 -> 2 1 0
    gsl_matrix *inv_perm_m = get_permutation_matrix(inv_perm); // matrix, that represents permutation

    /*
        Our solveGaussianEquation does not accept  matrix as
        | 1 0 0 |
        | 2 2 0 |
        | 3 4 1 |

        but only like:

        | 1 4 3 |
        | 0 2 2 |
        | 0 0 1 |

        So we have to permutate by rows and by cols one time
        Also we have to permutate b once and y after gathering results
    */

    gsl_permute_vector(inv_perm, b); // permutating b

    gsl_matrix *L_upper = gsl_matrix_calloc(n, n); // create copy of L
    gsl_matrix_memcpy(L_upper, L);
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, inv_perm_m, L, 0.0, L_upper); // permutate rows
    gsl_permute_matrix(inv_perm, L_upper);                                        // permute columns

    gsl_vector *y = solveGaussianEquation(L_upper, b);

    gsl_permute_vector(inv_perm, y); // permutate y after gathering solution. So y is ready to pass to the next equation

    gsl_vector *x = solveGaussianEquation(U, y); // Ux = y

    print_vector(x);

    gsl_matrix_free(L);
    gsl_matrix_free(U);
    gsl_matrix_free(inv_perm_m);
    gsl_matrix_free(L_upper);
    gsl_permutation_free(inv_perm);
    gsl_vector_free(y);
    gsl_vector_free(x);
    // endregion

    gsl_matrix_free(A);
    gsl_matrix_free(b_matrix);
    gsl_permutation_free(p);
    gsl_vector_free(b);
    gsl_vector_free(lib_solution);

    return 0;
}

// HW (6 x 6)
// LUx = b
// PAx = Pb
//
//
// To solve:
// Ly = Pb
// Ux = y
