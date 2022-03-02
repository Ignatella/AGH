#include <MyList.h>
#include <iostream>

using namespace std;

Element *Element::createElement(const char *name)
{
	Element *created = new Element;
	created->init(name);
	return created;
}

void Element::init(const char *name)
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

void Element::clear(Element *element)
{
	cout << "Clear Element: " << element->getName() << endl;
	delete element;
}

void MyList::init(const char *name)
{
	this->name = name;
	this->head = NULL;
	this->tail = NULL;
}

void MyList::append(const char *data)
{
	Element *created = Element::createElement(data);
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

	Element::clear(head);

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
		Element::clear(current);
		current = next;
	}

	this->head = NULL;
	this->tail = NULL;
}

void MyList::clear()
{
	cout << "CLear MyList: " << this->name << endl;
	this->clearList();
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