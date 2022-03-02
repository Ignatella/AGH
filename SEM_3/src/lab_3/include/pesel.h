#ifndef PESEL_H
#define PESEL_H

const int peselLength = 11;

const int peselNumberWeights[peselLength - 1] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

bool PeselGenerator(const char *, const char *, int[]);

void printPesel(const int (&peselArray)[peselLength]);

int getControlNumber(const int[]);

const char *sex(const char *);

int getYear(const char *);

int getDay(const char *);

int getMonth(const char *);

int getDay(const char *);

int CalculateMonthBit(int year, int month);

bool IsPeselDayValid(const char *peselStr);

#endif
