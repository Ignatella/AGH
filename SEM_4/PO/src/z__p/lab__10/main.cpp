/*
Proszę zdefiniować klasy reprezentujące żelazka marki Philips i Tefal.
Każde żelazko ma nazwę, cenę i aktualną temperaturę oraz maksymalny zakres temperatur (temperatura to liczba całkowita od 1 do 9, przy czym każdy model żelazka może mieć inny zakres - mniejszy).
Tefal ma zakres do 7, natomiast Philips ma zakres temperatur do 5.

Proszę zdefiniować również klasy reprezentujace różne rodzaje ubrań.
Każde ubranie:
* ma swoją nazwę i cenę oraz maksymalny zakres temperatury do prasowania, ustawiony domyślnie na 9,
* może być pogniecione lub wyprasowane,
* można prasować lub gnieść.
* jedwab prasujemy maks. na 3 stopniu a bawełnę na 7
Dodatkowo spodnie mogą mieć albo nie mieć wyprasowane kanty na nogawkach.

UWAGA!
* Koszula nie ma kantów na nogawkach, spodnie nie mają rękawów
* Ubrania wyprasowanego nie prasujemy ponownie.
* Stan i prasowanie kantów na nogawkach nie ma nic wspólnego z ogólnym stanem lub prasowaniem.
* Nowe ubranie zawsze wymaga prasowania.
* Nie należy definiować każdej klasy w osobnym pliku, raczej je pogrupować: klasa ogólna w main.h, klasy związane z zelazkiem w zelazko.h, klasy zwiazane z ubraniami w ubrania.h
Konstruktory proszę zdefiniować w klasach w listach inicjalizacyjnych.
* Proszę jak najoptymalniej zdefiniować strukturę klas, wyłaniając części wspólne -  to będzie znacząco wpływać na ocenę.

W zadaniu zaleca się korzystanie z elementów bilbioteki standardowej (std::string)
*/

#include "main.h"
#include "zelazko.h"
#include "ubranie.h"

