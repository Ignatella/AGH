using System;
using System.Collections.Generic;
using System.Text;

namespace lesson_5
{
    public static class BinarySearch
    {
        public static void BiSearch(int[] numbers, int number)
        {
            int upperBound = numbers.Length;
            int lowerBound = -1;
            while (upperBound - lowerBound > 1)
            {
                int index = (upperBound + lowerBound) / 2;

                if (numbers[index] == number)
                {
                    Console.WriteLine("Such number is performed in the array.");
                    return;
                }

                if (numbers[index] >= number)
                    upperBound = index;
                else lowerBound = index;
            }

            Console.WriteLine("Such number is not performed in the array.");
        }
    }
}
