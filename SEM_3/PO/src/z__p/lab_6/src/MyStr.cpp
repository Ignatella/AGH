#include <MyStr.h>
#include <MyList.h>
#include <iostream>

void copyStringTo(int sourceStart, int sourceEnd, const char *source, int targetStart, char *target)
{
	for (int i = sourceStart; i < sourceEnd; i++)
		*(target + targetStart + i - sourceStart) = *(source + i);
}

char *mycopy(const char *str)
{
	int len = mystrlen(str);

	char *result = new char[len + 1]();

	copyStringTo(0, len, str, 0, result);

	return result;
}

int mystrlen(const char *str)
{
	int i = 0;

	for (; *(str + i) != '\0'; i++)
		;

	return i;
}

char *mystrcat(const char *lstr, const char *rstr, const char separator)
{
	int lstrLen = mystrlen(lstr);
	int rstrLen = mystrlen(rstr);
	char *result = NULL;

	if (separator == '\0')
	{
		result = new char[lstrLen + rstrLen + 1];
		copyStringTo(0, lstrLen, lstr, 0, result);
		copyStringTo(0, rstrLen + 1, rstr, lstrLen, result);
	}
	else
	{
		result = new char[lstrLen + rstrLen + 2];
		copyStringTo(0, lstrLen, lstr, 0, result);
		result[lstrLen] = separator;
		copyStringTo(0, rstrLen + 1, rstr, lstrLen + 1, result);
	}

	return result;
}

bool findSep(char separator, const char *str)
{
	int len = mystrlen(str);
	int i = 0;

	for (; *(str + i) != separator && i < len; i++)
		;

	return i < len;
}

void addSep(MyString *str, const char *newSeparators)
{
	int oldLen = 0;

	if (str->separators != NULL)
		oldLen = mystrlen(str->separators);

	int len = mystrlen(newSeparators);

	char *newSeps = new char[oldLen + len + 1];

	copyStringTo(0, oldLen, str->separators, 0, newSeps);
	copyStringTo(0, len + 1, newSeparators, oldLen, newSeps);

	delete[] str->separators;
	str->separators = newSeps;
}

void initMyString(MyString *str, const char *sourceStr, const char *separators)
{
	str->begin = mycopy(sourceStr);
	str->next = str->begin;
	str->end = str->begin + mystrlen(sourceStr);

	str->separators = NULL;
	if (separators != NULL)
		str->separators = mycopy(separators);
}

void split2list(MyList *list, MyString *str)
{
	str->next = str->begin;

	for (const char *curr = mystrtok(str); *curr != '\0'; curr = mystrtok(str))
		append(list, curr);
}

char *mystrtok(MyString *str)
{
	char *result = str->next;

	for (int i = 0; str->next != str->end; i++, str->next++)
	{
		bool foundSeparator = false;
		while (findSep(*(str->next), str->separators))
		{
			*(str->next) = '\0';
			str->next++;
			foundSeparator = true;
		}

		if (foundSeparator && i > 0)
			break;

		if (i == 0)
			result = str->next;
	}

	return result;
}

void removeMyString(MyString *str)
{
	delete[] str->separators;
	delete[] str->begin;

	str->begin = NULL;
	str->next = NULL;
	str->end = NULL;
	str->separators = NULL;
}

char *gettok(MyString *str, int n)
{
	// for(const char *curr = mystrtok(str); *curr != '\0'; curr = mystrtok(str));

	char *result = str->begin;

	if (*str->begin != '\0')
		n--;

	for (char *curr = str->begin; n > 0 && curr != str->end; curr++)
	{
		if (*curr == '\0')
		{

			while (*curr == '\0')
				curr++;

			n--;
			result = curr;
		}
	}

	return result;
}
