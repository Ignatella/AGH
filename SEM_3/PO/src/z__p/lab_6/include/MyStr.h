#pragma once

#include "MyList.h"
#include <iostream>

struct MyString { 
    char *begin;
    char *next;
	char *end;
    char *separators;
};

char *mycopy(const char *str);

int mystrlen(const char *str);

char *mystrcat(const char *lstr, const char *rstr, const char separator = '\0');

bool findSep(char separator, const char *str);

void addSep(MyString *str, const char *newSeparators);

void initMyString(MyString *str, const char *sourceStr, const char *separators = NULL);

void split2list(MyList *list, MyString* str);

char *mystrtok(MyString *str);

void removeMyString(MyString *str);

char *gettok(MyString *str, int n);