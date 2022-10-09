#pragma once

#include "Node.h"

#include <iostream>

/**
 * @brief Lista cykliczna
 * 
 */
class CyclicList
{
private:
    /**
     * @brief Pierwszy element na liscie
     * 
     */
    Node *_first;

    /**
     * @brief Ostatni element na liscie
     * 
     */
    Node *_last;

public:
    /**
     * @brief Tworzy liste
     * 
     */
    CyclicList() : _first(nullptr), _last(nullptr){};

    /**
     * @brief Konstruktor kopijacy
     * 
     * @param c 
     */
    CyclicList(const CyclicList &c)
    {
        if (c._first == nullptr)
            return;

        Node *next = c._first->getNext();

        _first = c._first->clone();
        Node *mCurr = _first;

        for (; next != c._first; next = next->getNext())
        {
            mCurr->setNext(next->clone());
            mCurr = mCurr->getNext();
        }

        _last = mCurr;
        _last->setNext(_first);
    }

    /**
     * @brief Zwraca ilosc elementow na liscie
     * 
     * @return unsigned int 
     */
    unsigned int count() const
    {
        unsigned int count = 0;

        Node *curr = _first;
        if (curr == nullptr)
            return count;

        for (bool firstI = true; firstI || curr != _first; count++, curr = curr->getNext(), firstI = false)
            ;

        return count;
    };

    /**
     * @brief Przesuwa liste w lewo
     * 
     * @return CyclicList& 
     */
    CyclicList &rotate()
    {
        if (_first == nullptr)
            return *this;

        _last = _first;
        _first = _first->getNext();

        return *this;
    }

    /**
     * @brief Przesuwa liste w prawo
     * 
     * @return CyclicList& 
     */
    CyclicList &rotate_back()
    {
        unsigned int len = count();

        for (size_t i = 0; i < len - 1; i++)
            rotate();

        return *this;
    }

    /**
     * @brief Zwraca pierwszy element na liscie
     * 
     * @return Node* 
     */
    Node *operator()() { return _first; };

    /**
     * @brief Dodaje element na koniec listy
     * 
     * @param n 
     * @return CyclicList& 
     */
    CyclicList &operator<<(Node *n)
    {
        if (_first == nullptr)
        {
            _first = n;
            _last = n;
            _last->setNext(n);
            return *this;
        }

        _last->setNext(n);
        _last = n;
        n->setNext(_first);

        return *this;
    };

    /**
     * @brief Wypisuje liste na ekran
     * 
     * @param os 
     * @param c 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &os, const CyclicList &c)
    {
        Node *curr = c._first;
        if (curr == nullptr)
            return os;

        for (bool firstI = true; firstI || curr != c._first; curr = curr->getNext(), firstI = false)
            os << curr->toString() << " ";

        return os;
    }

    /**
     * @brief Usuwa liste z pamieci
     * 
     */
    ~CyclicList()
    {
        Node *curr = _first;

        if (curr == nullptr)
            return;

        for (Node *next = curr->getNext(); curr != _last;)
        {
            delete curr;
            curr = next;
            next = next->getNext();
        }

        delete curr;
    }
};
