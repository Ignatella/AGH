#include "Element.h"
#include <iostream>

using namespace std;

Element::Element(const char *name)
{
	this->name = name;
	this->next = NULL;
}

Element *Element::getNext()
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

Element::~Element()
{
	cout << "Destruktor Element: " << this->getName() << endl;
}
