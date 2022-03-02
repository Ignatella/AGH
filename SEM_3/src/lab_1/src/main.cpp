/*
 Dany jest program, który celowo zawiera błędy
 1. Skompiluj program ręcznie do pliku wykonywalnego main. Zrób to dwuetapowo.
 2. Odkomentuj #define SEGFAULT, skompiluj i uruchom.
 3. Zakomentuj #define SEGFAULT, skompiluj program z flagą -DSEGFAULT i spróbuj uruchomić program.
 4. Uruchom valgrind ./main dla wersji z segmentation fault
 5. Skompiluj program dodatkowo z flagą -g, uruchom gdb ./main plik_core_dump, następnie run i spróbuj zlokalizować segmentation fault. Jeśli plik core się nie wygenerował, uruchom wcześniej ulimit -c unlimited
(https://chyla.org/artykuly/linux/core-dump.html, https://chyla.org/artykuly/cpp/gdb-tutorial.html)
 6. Prześledź za pomocą gdb krok po kroku działającą wersję programu, ustawiając breakpoint na pętli for (zapoznaj się z dołączonym plikiem How-to-Use-GDB.pdf)
 ------------------------------------------
 Zadania do wykonania po przećwiczeniu makefile na drugim przykładzie w katalogu Kompilacja. Polecam materiały:
   https://www.bezkompilatora.pl/automatyzacja-budowania-makefile-czesc-1/
   https://www.bezkompilatora.pl/automatyzacja-budowania-projektu-z-uzyciem-makefile-czesc-2/
   https://www.bezkompilatora.pl/reguly-niejawne-i-pliki-naglowkowe-w-makefile/

 7. Na podstawie przykładów oraz pliku GnuMake.pdf napisz własny makefile, który po wywołaniu:
    make clean - usunie niepotrzebne pliki
    make run - uruchomi program
    make check  - uruchomi valgrind ./main
    make debug - uruchomi gdb ./main
    make ERROR - skompiluje program z flagą -DSEGFAULT 
    make all - komiluje, uruchamia i czyści.
 8*. Popraw program, aby wyeliminować warning i jednocześnie seqmentation fault.
*/

#include <iostream>

// #define SEGFAULT

int main() {
  char str1[]="kajak";
  char *str2;

  str2 = "kajak"; //bez alokacji pamięci nie powinniśmy tego zrobić   
 
  *(str1+2)='a'; 
  
  #ifdef SEGFAULT
    *(str2+2)='a';
  #endif
  //wypisywanie w pętli dla debugera
  for (int i=0; i<5;i++)
    std::cout << *(str1+i);
  std::cout << std::endl;
  std::cout << str2 << std::endl;

  return 0;
}