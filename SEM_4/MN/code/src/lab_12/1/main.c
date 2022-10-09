#include <stdio.h>
#include "math.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"
#include "matrix_helpers.h"

#define n 100
#define a 1
#define b 5

int main()
{
    gsl_vector *X = gsl_vector_calloc(n);

    for (size_t i = 0; i < n; i++)
    {
        double z = cos((M_PI * 2 * i + 1) / (2 * n + 2));

        // double x = 1.0 / 2.0 * (z  * (b - a) + a + b);
        double x = 2.0 / (b - a) * (z - a) - 1;

        v_set(X, i, x);

        printf("%f\n", x);
    }

    save_vector_to_file("/home/stud2020/0yermakovich/Desktop/MN/src/lab_12/1/result.txt", X);

    gsl_vector_free(X);
}