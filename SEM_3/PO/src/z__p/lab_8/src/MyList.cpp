#include "MyList.h"
#include "Element.h"
#include <iostream>

using namespace std;


MyList::MyList(const char *name) { 
// 	this->name = name;
// 	this->head = NULL;
// 	this->tail = NULL;
}

// void MyList::init(const char *name)
// {
// 	this->name = name;
// 	this->head = NULL;
// 	this->tail = NULL;
// }

void MyList::append(const char *data)
{
	Element *created = new Element(data);
	this->append(created);
}

// void MyList::append(Element *element)
// {
// 	if (this->isEmpty())
// 		this->head = element;
// 	else
// 		this->tail->setNext(element);

// 	this->tail = element;
// }

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

// void MyList::clear()
// {
// 	cout << "CLear MyList: " << this->name << endl;
// 	this->clearList();
// }

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