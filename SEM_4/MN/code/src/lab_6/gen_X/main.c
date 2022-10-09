#include "stdio.h"
#include <time.h>
#include <stdlib.h>

#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#include "matrix_helpers.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"

#define N 20

int main()
{
    gsl_vector *x = gsl_vector_calloc(N);

    srand(time(NULL));
    for (size_t i = 0; i < N; i++)
    {
        int r = rand() % 200 - 100;
        v_set(x, i, r);
    }

    save_vector_to_file("src/lab_6/gen_X/assets/vector_X.txt", x);

    printf("SUCCESSFULLY GENERATED\n");

    gsl_vector_free(x);

    return 0;
}
