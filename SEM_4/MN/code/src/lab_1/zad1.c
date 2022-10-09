// #include "stdio.h"

// double next(double xn, double xn1)
// {
//   return 13 / (double)3 * xn1 - 4 / (double)3 * xn;
// }

// int main()
// {
//   double x0 = 1;
//   double x1 = 1 / (double)3;

//   printf("0: %f\n", x0);
//   printf("1: %f\n", x1);

//   for (int i = 2; i < 120; i++)
//   {
//     double n = next(x0, x1);
//     x0 = x1;
//     x1 = n;

//     printf("%d: %f\n", i, n);
//   }

//   return 0;
// }

#include <stdio.h>

int main()
{
  double x0 = 1., x1 = 1 / 3.;

  printf("0: %f\n", x0);
  printf("1: %f\n", x1);

  for (int i = 2; i < 120; i++)
  {
    double x2 = 13 / 3. * x1 - 4 / 3.0 * x0;
    printf("%d: %f\n", i, x2);
    x0 = x1;
    x1 = x2;
  }
  return 0;
}