int main()
{
  const double cenaZelazka = 135;
  ZelazkoPhilips zelazko1(cenaZelazka); // =zakres prasowania 5
  zelazko1.UstawTemperature(6);         // Ten model nie obsluguje takiego zakresu temperatur
  zelazko1.Wypisz();                    // Philips cena: 135. Temperatura: 0 Zakres 5
  zelazko1.UstawTemperature(5);
  zelazko1.Wypisz(); // Philips cena: 135. Temperatura: 5 Zakres 5

  std::cout << "\n==== Koszula bawelniana ====\n";
  const double cenaKoszuli = 200;
  KoszulaBawelniana koszula1(cenaKoszuli, 1); // =długi rękaw, temp prasowania maks 7
  koszula1.Wypisz();                          // Koszula bawelniana cena: 200. pogniecione. Dlugi rekaw.
  koszula1.SkrocRekawy();
  koszula1.Prasuj(zelazko1); // ---Prasuje Koszula bawelniana zelazkiem o temp. 5.
  koszula1.Wypisz();         // Koszula bawelniana cena: 200. Wyprasowane. Krotki rekaw.

  std::cout << "\n==== Koszula jedwabna ====\n";
  KoszulaJedwabna koszula2(300, 0); //=temp prasowania maks 3
  koszula2.Wypisz();                // Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Rekaw: krotki.
  koszula2.Prasuj(zelazko1);        // Zelazko za gorace.
  zelazko1.UstawTemperature(3);
  koszula2.Prasuj(zelazko1); // Prasuje Koszula jedwabna zelazkiem o temp. 3.
  koszula2.Prasuj(zelazko1); // Ubranie nie wymaga prasowania.

  std::cout << "\n==== Spodnie bawelniane ====\n";
  SpodnieBawelniane spodnie1(55);
  spodnie1.Wypisz();         // Spodnie bawelniane cena: 55. Pogniecione. Brak kantow.
  spodnie1.Prasuj(zelazko1); // Prasuje Spodnie bawelniane zelazkiem o temp. 3.
  spodnie1.Wypisz();         // Spodnie bawelniane cena: 55. Wyprasowane. Brak kantow.
  spodnie1.Prasuj(zelazko1); // Ubranie nie wymaga prasowania.

  std::cout << "\n==== Spodnie jedwabne ====\n";
  SpodnieJedwabne spodnie2(234);
  spodnie2.Wypisz();              // Spodnie jedwabne cena: 234. Pogniecione. Brak kantow.
  spodnie2.PrasujKanty(zelazko1); // Prasuje kanty Spodnie jedwabne zelazkiem o temp.3
  spodnie2.Wypisz();              // Spodnie jedwabne cena: 234. Pogniecione. Kanty.
  spodnie2.PrasujKanty(zelazko1); // Ubranie ma kanty.

  Ubranie *koszUbran[4];
  koszUbran[0] = &koszula1;
  koszUbran[1] = &koszula2;
  koszUbran[2] = &spodnie1;
  koszUbran[3] = &spodnie2;

  std::cout << "\n";
  std::cout << "===== GNIECIEMY =====\n";
  Ubranie **koniecKosza = koszUbran + 4;
  for (Ubranie **ciuch = koszUbran; ciuch != koniecKosza; ++ciuch)
  {
    (*ciuch)->Pogniec();
    (*ciuch)->Wypisz();
    std::cout << "\n";
  }
  std::cout << "\n";

  ZelazkoTefal zelazko2(333);
  zelazko2.UstawTemperature(7);
  zelazko2.Wypisz(); // Tefal cena: 333. temperatura: 7
  zelazko2.UstawTemperature(2);

  std::cout << "\n";
  std::cout << "===== PRASUJEMY =====\n";
  for (Ubranie **ciuch = koszUbran; ciuch != koniecKosza; ++ciuch)
  {
    (*ciuch)->Prasuj(zelazko2);
    (*ciuch)->Wypisz();
    std::cout << "\n";
  }

  return 0;
}
/*
Ten model nie obsluguje takiego zakresu temperatur.
Philips cena: 135. temperatura: 0
Philips cena: 135. temperatura: 5

==== Koszula bawelniana ====
Koszula bawelniana cena: 200. Pogniecione. Dlugi rekaw.
---Prasuje Koszula bawelniana zelazkiem o temp. 5.
Koszula bawelniana cena: 200. Wyprasowane. Krotki rekaw.

==== Koszula jedwabna ====
Koszula jedwabna cena: 300. Pogniecione. Krotki rekaw.
Zelazko za gorace.
---Prasuje Koszula jedwabna zelazkiem o temp. 3.
---Ubranie nie wymaga prasowania.

==== Spodnie bawelniane ====
Spodnie bawelniane cena: 55. Pogniecione. Brak kantow.
---Prasuje Spodnie bawelniane zelazkiem o temp. 3.
Spodnie bawelniane cena: 55. Wyprasowane. Brak kantow.
---Ubranie nie wymaga prasowania.

==== Spodnie jedwabne ====
Spodnie jedwabne cena: 234. Pogniecione. Brak kantow.
---Prasuje nogawki Spodnie jedwabne zelazkiem o temp.3
Spodnie jedwabne cena: 234. Pogniecione. Kanty.
Ubranie ma kanty.

===== GNIECIEMY =====
Koszula bawelniana cena: 200. Pogniecione.
Koszula jedwabna cena: 300. Pogniecione.
Spodnie bawelniane cena: 55. Pogniecione.
Spodnie jedwabne cena: 234. Pogniecione.

Tefal cena: 333. Temperatura: 7 Zakres: 7.

===== PRASUJEMY =====
---Prasuje Koszula bawelniana zelazkiem o temp. 2.
Koszula bawelniana cena: 200. Wyprasowane.
---Prasuje Koszula jedwabna zelazkiem o temp. 2.
Koszula jedwabna cena: 300. Wyprasowane.
---Prasuje Spodnie bawelniane zelazkiem o temp. 2.
Spodnie bawelniane cena: 55. Wyprasowane.
---Prasuje Spodnie jedwabne zelazkiem o temp. 2.
Spodnie jedwabne cena: 234. Wyprasowane.
*/
