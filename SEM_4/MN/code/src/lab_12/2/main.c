#include <stdio.h>
#include "math.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"
#include "matrix_helpers.h"

#define n 7
#define m 4

int main()
{
    gsl_vector *X = read_vector_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_12/2/x.txt", n);
    gsl_vector *Y = read_vector_from_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_12/2/y.txt", n);
    gsl_matrix *G = gsl_matrix_calloc(m, m);
    gsl_vector *RO = gsl_vector_calloc(m);

    for (size_t k = 0; k < m; k++)
    {
        double ro = 0;

        for (size_t j = 0; j < n; j++)
        {
            ro += v_get(Y, j) * pow(v_get(X, j), k);
        }

        v_set(RO, k, ro);

        for (size_t i = 0; i < m; i++)
        {
            double gk = 0;
            
            for (size_t j = 0; j < n; j++)
            {
                gk += pow(v_get(X, j), i + k);
            }

            m_set(G, k, i, gk);
        }
    }

    gsl_vector *result = linalg_solve_LU(G, RO);
    print_vector(stdout, result);

    double RR = 0;

    for (size_t j = 0; j < n; j++)
    {
        double yy = 0;

        for (size_t i = 0; i < m; i++)
        {
            yy += v_get(result, i) * v_get(X, j);
        }

        RR += pow(v_get(Y, j) - yy, 2);
    }

    printf("R^2=%f\n", RR / n);

    gsl_vector_free(X);
    gsl_vector_free(Y);
    gsl_vector_free(RO);
    gsl_vector_free(result);
    gsl_matrix_free(G);
}