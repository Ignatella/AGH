#pragma once

class Element
{
public:
    static Element *createElement(const char *name);
    static void clear(Element *element);

private:
    const char *name;
    Element *next;

public:
    void init(const char *name);
    void printName() const;
    const char *getName() const;

    Element *getNext();
    void setNext(Element *element);
};

class MyList
{
private:
    const char *name;
    Element *head;
    Element *tail;

public:
    void init(const char *name);
    void append(const char *data);
    void append(Element *element);
    const char *getName() const;
    Element *getHead() const;
    Element *getLast() const;
    bool isEmpty() const;
    void removeFirst();
    void clearList();
    void clear();
};

void print(const MyList *list);
