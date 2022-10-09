#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "../helpers/matrix_helpers.h"
#include "../helpers/gsl_helpers.h"

#define N 4

int main()
{
    // A[0] <- c
    // A[1] <- d
    // A[2] <- a
    // A[3] <- b
    gsl_matrix *A = read_matrix_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_3/assets/matrix_A.txt", 4, N);
    gsl_vector *x = gsl_vector_calloc(N);

    for (int i = 1; i < N; i++)
    {
        double di = m_get(A, 1, i) - m_get(A, 0, i - 1) * m_get(A, 2, i) / m_get(A, 1, i-1);
        m_set(A, 1, i, di);

        double bi = m_get(A, 3, i) - m_get(A, 3, i - 1) * m_get(A, 2, i) / m_get(A, 1, i-1);
        m_set(A, 3, i, bi);
    }

    double bn = m_get(A, 3, N - 1);
    double dn = m_get(A, 1, N - 1);

    gsl_vector_set(x, N - 1, bn / dn);

    for (int i = N - 2; i > -1; i--)
    {
        double bi = m_get(A, 3, i);
        double ci = m_get(A, 0, i);
        double di = m_get(A, 1, i);
        double xi1 = v_get(x, i + 1);
        
        double xi = (bi - ci * xi1) / di;

        v_set(x, i, xi);
    }
    
    print_vector(x);

    gsl_matrix_free(A);
    gsl_vector_free(x);

    return 0;
}
