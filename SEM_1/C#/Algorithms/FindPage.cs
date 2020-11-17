using System;
using System.Collections.Generic;
using System.Text;

namespace lesson_5
{
    public static class FindPage
    {
        public static void FindPageItemIsOn(int itemPosition, int pageSize)
        {
            string[] positionName = { "A", "B", "C", "D" };

            int pageNumber = 1;

            while (true)
            {
                if (itemPosition - pageSize * pageNumber <= 0)
                {
                    int itemPositionOnPage = itemPosition - ((pageNumber - 1) * pageSize) - 1;
                    Console.WriteLine($"Page number: {pageNumber}, page position: {positionName[itemPositionOnPage]}");
                    return;
                }
                pageNumber++;
            }
        }
    }
}
