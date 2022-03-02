#pragma once

#include "Element.h"

class MyList
{
private:
    const char *name;
    Element *head;
    Element *tail;

public:
    MyList(const char *name);
    //void init(const char *name);
    void append(const char *data);
    void append(Element *element);
    const char *getName() const;
    Element *getHead() const;
    Element *getLast() const;
    bool isEmpty() const;
    void removeFirst();
    void clearList();
    // void clear();
    ~MyList();
};

void print(const MyList *list);

