#pragma once

#include <string>

/**
 * @brief Przedstawia klasa nadrzedna dla klasy Dir i File
 *
 */
class Node
{
protected:
    /**
     * @brief Nazwa elementu
     *
     */
    std::string _name;

    /**
     * @brief Tworzy element z nazwa
     *
     * @param name
     */
    Node(std::string name) : _name(name){};

public:
    /**
     * @brief Wymuszamy kopiowanie poprzez copy
     * 
     */
    Node(const Node &) = delete;

    /**
     * @brief Wypisuje element na ekran
     *
     * @param indents
     */
    virtual void print(int indents) const
    {
        for (size_t i = 0; i < indents; i++)
            std::cout << "  ";
    };

    /**
     * @brief Zwraca nazwe elementu
     *
     * @return std::string
     */
    std::string getName() const { return _name; };

    /**
     * @brief Wymuszamy kopiowanie poprzez copy
     * 
     * @return Node& 
     */
    Node &operator=(const Node &) = delete;

    /**
     * @brief Usuwa element z pamieci
     *
     */
    virtual ~Node(){};
};
