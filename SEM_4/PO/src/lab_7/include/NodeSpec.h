#pragma once

#include "Node.h"

#include <string>

/**
 * @brief Element na liscie przechowujacy int
 * 
 */
class NodeInt : public Node
{
private:
    /**
     * @brief Przechowywana wartosc
     * 
     */
    int _v;

public:
    /**
     * @brief Tworzy element
     * 
     * @param v 
     */
    NodeInt(int v) : _v(v){};

    /**
     * @brief Konwertuje element na string
     * 
     * @return std::string 
     */
    std::string toString() const override { return std::to_string(_v); };

    /**
     * @brief Tworzy kopije elementu
     * 
     * @return Node* 
     */
    Node *clone() const override { return new NodeInt(_v); };

    /**
     * @brief Zwraca przechowywana wartosc
     * 
     * @return int& 
     */
    int &valInt() { return _v; };
};

/**
 * @brief Element na liscie przechowujacy float
 * 
 */
class NodeFloat : public Node
{
private:
    /**
     * @brief Przechowywana wartosc
     * 
     */
    float _v;

public:
    /**
     * @brief Tworzy element
     * 
     * @param v 
     */
    NodeFloat(float v) : _v(v){};

    /**
     * @brief Konwertuje element na string
     * 
     * @return std::string 
     */
    std::string toString() const override { return std::to_string(_v); };

    /**
     * @brief Tworzy kopije elementu
     * 
     * @return Node* 
     */
    Node *clone() const override { return new NodeFloat(_v); };

    /**
     * @brief Zwraca przechowywana wartosc
     * 
     * @return int& 
     */
    float &valFloat() { return _v; };
};

/**
 * @brief Element na liscie przechowujacy string
 * 
 */
class NodeString : public Node
{
private:
    /**
     * @brief Przechowywana wartosc
     * 
     */
    std::string _v;

public:
    /**
     * @brief Konwertuje element na string
     * 
     * @return std::string 
     */
    NodeString(std::string v) : _v(v){};

    /**
     * @brief Konwertuje element na string
     * 
     * @return std::string 
     */
    std::string toString() const override { return _v; };

    /**
     * @brief Tworzy kopije elementu
     * 
     * @return Node* 
     */
    Node *clone() const override { return new NodeString(_v); };

    /**
     * @brief Zwraca przechowywana wartosc
     * 
     * @return int& 
     */
    std::string &valString() { return _v; };
};
