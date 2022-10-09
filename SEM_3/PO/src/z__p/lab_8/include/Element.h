#pragma once

class Element
{
public:
    // static Element *createElement(const char *name);
    // static void clear(Element *element);

private:
    const char *name;
    Element *next;

public:
    Element(const char *name);
    // void init(const char *name);
    void printName() const;
    const char *getName() const;

    Element *getNext();
    void setNext(Element *element);

    ~Element();
};