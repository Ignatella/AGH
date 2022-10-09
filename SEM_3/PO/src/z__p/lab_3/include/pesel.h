#ifndef PESEL_H
#define PESEL_H

const int peselLength = 11;

const int peselNumberWeights[peselLength] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

bool IsPeselCodeValid(int (&peselArray)[peselLength]);

bool IsPeselLengthValid(const char *);

bool IsPeselDayValid(int (&peselArray)[peselLength]);

bool PeselValidator(const char *, int (&)[peselLength]);

void printPesel(const int (&)[peselLength]);

int getCtrlNumber(const int (&)[peselLength]);

int getDay(const int (&)[peselLength]);

int getMonth(const int (&)[peselLength]);

int getYear(const int (&)[peselLength]);

#endif