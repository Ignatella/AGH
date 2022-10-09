#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "matrix_helpers.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"
#include <time.h>
#include <stdlib.h>

#define N 20

int main()
{
    gsl_matrix *A = gsl_matrix_calloc(N, N);
    gsl_vector *sums = gsl_vector_calloc(N);

    srand(time(NULL));
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            int r = rand() % 100 - 50;
            m_set(A, i, j, r);
            int c = v_get(sums, i);
            v_set(sums, i, c + abs(r));
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        int v = v_get(sums, i);
        int r = rand() % 10 - 5;

        if (r == 0)
            r = 1;

        m_set(A, i, i, v * r);
    }

    save_matrix_to_file("src/lab_6/gen_A/assets/matrix_A.txt", A);

    printf("SUCCESSFULLY GENERATED\n");

    gsl_matrix_free(A);
    gsl_vector_free(sums);

    return 0;
}
