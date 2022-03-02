#pragma once

/**
 * @brief Abstrakcja przedstawiajaca studenta
 * 
 */
class Student
{
private:
    /**
     * @brief Id studenta
     * 
     */
    int id;
public:
    /**
     * @brief Tworzy nowego studenta
     * 
     * @param id studenta
     */
    Student(int id);

    /**
     * @brief Pobiera id studenta (getter)
     * 
     * @return int id studenta
     */
    int getId() const;

    /**
     * @brief Wypisuje informacje o studencie oraz jego oceny
     * 
     */
    void print() const;
};
