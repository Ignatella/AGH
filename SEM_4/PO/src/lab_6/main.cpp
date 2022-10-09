/*
Celem zadania jest przećwiczenie funkcji wirtualnych i napisanie hierarchii klas opisującej składniki systemu plików.
Składnikami tymi sa katalog (klasa Dir) i plik (klasa File), i przydałaby się jeszcze jakaś klasa nadrzędna. Pliki mają nazwę i rozmiar (podawany w nawiasach), katalogi nazwę i tablicę podrzędnych składników systemu plików.
Prosze uniemożliwić dziedziczenie po klasie Dir i uzasadnić słownie w komentarzu.

   UWAGA:
* Nazwy składników systemu plików proponuję przechowywać w std::string
* Implementacja klasy Dir może opierać się o std::vector (już wszyscy powinni go znać), ew. tablicę ograniczoną do 20 elementów). Tablica musi być tylko jedna wspólna dla plików i katalogów.
* Aby zapewnic wypisywanie z wcięciami, klasy te powinny posiadac metodę print z argumentem informujacym, ile spacji potrzeba wypisac przed nazwa (indentacja).
* Podczas kopiowania przydana bedzie polimorficzna metoda kopiujaca wywoływana przez copy.

Wskazówka do getDir(), jak wykorzystać dynamic_cast do rozpoznawania czy element wektora jest katalogiem
//wykonywane w pętli po elemencie el w wektorze
Dir * d = dynamic_cast<Dir *>(el);

std::string n=el->Element::get();
        if( n == _name)
            return d;
        if (d)
            return d -> getDir(_name);
 */

#include <iostream>
#include "Dir.h"
#include "File.h"

int main()
{
  std::cout << "------- Etap 1 -------\n";
  Dir *top = new Dir(".");
  Dir *home = new Dir("home");
  *top += home; // dodajemy do kat top podkatalog
  Dir *stud1 = new Dir("stud1");
  *home += stud1;
  Dir *stud2 = new Dir("stud2");
  *home += stud2;
  std::cout << const_cast<const Dir &>(*top) << std::endl;

  std::cout << "------- Etap 2 -------\n";
  *stud1 += new File("img1.jpg", 2020);
  *stud1 += new File("img2.jpg");
  Dir *work = new Dir("work");
  *work += new File("main.h", 150);
  *work += new File("proj.h", 175);
  *stud1 += work;
  std::cout << *home << std::endl;

#ifndef BASIC
  std::cout << "------- Etap 3 -------\n";
  stud2->copy(stud1->getDir("work")); // trzeba koniecznie zrobic kopie
  if (stud1->getDir("img1.jpg"))
    std::cout << "**** TO NIE POWINNO SIE WYPISAC ****\n";
  stud2->copy(stud1->get("img1.jpg"));
  *work += new Dir("tmp");
  Dir *tmp = static_cast<Dir *>(work->getDir("tmp"));
  *tmp += new Dir("cpp");
  std::cout << *(stud1->getDir("work"));
#endif

  // usuwanie
  *work -= "tmp";
  *work -= "proj.h";

  *work += new File("main.cpp"); // w kat: home/stud1/work pojawi sie nowy plik main.cpp, ktorego brak w kat home/stud2/work

  std::cout << "\n------ Cale drzewo -------" << std::endl;
  std::cout << *top;

  std::cout << "\n------- Czyszczenie -------" << std::endl;
  delete top;
}

/* oczekiwany wynik
./main
------- Etap 1 -------
. (dir)
  home (dir)
    stud1 (dir)
    stud2 (dir)

------- Etap 2 -------
home (dir)
  stud1 (dir)
    img1.jpg (2020)
    img2.jpg (0)
    work (dir)
      main.h (150)
      proj.h (175)
  stud2 (dir)

------- Etap 3 -------
work (dir)
  main.h (150)
  proj.h (175)
  tmp (dir)
    cpp (dir)
Destruktor Dir: tmp
Destruktor Dir: cpp
---Destruktor File: proj.h

------ Cale drzewo -------
. (dir)
  home (dir)
    stud1 (dir)
      img1.jpg (2020)
      img2.jpg (0)
      work (dir)
        main.h (150)
        main.cpp (175)
    stud2 (dir)
      work (dir)
        main.h (150)
        proj.h (175)
      img1.jpg (2020)

------- Czyszczenie -------
Destruktor Dir: .
Destruktor Dir: home
Destruktor Dir: stud1
---Destruktor File: img1.jpg
---Destruktor File: img2.jpg
Destruktor Dir: work
---Destruktor File: main.h
---Destruktor File: main.cpp
Destruktor Dir: stud2
Destruktor Dir: work
---Destruktor File: main.h
---Destruktor File: proj.h
---Destruktor File: img1.jpg

 */