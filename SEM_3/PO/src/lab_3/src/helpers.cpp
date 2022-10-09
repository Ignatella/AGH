#include "helpers.hpp"
#include <iostream>

namespace helpers
{
    int GetNumberFromCharArray(const char *str, int index)
    {
        return *(str + index) - 48;
    }

    void ConvertStringToNumArray(int from, int length, const char *str, int peselArray[])
    {
        for (int i = 0; i < length; i++)
            peselArray[i + from] = GetNumberFromCharArray(str, i);
    }

    void FillArrWithNumber(int length, int arr[], int number)
    {
        for (int i = 0; i < length; i++)
        {
            arr[i] = number;
        }
    }

    void SetArrayBit(int strI, int arrI, const char *str, int arr[]) 
    { 
        arr[arrI] = GetNumberFromCharArray(str, strI);
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
