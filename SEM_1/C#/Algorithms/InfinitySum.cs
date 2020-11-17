using System;
using System.Collections.Generic;
using System.Text;

namespace lesson_5.Algorithms
{
    public static class InfinitySum
    {
        public static void Sum(double eps)
        {
            int i = 1;
            double sum = 0;
            while (true)
            {
                sum += (double)1 / (double)i;
                if ((double)1 / (double)i < eps)
                {
                    Console.WriteLine(sum);
                    return;
                }
                i++;
            }
        }
    }
}
