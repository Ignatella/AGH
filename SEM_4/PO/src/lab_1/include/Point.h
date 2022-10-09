#pragma once

#include <iostream>
#include <utility>

/**
 * @brief Punkt we wspolrzednych x, y
 * 
 */
class Point
{
private:
    /**
     * @brief Nazwa punktu
     * 
     */
    std::string name_;

    /**
     * @brief Polozenie punktu we wspolrzednych x, y
     * 
     */
    double x_, y_;

    /**
     * @brief Numer porzadkowy punktu
     * 
     */
    unsigned int n_;

public:
    /**
     * @brief Seed numerow porzadkowych punktu
     * 
     */
    static unsigned int number;

public:
    /**
     * @brief Tworzy punkt
     * 
     */
    Point() : Point("", 0, 0){};

    /**
     * @brief Tworzy punkt o podanej nazwie i polozeniu
     * 
     * @param name nazwa punktu
     * @param x wspolrzedna x
     * @param y wspolrzedna y
     */
    Point(std::string name, double x, double y) : name_(name), x_(x), y_(y), n_(++number){};

    /**
     * @brief Konstruktor kopiujacy
     * 
     * @param p 
     */
    Point(const Point &p) : Point(p.name_, p.x_, p.y_)
    {
        std::cout << "--- Kopiujemy " << p.n_ << ". " << p.name_ << std::endl;
    };

    /**
     * @brief Konstruktor przenoszacy
     * 
     * @param p 
     */
    Point(Point &&p) : x_(std::exchange(p.x_, 0)), y_(std::exchange(p.y_, 0)), name_(std::move(p.name_)), n_(++number)
    {
        std::cout << "--- Przenosimy " << p.n_ << ". " << name_ << std::endl;
    };

    /**
     * @brief Tworzy punkt przeniesiony wzgledem tego
     * 
     * @param name 
     * @param dx 
     * @param dy 
     * @return Point 
     */
    Point newMoved(std::string name, double dx, double dy) { return Point(name, x_ + dx, y_ + dy); };\

    /**
     * @brief Tworzy punkt bez nazwy o podanych wspolrzednych
     * 
     * @param x 
     * @param y 
     * @return Point 
     */
    static Point setPoint(double x, double y) { return Point("Punkt X", x, y); };

    /**
     * @brief Tworzy punkt o wspolrzednych odwrotnych wzgledem podanych
     * 
     * @param x 
     * @param y 
     * @return Point 
     */
    static Point setContrary(double x, double y) { return Point{"Punk X", -x, -y}; };

    /**
     * @brief Wypisuje punkt na ekran
     * 
     */
    void fullPrint() const { std::cout << n_ << ". " << name_ << " (" << x_ << ", " << y_ << ")" << std::endl; };

    /**
     * @brief Zmienia nazwe punktu
     * 
     * @param new_name 
     */
    void changeName(std::string new_name) { name_ = new_name; };

    /**
     * @brief Usuwa punkt z pamieci
     * 
     */
    ~Point() { number--; };
};
