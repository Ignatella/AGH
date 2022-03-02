#include "Element.h"
#include <iostream>
#include <cstring>

using namespace std;

Element::Element(const char *name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	this->next = NULL;
}

Element::~Element()
{
	if (this->name != NULL)
	{
		cout << "Destruktor Element: " << this->getName() << endl;
		delete[] this->name;
	}
}

Element *Element::getNext() const
{
	return this->next;
}

void Element::setNext(Element *element)
{
	this->next = element;
}

void Element::printName() const
{
	cout << this->name;
}

const char *Element::getName() const
{
	return this->name;
}
