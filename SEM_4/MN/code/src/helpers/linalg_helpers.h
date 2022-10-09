#pragma once

#include "gsl_helpers.h"

gsl_vector *linalg_solve_LU(gsl_matrix *A, gsl_vector *b)
{
    unsigned int n = A->size1;

    gsl_permutation* p = gsl_permutation_calloc(n);
    int sign =0;
    gsl_vector *x = gsl_vector_calloc(n);

    gsl_linalg_LU_decomp(A, p, &sign);
    gsl_linalg_LU_solve(A, p, b, x);

    gsl_permutation_free(p);

    return x;
}

gsl_vector *linalg_solve_jacobi(gsl_matrix *A, gsl_vector *b, int iterations)
{
    gsl_vector *x = gsl_vector_calloc(b->size);

    for (size_t i = 0; i < iterations; i++)
    {
        for (size_t k = 0; k < b->size; k++)
        {
            double sum = 0;
            for (size_t j = 0; j < b->size; j++)
            {
                if (j == k)
                    continue;

                sum += m_get(A, k, j) * v_get(x, j);
            }

            double newX = (v_get(b, k) - sum) / m_get(A, k, k);

            v_set(x, k, newX);
        }
    }

    return x;
}

int linalg_is_diagonally_dominant(gsl_matrix *A)
{
    for (size_t i = 0; i < A->size1; i++)
    {
        double Aii = m_get(A, i, i);
        double sum = 0;

        for (size_t j = 0; j < A->size2; j++)
        {
            if (i == j)
                continue;

            sum += abs(m_get(A, i, j));
        }

        if (abs(Aii) < sum)
            return 0;
    }

    return 1;
}
