#ifndef matrix_helpers
#define matrix_helpers

#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include <string.h>

#include "gsl_helpers.h"

void print_matrix(gsl_matrix *matrix)
{
    int n = matrix->size1, m = matrix->size2;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            double el = gsl_matrix_get(matrix, i, j);
            printf("%.4f ", el);
        }

        printf("\n");
    }

    printf("\n");
    printf("\n");
}

void print_permutation(gsl_permutation *p)
{
    for (size_t i = 0; i < p->size; i++)
        printf("%ld\n", gsl_permutation_get(p, i));

    printf("\n");
    printf("\n");
}

void print_vector(FILE *fp, gsl_vector *v)
{
    for (size_t i = 0; i < v->size; i++)
        fprintf(fp, "%.4g\n", gsl_vector_get(v, i));

    fprintf(fp, "\n");
    fprintf(fp, "\n");
}

gsl_matrix *read_matrix_from_file(const char *name, int n, int m)
{
    FILE *fp = fopen(name, "rt");

    if (fp == NULL)
        exit(EXIT_FAILURE);

    char *line = NULL;
    size_t len = 0;

    gsl_matrix *result = gsl_matrix_calloc(n, m);

    for (size_t i = 0; i < n; i++)
    {
        getline(&line, &len, fp);
        char *token = strtok(line, " ");

        for (size_t j = 0; j < m; j++)
        {
            double a = atof(token);
            gsl_matrix_set(result, i, j, a);

            token = strtok(NULL, " ");
        }

        free(line);
        line = NULL;
    }

    fclose(fp);

    return result;
}

gsl_vector *read_vector_from_file(const char *name, int n)
{
    gsl_vector *result = gsl_vector_calloc(n);

    gsl_matrix *m = read_matrix_from_file(name, n, 1);
    for (size_t i = 0; i < n; i++)
    {
        double value = gsl_matrix_get(m, i, 0);
        gsl_vector_set(result, i, value);
    }

    gsl_matrix_free(m);
    return result;
}

void save_matrix_to_file(const char *name, gsl_matrix *m)
{
    FILE *fp = fopen(name, "w");

    if (fp == NULL)
        exit(EXIT_FAILURE);

    for (size_t i = 0; i < m->size1; i++)
    {
        for (size_t j = 0; j < m->size2; j++)
        {
            fprintf(fp, "%g ", m_get(m, i, j));
        }

        fprintf(fp, "\n");
    }

    fclose(fp);
}

void save_vector_to_file(const char *name, gsl_vector *v)
{
    FILE *fp = fopen(name, "w+");

    if (fp == NULL)
        exit(EXIT_FAILURE);

    for (size_t i = 0; i < v->size; i++)
    {
        fprintf(fp, "%g ", v_get(v, i));
        fprintf(fp, "\n");
    }

    fclose(fp);
}

/**
 * @brief To be fixed
 *
 * @param p
 * @return gsl_matrix*
 */
gsl_matrix *get_permutation_matrix(gsl_permutation *p)
{
    int n = p->size;

    gsl_matrix *result = gsl_matrix_calloc(n, n);

    for (int i = 0; i < n; i++)
    {
        int c = gsl_permutation_get(p, i);
        gsl_matrix_set(result, i, c, 1.0);
    }

    return result;
}

gsl_matrix *extractLMatrix(gsl_matrix *LU)
{
    gsl_matrix *result = gsl_matrix_calloc(LU->size1, LU->size2);

    for (int i = 0; i < LU->size1; i++)
    {
        gsl_matrix_set(result, i, i, 1);
        for (int j = 0; j < i; j++)
        {
            gsl_matrix_set(result, i, j, gsl_matrix_get(LU, i, j));
        }
    }

    return result;
}

gsl_matrix *extractUMatrix(gsl_matrix *LU)
{
    gsl_matrix *result = gsl_matrix_calloc(LU->size1, LU->size2);

    for (int i = 0; i < LU->size1; i++)
    {
        for (int j = i; j < LU->size2; j++)
        {
            gsl_matrix_set(result, i, j, gsl_matrix_get(LU, i, j));
        }
    }

    return result;
}

//    | 3 2 7 | | x_1 | | 5 |
// eg | 0 4 4 |x| x_2 |=| 7 |
//    | 0 0 5 | | x_3 | | 8 |
//
gsl_vector *solveGaussianEquation(gsl_matrix *A, gsl_vector *b)
{
    int n = b->size;

    gsl_vector *x = gsl_vector_calloc(n);

    for (int i = n - 1; i > -1; i--)
    {
        double curr_x_i = gsl_vector_get(b, i);

        for (int j = n - 1; j > i; j--)
        {
            curr_x_i -= gsl_matrix_get(A, i, j) * gsl_vector_get(x, j);
        }

        double Aii = gsl_matrix_get(A, i, i);

        gsl_vector_set(x, i, curr_x_i / Aii);
    }

    return x;
}

void vector_cpvv(gsl_vector *from, gsl_vector *to)
{
    for (size_t i = 0; i < from->size; i++)
    {
        v_set(to, i, v_get(from, i));
    }
}
#endif
