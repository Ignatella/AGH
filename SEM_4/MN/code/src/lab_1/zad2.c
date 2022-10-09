#include "stdio.h"

/**
 * Root of any number >= 0
 * x initialization:
 * 1 when a <= 1
 * a when a > 1
 */

int main()
{ 
  double a  = 100;
  double x = 100;

  for (int i = 0; i < 15; i++)
  {
    x = 0.5 * (x + a / x);
    printf("%d: %f\n", i, x);
  }

  return 0; 
}
