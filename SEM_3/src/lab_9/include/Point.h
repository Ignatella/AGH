#pragma once

/**
 * @brief Punkt na mapie
 * 
 */
class Point
{
public:
    /**
     * @brief Ilosc objektow Point w pamieci w obecnej chwili
     * 
     */
    static int number;

private:
    /**
     * @brief Zrodlo id, zapewnia, aby id bylo unikatowe
     * 
     */
    static int idSeed;

    /**
     * @brief Id punktu
     * 
     */
    int id;

    /**
     * @brief Wspolrzedne punktu na mapie (x - dlugosc) (y - szerokosc)
     * 
     */
    double x, y;

    /**
     * @brief Nazwa punktu
     * 
     */
    char *name;

private:
    /**
     * @brief Ustawia id punktu (helper)
     * 
     */
    void setId();

public:
    /**
     * @brief Tworzy pusty Punkt, x = 0, y = 0, name = nullptr
     * 
     */
    Point();

    /**
     * @brief Tworzy Punkt o zadanych wartosciach
     * 
     * @param name Nazwa punktru
     * @param x Wspolrzedna x (dlugosc)
     * @param y Wspolrzedna y (szerokosc)
     */
    Point(const char *name, double x, double y);

    /**
     * @brief Tworzy punkt o zadanych x i y
     * 
     * @param x Wspolrzedna x (dlugosc)
     * @param y Wspolrzedna y (szerokosc)
     * @return Utworzony punkt
     */
    static Point setPoint(double x, double y);

    /**
     * @brief Tworzy punkt o wartosciach -x i -y
     * 
     * @param x Wspolrzedna x (dlugosc)
     * @param y Wspolrzedna y (szerokosc)
     * @return Utworzony punkt
     */
    static Point setContrary(double x, double y);

    /**
     * @brief Twory punkt na podstawie objektu na ktorym jest wywolana
    
     * 
     * @param name Nazwa punktu
     * @param x Przesuniecie wspolrzednej x
     * @param y Przesuniecie wspolrzednej y
     * @return Utworzony punkt
     */
    Point newMoved(const char *name, double x, double y);

    /**
     * @brief Konstruktor kopiujacy
     * 
     * @param point Punkt, ktory zostanie skopiowany
     */
    Point(const Point &point);

    /**
     * @brief Konstruktor przenoszacy
     * 
     * @param point Punkt, ktozy zostanie przeniesiony
     */
    Point(Point &&point);

    /**
     * @brief Wypisuje na ekran wartosci punktow w postaci
     * id. name (x, y)
     * 
     */
    void fullPrint() const;

    /**
     * @brief Zmienia nazwe punktu
     * 
     * @param newName Nowa nazwa punktu
     */
    void changeName(const char *newName);

    /**
     * @brief Pobiera x (dlugosc) punktu (getter)
     * 
     * @return double x (dlugosc) punktu
     */
    double getX() const;

    /**
     * @brief Pobiera y (szerokosc) punktu (getter)
     * 
     * @return double y (szerokosc) punktu
     */
    double getY() const;

    /**
     * @brief Pobiera nazwe punktu (getter)
     * 
     * @return char* 
     */
    char *getName() const;

    /**
     * @brief Usuwa punkt z pamieci
     * 
     */
    ~Point();
};

/**
 * @brief Porownuje wspolrzedna x (dlugosc) punktow p1 i p2
 * 
 * @param p1 pierwszy punkt
 * @param p2 drugi punkt
 * @return 1, jezeli p1.x < p2.x, -1 jezeli p1.x > p2.x, 0 w przeciwnym przypadku
 */
int compareX(const Point &p1, const Point &p2);

/**
 * @brief Porownuje wspolrzedna y (szerokosc) punktow p1 i p2
 *     
 * @param p1 pierwszy punkt
 * @param p2 drugi punkt
 * @return 1, jezeli p1.y < p2.y, -1 jezeli p1.y > p2.y, 0 w przeciwnym przypadku
 */
int compareY(const Point &p1, const Point &p2);

/**
 * @brief Wypisuje na ekran 
 * 
 * @param p1 pierwszy punkt
 * @param p2 drugi punkt
 * @param compFun funkcja, ktora porownuje punkt p1 z punktem p2
 */
void directions(const Point &p1, const Point &p2, int compFun(const Point &, const Point &));