#ifndef HELPERS_HPP
#define HELPERS_HPP

namespace helpers
{
    const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    const int leapYearFebDaysCount = 29;

    int GetNumberFromCharArray(const char *str, int index);

    void ConvertStringToNumArray(int length, const char *str, int peselArray[]);

    void FillArrWithNumber(int length, int arr[], int number);

    int GetDaysCountInMonth(int year, int month);
}

#endif
