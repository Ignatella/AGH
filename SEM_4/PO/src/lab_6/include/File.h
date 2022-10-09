#pragma once

#include "Node.h"

#include <string>

/**
 * @brief Klasa przedstawiajaca plik
 *
 */
class File : public Node
{
private:
    /**
     * @brief Rozmiar pliku
     *
     */
    unsigned int _size;

public:
    /**
     * @brief Tworzy plik
     *
     * @param name
     * @param size
     */
    File(std::string name, unsigned int size = 0) : Node(name), _size(size){};

    /**
     * @brief Kopiuje plik
     *
     * @return File*
     */
    File *copy() const
    {
        return new File(_name, _size);
    }

    /**
     * @brief Wypisuje plik na ekran
     *
     * @param indents
     */
    virtual void print(int indents = 0) const
    {
        Node::print(indents);

        std::cout << _name << " (" << _size << ")" << std::endl;
    };

    /**
     * @brief Wypisuje plik na ekran
     *
     * @param os
     * @param d
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const File &d)
    {
        d.print();
        return os;
    };

    /**
     * @brief Usuwa plik z pamieci
     *
     */
    virtual ~File()
    {
        std::cout << "---Destruktor File: " << _name << std::endl;
    };
};
