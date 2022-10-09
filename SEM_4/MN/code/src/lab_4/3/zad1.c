#include "stdio.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "../../helpers/matrix_helpers.h"
#include "../../helpers/gsl_helpers.h"

int main()
{
    double x1k = 0, x2k = 0, x1kp1, x2kp1;

    for (int i = 0; i < 101; i++)
    {
        x1kp1 = 6 / 7.0f * x2k + 3 / 7.0f;
        x2kp1 = 8 / 9.0f * x1k - 4 / 9.0f;

        if (i % 10 == 0)
        {
            printf("%.2f %.2f\n", x1kp1, x2kp1);
        }

        x1k = x1kp1;
        x2k = x2kp1;
    }

    return 0;
}

// macierz ma byc przekatniowo dominujaca
// wartosc na przekatnej ma byc |ai| > sum |aij|