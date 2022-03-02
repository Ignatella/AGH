#include "pesel.h"
#include "helpers.hpp"
#include <cstring>
#include <iostream>

using namespace std;

bool PeselValidator(const char *pesel, int (&peselArray)[peselLength])
{
    helpers::FillArrWithNumber(peselLength, peselArray, -1);
    helpers::ConvertStringToNumArray(strlen(pesel), pesel, peselArray);

    bool valid = true;

    valid = valid && IsPeselLengthValid(pesel);
    valid = valid ? valid && IsPeselCodeValid(peselArray) : valid;
    valid = valid ? valid && IsPeselDayValid(peselArray) : valid;

    return valid;
}

bool IsPeselLengthValid(const char *pesel)
{
    size_t len = strlen(pesel);

    if (len == peselLength)
        return true;

    return false;
}

bool IsPeselCodeValid(int (&peselArray)[peselLength])
{
    return getCtrlNumber(peselArray) == peselArray[10];
}

bool IsPeselDayValid(int (&peselArray)[peselLength])
{
    int year = getYear(peselArray);
    int month = getMonth(peselArray);
    int day = getDay(peselArray);

    int correctDayCount = helpers::GetDaysCountInMonth(year, month);

    return day <= correctDayCount;
}

void printPesel(const int (&peselArray)[peselLength])
{
    for (int i : peselArray)
    {
        if (i < 0)
            continue;

        cout << i;
    }
}

int getCtrlNumber(const int (&peselArray)[peselLength])
{
    int sum = 0;
    for (int i = 0; i < peselLength; i++)
    {
        sum += peselArray[i] * peselNumberWeights[i];
    }

    return (10 - sum % 10) % 10;
}

int getDay(const int (&peselArray)[peselLength])
{
    return peselArray[4] * 10 + peselArray[5];
}

int getMonth(const int (&peselArray)[peselLength])
{
    int currentMonth = peselArray[2] * 10 + peselArray[3];
    while (currentMonth > 12)
    {
        currentMonth -= 10;
    }

    return currentMonth;
}

int getYear(const int (&peselArray)[peselLength])
{
    int year = peselArray[0] * 10 + peselArray[1];

    int month = peselArray[2] * 10 + peselArray[3];

    return 1900 + (month / (int)20) * 100 + year;
}
