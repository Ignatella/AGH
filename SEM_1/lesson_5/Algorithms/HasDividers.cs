using System;
using System.Collections.Generic;
using System.Text;

namespace lesson_5.Algorithms
{
    public static class HasDividers
    {
        public static void FindDividers(int num)
        {
            bool hasDivider = false;

            for (int i = 2; i < num / 2 + 1; i++)
            {
                if (num % i == 0)
                {
                    hasDivider = true;
                    Console.WriteLine($"{i} is divider of {num}");
                }
            }

            if (hasDivider)
            {
                Console.WriteLine($"1 is divider of {num}");
                Console.WriteLine($"{num} is divider of {num}");
            }
            else
                Console.WriteLine("The number is Prime");
        }
    }
}
