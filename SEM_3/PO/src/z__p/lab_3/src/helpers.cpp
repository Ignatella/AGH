#include "helpers.hpp"
#include <iostream>

namespace helpers
{
    int GetNumberFromCharArray(const char *str, int index)
    {
        return *(str + index) - 48;
    }

    void ConvertStringToNumArray(int length, const char *str, int peselArray[])
    {
        for (int i = 0; i < length; i++)
            peselArray[i] = GetNumberFromCharArray(str, i);
    }

    void FillArrWithNumber(int length, int arr[], int number)
    {
        for (int i = 0; i < length; i++)
        {
            arr[i] = number;
        }
    }

    bool LeapYear(int year)
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    int GetDaysCountInMonth(int year, int month)
    {
        int days = daysPerMonth[month];

        if (LeapYear(year) && month == 2)
            days = leapYearFebDaysCount;
            
        return days;
    }
}