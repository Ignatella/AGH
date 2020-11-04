using System;
using System.Collections.Generic;

namespace lesson_5
{
    public static class PascalTriangle
    {
        public static void PascalTriangleQueue(int stringNum) //better solution
        {
            Queue<int> row = new Queue<int>(new[] { 1 });

            Console.WriteLine(row.Peek());

            for (int i = 2; i <= stringNum; i++)
            {
                Console.Write(row.Peek() + " ");
                row.Enqueue(1);

                for (int k = 2; k < i; k++)
                {
                    int sum = row.Dequeue() + row.Peek();
                    row.Enqueue(sum);

                    Console.Write(sum + " ");
                }

                row.Dequeue();
                row.Enqueue(1);

                Console.Write(row.Peek() + " \n");
            }
        }

        public static void PascalTriangleOneArray(int rowNumbers)
        {
            int[] row = new int[rowNumbers];
            row[0] = 1;

            Console.WriteLine(1);

            for (int i = 1; i < rowNumbers; i++)
            {
                int overridenValue = 1;

                Console.Write(1 + " ");

                for (int k = 1; k < i; k++)
                {
                    int tmp = row[k];
                    row[k] = overridenValue + row[k];
                    overridenValue = tmp;
                    Console.Write(row[k] + " ");
                }

                row[i] = 1;
                Console.WriteLine(1);
            }
        }

        public static void PascalTriangleArrays(int stringNum)
        {
            int[] triangleRow = { };

            for (int i = 0; i < stringNum; i++)
            {
                int[] newLine = new int[i + 1];

                for (int k = 0; k < newLine.Length; k++)
                {
                    if (k == 0 || k == newLine.Length - 1)
                    {
                        newLine[k] = 1;
                        Console.Write("1 ");
                        continue;
                    }
                    newLine[k] = triangleRow[k] + triangleRow[k - 1];
                    Console.Write(newLine[k] + " ");
                }
                triangleRow = newLine;
                Console.WriteLine();
            }
        }
    }
}
