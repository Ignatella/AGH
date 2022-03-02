#include "MyList.h"
#include "Element.h"
#include <iostream>
#include <cstring>

using namespace std;

MyList::MyList(const char *name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	this->head = NULL;
	this->tail = NULL;
}

MyList::~MyList()
{
	if (this->name != NULL)
	{
		cout << "Destruktor MyList: " << this->getName() << endl;
		this->clearList();
		delete[] this->name;
	}
}

void MyList::prepend(Element *element)
{
	element->setNext(this->head);
	this->head = element;
}

void MyList::append(const char *data)
{
	Element *created = new Element(data);
	this->append(created);
}

void MyList::append(Element *element)
{
	if (this->isEmpty())
		this->head = element;
	else
		this->tail->setNext(element);

	this->tail = element;
}

const char *MyList::getName() const
{
	return this->name;
}

Element *MyList::getHead() const
{
	return this->head;
}

Element *MyList::getLast() const
{
	return this->tail;
}

bool MyList::isEmpty() const
{
	return this->head == NULL && this->tail == NULL;
}

void MyList::removeFirst()
{
	if (this->isEmpty())
		return;

	Element *head = this->getHead();
	Element *next = head->getNext();

	delete head;

	this->head = next;
}

void MyList::clearList()
{
	if (isEmpty())
		return;

	Element *current = this->getHead();
	Element *next = NULL;

	while (current != NULL)
	{
		next = current->getNext();
		delete current;
		current = next;
	}

	this->head = NULL;
	this->tail = NULL;
}

void print(const MyList *list)
{
	Element *curr = list->getHead();

	cout << list->getName() << " = ";

	cout << "[";
	while (curr != NULL)
	{
		cout << curr->getName();
		if (curr->getNext() != NULL)
			cout << " ";
		curr = curr->getNext();
	}
	cout << "]" << endl;
}