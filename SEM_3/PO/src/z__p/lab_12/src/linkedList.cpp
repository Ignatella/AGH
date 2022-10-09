#include "linkedList.h"
#include <string>
#include <utility>

LinkedList::LinkedList() : LinkedList("LX") {}

LinkedList::LinkedList(std::string name) : name(name), head(nullptr) {}

LinkedList::LinkedList(LinkedList &&l) : name(std::exchange(l.name, "LX")), head(std::exchange(l.head, nullptr)) {}

LinkedList::LinkedList(const LinkedList &p) : LinkedList(p.name)
{
    Point *curr = p.head;

    while (curr != nullptr)
    {
        append(*curr);
        curr = curr->getNext();
    }
}

void LinkedList::append(const Point &p)
{
    if (contains(p))
        return;

    Point *created = new Point(p);
    created->setNext(nullptr);

    if (count == 0)
        head = created;
    else
        last()->setNext(created);

    count++;
}

void LinkedList::addSorted(const Point &p)
{
    if (contains(p))
        return;

    Point *created = new Point(p);

    if (count == 0)
    {
        head = created;
        created->setNext(nullptr);
    }
    else
    {
        Point *curr = head;

        while (curr->getNext() != nullptr && *(curr->getNext()) < *created)
            curr = curr->getNext();

        if (*created < *head)
        {
            created->setNext(head);
            head = created;
        }
        else
        {
            Point *next = curr->getNext();
            curr->setNext(created);
            created->setNext(next);
        }
    }

    count++;
}

bool LinkedList::contains(const Point &p) const
{
    Point *curr = head;

    while (curr != nullptr)
    {
        if (*curr == p)
            return true;
        curr = curr->getNext();
    }

    return false;
}

Point *LinkedList::last() const
{
    if (head == nullptr)
        return nullptr;

    Point *curr = head;

    while (curr->getNext() != nullptr)
        curr = curr->getNext();

    return curr;
}

void print(const LinkedList &l)
{
    std::cout << l;
}

void LinkedList::removeLast()
{
    if (head == nullptr)
        return;

    Point *curr = head;
    Point *l = last();

    if (l == curr)
    {
        delete head;
        head = nullptr;
    }

    while (curr->getNext() != l)
        curr = curr->getNext();

    delete l;
    curr->setNext(nullptr);
    count--;
}

LinkedList LinkedList::operator=(const LinkedList &p)
{
    Point *curr = p.head;

    while (curr != nullptr)
    {
        append(*curr);
        curr = curr->getNext();
    }

    return *this;
}

LinkedList LinkedList::operator+(const LinkedList &l) const
{
    LinkedList result;

    result += *this;
    result += l;

    return result;
}

LinkedList &LinkedList::operator--(int)
{
    this->removeLast();
    return *this;
}

LinkedList &LinkedList::operator+=(const LinkedList &list)
{
    if (list.head == nullptr)
        return *this;

    Point *curr = list.head;

    while (curr != nullptr)
    {
        *this += *curr;
        curr = curr->getNext();
    }

    return *this;
}

LinkedList &LinkedList::operator+=(const Point &p)
{
    this->addSorted(p);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const LinkedList &l)
{
    std::cout << l.name << "=[";

    Point *curr = l.head;
    while (curr != nullptr)
    {
        std::cout << *curr << ", ";
        curr = curr->getNext();
    }

    if (l.head != nullptr)
        std::cout << "\b\b";

    std::cout << "]" << std::endl;

    return os;
}

LinkedList::~LinkedList()
{
    if (head == nullptr)
        return;

    Point *curr = head;

    while (curr != nullptr)
    {
        Point *next = curr->getNext();
        delete curr;
        curr = next;
    }
}
