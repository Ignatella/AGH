/*
Zadanie służy przetestowaniu konstruktorów kopiujących i przenoszących oraz operatora = w dziedziczeniu.
Należy zaimplementować następujące klasy:
* RNA - implementuje dowolną sekwencję nukleotydów - łańcuch RNA.
  Nukleotydy są nowym typem enum. Deklaracja tej klasy oraz typu 'Nukleotyp' jest dana, należy jedynie dopisać plik 'rna.cpp'.
  Uwaga! Można mutować łańcuch.
* Virus (virus.h) - klasa implemetuje wirus o następujących cechach:
  - nazwa
  - łańcuch RNA (dynamiczny obiekt RNA)
  - "wiek" wirusa - ilość wyprodukowanych pokoleń (bez mutacji)
	Wiek wirusa zwiększa się o jeden, po każdej replikacji (skopiowaniu konstr. kopiującym).
	Na przykład, jeśli wiek wirusa vir1 wynosi 1, to nowy wirus vir2 utworzony przez instrukcję 'Virus vir2(vir1)' bedzie miał wiek 0, zaś vir1 wiek 2.
* AnimalVirus (animalvirus.h) - klasa pochodna klasy Virus, implementująca wirusy przenoszone przez zwierzęta.
  Dodatkową cechą klasy AnimalVirus jest:
  - nazwa zwierzęcia, które jest hostem wirusa.
UWAGI:
*  Aby program działał poprawnie, odpowiednie klasy muszą posiadać niedomyślne konstruktory kopiujące/przenoszące oraz operatory=.
*
*/
//-----------------------------------------------------

#include <iostream>

#include "rna.h"
#include "virus.h"
#include "animalvirus.h"

using namespace std;

/// Funkcja pomocnicza, do sprawdzania konstruktora przenoszącego.
template <class T>
T my_copy(T a)
{
	return a;
}

//----------------------------------------------------
int main()
{
	// tworzymy dwie sekwencje genów
	RNA rna1(vector<Nukleotyp>({A, C, A, T, A, G, A, C, T, A, G, T, C, A, T}));
	RNA rna2(vector<Nukleotyp>({C, A, T, C, C, A, G, A, G, T, A, C, T, C, A}));
	cout << "RNA1: " << rna1 << "RNA2: " << rna2;
	// mutujemy RNA - przesuwamy rotacyjnie w lewo
	cout << "MUTATED RNA2: " << rna2.mutate();

	// tworzymy nowego wirusa (z pustą informacją o kodzie RNA)
	Virus vir1("RSV");
	cout << "Wirus: " << vir1.get_name() << " " << vir1.get_RNA() << endl;
	// dodajemy sekwencję RNA
	vir1.set_RNA(vector<Nukleotyp>({A, C, U, A, G, G, U, A, U, G, A}));
	cout << "RNA: " << *vir1.get_RNA() << endl;

	// reprodukcja i zliczanie pokoleń wirusów (my_copy jest moje)
	// trzeba podefiniować odpowiednie konstruktory i op =
	// nie zapomnieć o mutacji
	Virus vir2 = Virus(my_copy(vir1)); // z mutacją
	Virus vir3(vir1);				   // bez mutacji
	Virus vir4(my_copy(vir3));		   // z mutacją
	cout << "Pokolenia: " << endl;	   // 0 1 2
	cout << "Vir1 - Wiek: " << vir1.get_age() << "  RNA: " << *vir1.get_RNA();
	cout << "Vir2 - Wiek: " << vir2.get_age() << "  RNA: " << *vir2.get_RNA();
	cout << "Vir3 - Wiek: " << vir3.get_age() << "  RNA: " << *vir3.get_RNA();
	cout << "Vir4 - Wiek: " << vir4.get_age() << "  RNA: " << *vir4.get_RNA() << endl;

	Virus vir5 = Virus(vir1); // z mutacją
	cout << "Pokolenia:" << endl;
	cout << "Vir1 - Wiek: " << vir1.get_age() << "  RNA: " << *vir1.get_RNA();
	cout << "Vir5 - Wiek: " << vir5.get_age() << "  RNA: " << *vir5.get_RNA() << endl;

	// tworzymy nowego wirusa przenoszonego przez zwierzęta,
	// podając nazwę wirusa, nazwę zwierzęcia, od którego pochodzi oraz kod RNA
	AnimalVirus avir("Koronawirus", "nietoperz", rna1.get_RNA());
	cout << "Wirus: " << avir.get_name() << endl;
	cout << "Nosiciel: " << avir.get_animal_host() << endl;
	cout << "RNA: " << *avir.get_RNA() << endl;

	AnimalVirus avir1("Chikungunya", "komar", vector<Nukleotyp>({U, C, A, A, U, C, C, U, C, A, U, C, A}));
	cout << "Wirus: " << avir1.get_name() << endl;
	cout << "Nosiciel: " << avir1.get_animal_host() << endl;
	cout << "RNA: " << *avir1.get_RNA();

	AnimalVirus avir2 = AnimalVirus() = (my_copy(avir1)); // z mutacją = AnimalVirus(my_copy (avir1))
	cout << "AVir1 - Wiek: " << avir1.get_age() << "  RNA: " << *avir1.get_RNA();
	AnimalVirus avir3(avir1); // bez mutacji
	cout << "Wirus: " << avir2.get_name() << " Pokolenia: " << endl;
	cout << "AVir1 - Wiek: " << avir1.get_age() << "  RNA: " << *avir1.get_RNA();
	cout << "AVir2 - Wiek: " << avir2.get_age() << "  RNA: " << *avir2.get_RNA();
	cout << "AVir3 - Wiek: " << avir3.get_age() << "  RNA: " << *avir3.get_RNA();
	return 0;
}
// =======================================================================

/* *** Oczekiwane wyjście
RNA1: A C A T A G A C T A G T C A T
RNA2: C A T C C A G A G T A C T C A
MUTATED RNA2: A T C C A G A G T A C T C A C
Wirus: RSV 0
RNA: A C U A G G U A U G A
Pokolenia:
Vir1 - Wiek: 2  RNA: A C U A G G U A U G A
Vir2 - Wiek: 0  RNA: C U A G G U A U G A A
Vir3 - Wiek: 1  RNA: A C U A G G U A U G A
Vir4 - Wiek: 0  RNA: C U A G G U A U G A A
Pokolenia:
Vir1 - Wiek: 3  RNA: A C U A G G U A U G A
Vir5 - Wiek: 0  RNA: A C U A G G U A U G A
Wirus: Koronawirus
Nosiciel: nietoperz
RNA: A C A T A G A C T A G T C A T
Wirus: Chikungunya
Nosiciel: komar
AVir1 - Wiek: 1  RNA: U C A A U C C U C A U C A
Wirus: Chikungunya  Pokolenia:
AVir1 - Wiek: 2  RNA: U C A A U C C U C A U C A
AVir2 - Wiek: 0  RNA: C A A U C C U C A U C A U
AVir3 - Wiek: 0  RNA: U C A A U C C U C A U C A
*/