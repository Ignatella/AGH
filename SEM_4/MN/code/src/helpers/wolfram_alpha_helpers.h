#pragma once

#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#include "gsl_helpers.h"

void wolfram_print_matrix(gsl_matrix *matrix)
{
    int n = matrix->size1, m = matrix->size2;

    printf("{");

    for (size_t i = 0; i < n; i++)
    {
        printf("{");
        for (size_t j = 0; j < m; j++)
        {
            printf("%.3g, ", m_get(matrix, i, j));
        }
        printf("\b\b}, ");
    }

    printf("\b\b}");

    printf("\n");
    printf("\n");
}

void wolfram_print_vector(gsl_vector *v)
{
    printf("{");

    for (size_t i = 0; i < v->size; i++)
    {
        printf("%.3g, ", v_get(v, i));
    }

    printf("\b\b}");
    printf("\n");
    printf("\n");
}