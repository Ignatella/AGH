#pragma once
#include "Student.h"

/**
 * @brief Ocena studenta
 * 
 */
class Grade
{
private:
    /**
     * @brief IdSeed istnieje, aby zawsze byl unikalny id (id tylko rosnie)
     * 
     */
    static int idSeed;

    /**
     * @brief Ilosc ocen w tablicy ocen
     * 
     */
    static int gradeCount;

    /**
     * @brief Oceny wszystkich studentow
     * 
     */
    static Grade **grades;

    /**
     * @brief Dodaje Grade do tablicy ocen
     * 
     * @param grade ocena, ktora dodajemy do talblicy ocen
     */
    static void addGrade(Grade *grade);

    /**
     * @brief Id oceny
     * 
     */
    int id;

    /**
     * @brief Nazwa przedmiotu
     * 
     */
    char *name;

    /**
     * @brief Ocena
     * 
     */
    double grade;

    /**
     * @brief Student, do ktorego nalezy ocena
     * 
     */
    const Student &student;

public:
    /**
     * @brief Pobiera wszystkie oceny (getter)
     * 
     * @return Grade** wskaznik na liste ocen
     */
    static Grade **getGrades();

    /**
     * @brief Pobiera ilosc ocen w tablicy ocen (getter)
     * 
     * @return int 
     */
    static int getCount();

    /**
     * @brief Tworzy nowy Grade
     * 
     * @param name nazwa przedmioutu
     * @param grade ocena
     * @param student student, ktory otrzymal ocene
     */
    Grade(const char *name, double grade, const Student &student);

    /**
     * @brief Wypisuje ocene
     * 
     */
    void print() const;

    /**
     * @brief Pobiera ocene (getter)
     * 
     * @return double ocena
     */
    double getGrade() const;

    /**
     * @brief Pobiera nazwe przedmiout (getter)
     * 
     * @return char* nazwa przedmiotu
     */
    char *getName() const;

    /**
     * @brief Pobiera studenta, ktory otrzymal ocene (getter)
     * 
     * @return const Student& 
     */
    const Student &getStudent() const;

    /**
     * @brief Usuwa Grade z pamieci
     * 
     */
    ~Grade();
};
