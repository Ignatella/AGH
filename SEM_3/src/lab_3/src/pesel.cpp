#include "pesel.h"
#include "helpers.hpp"
#include <iostream>
#include <cstring>

using namespace std;

// YYMMDDXXXPK
// DDMMYYYY
// XXXP
bool PeselGenerator(const char *dateOfBirth, const char *extraInfo, int peselArray[]) 
{
    helpers::FillArrWithNumber(11, peselArray, 0);
    int month = getMonth(dateOfBirth);
    int year = getYear(dateOfBirth);

    helpers::SetArrayBit(6, 0, dateOfBirth, peselArray);
    helpers::SetArrayBit(7, 1, dateOfBirth, peselArray);
    helpers::SetArrayBit(2, 2, dateOfBirth, peselArray);
    helpers::SetArrayBit(3, 3, dateOfBirth, peselArray);
    helpers::SetArrayBit(0, 4, dateOfBirth, peselArray);
    helpers::SetArrayBit(1, 5, dateOfBirth, peselArray);

    helpers::SetArrayBit(0, 6, extraInfo, peselArray);
    helpers::SetArrayBit(1, 7, extraInfo, peselArray);
    helpers::SetArrayBit(2, 8, extraInfo, peselArray);
    helpers::SetArrayBit(3, 9, extraInfo, peselArray);

    int monthBit = CalculateMonthBit(year, month);
    peselArray[2] = monthBit;

    int ctrlNumber = getControlNumber(peselArray);
    peselArray[10] = ctrlNumber;
 
    bool valid = true;

    valid = strlen(extraInfo) == 4;
    valid = valid ? month < 13 : valid;
    valid = valid ? strlen(dateOfBirth) == 8 : valid;
    valid = valid ? IsPeselDayValid(dateOfBirth) : valid;

    return valid;
}

// oblicza pierwsza liczbe miesiaca dla pesel
int CalculateMonthBit(int year, int month) { 
    int bit = (year - 1900) / (int) 100 * 2;
    return (bit * 10 + month) / (int) 10;
}

// wypisuje pesel
void printPesel(const int (&peselArray)[peselLength])
{
    for (int i : peselArray)
    {
        if (i < 0)
            continue;

        cout << i;
    }
}

// oblicza liczbe kontrolna
int getControlNumber(const int peselArray[])
{
    int sum = 0;
    for (int i = 0; i < peselLength - 1; i++)
    {
        sum += peselArray[i] * peselNumberWeights[i];
    }

    return (10 - sum % 10) % 10;
}

// zwraca plec 
const char *sex(const char *extraInfo)
{
    int sexBit = helpers::GetNumberFromCharArray(extraInfo, 3);
    if (sexBit % 2 == 0)
        return "Kobieta";
    return "Mezczyzna";
}

// wyobrebnienie roku z daty urodzenia
int getYear(const char *dateOfBirth)
{
    return 
        helpers::GetNumberFromCharArray(dateOfBirth, 4) * 1000 + 
        helpers::GetNumberFromCharArray(dateOfBirth, 5) * 100  + 
        helpers::GetNumberFromCharArray(dateOfBirth, 6) * 10   +
        helpers::GetNumberFromCharArray(dateOfBirth, 7);
}

// wyobrebnienie dnia z daty urodzenia
int getDay(const char *dateOfBirth)
{
    return helpers::GetNumberFromCharArray(dateOfBirth, 0) * 10 + helpers::GetNumberFromCharArray(dateOfBirth, 1);
}

// wyobrebnienie miesiaca z daty urodzenia
int getMonth(const char *dateOfBirth)
{ 
    return helpers::GetNumberFromCharArray(dateOfBirth, 2) * 10 + helpers::GetNumberFromCharArray(dateOfBirth, 3);
}

// sprawdza, czy dzien jest mozliwy
bool IsPeselDayValid(const char *peselStr)
{
    int year = getYear(peselStr);
    int month = getMonth(peselStr);
    int day = getDay(peselStr);

    int correctDayCount = helpers::GetDaysCountInMonth(year, month);

    return day <= correctDayCount;
}
