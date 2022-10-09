#pragma once

#include <string>

/**
 * @brief Przedstawia element na liscie
 * 
 */
class Node
{
private:
    /**
     * @brief Wskaznik na nastepny element
     * 
     */
    Node *_next;

public:
    /**
     * @brief Tworzy element
     * 
     */
    Node() : _next(nullptr){};

    /**
     * @brief Pobiera nastepny element [getter]
     * 
     * @return Node* 
     */
    Node *getNext() { return _next; };

    /**
     * @brief Ustawia nastepny element [setter]
     * 
     * @param n 
     */
    void setNext(Node *n) { _next = n; };

    /**
     * @brief Konwertuje element na string
     * 
     * @return std::string 
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Tworzy kopije elementu
     * 
     * @return Node* 
     */
    virtual Node *clone() const = 0;
};
