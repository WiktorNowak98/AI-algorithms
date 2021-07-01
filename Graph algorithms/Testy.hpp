#ifndef TESTY_HPP	
#define TESTY_HPP

#include "pch.h"
#include "Lista.hpp"
#include "Macierz.hpp"

class Testy {
public:
	void Testuj_Macierz(int wierzch, int dens);

	void Testuj_Liste(int wierzch, int dens);

	void Komunikacja();

	void Menu_Do_Testow();
};

void Testy::Testuj_Macierz(int wierzch, int dens) {

	double tab_czas[100];

	for (int i = 0; i < 100; i++) {
		
		Macierz M(wierzch, dens);
		tab_czas[i] = Czas_M(M);
		M.Usun_Macierz(wierzch);
		//std::cout << tab_czas[i] << " ";
	}
	std::sort(tab_czas, tab_czas + 100);
	std::cout << "Czasy Macierzy" << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Min Czas: " << tab_czas[0] << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Max Czas: " << tab_czas[99] << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Mediana: " << tab_czas[49] << std::endl;
}

void Testy::Testuj_Liste(int wierzch, int dens) {
	double tab_czas[100];

	for (int i = 0; i < 100; i++) {

		Graf_Lista L(wierzch,dens);
		tab_czas[i] = Czas_L(L);
		L.Usun_Liste(wierzch);
		L.Usun_Tablice_Flag(wierzch);
		std::cout << tab_czas[i] << ' ';
	}
	std::sort(tab_czas, tab_czas + 100);
	std::cout << "Czasy Listy" << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Min Czas: " << tab_czas[0] << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Max Czas: " << tab_czas[99] << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Mediana: " << tab_czas[49] << std::endl;
}

void Testy::Komunikacja() {
	std::cout << "Sprawdzenie dzialania algorytmu Bellmana Forda oraz tworzenia grafow na macierzy oraz liscie sasiedztwa" << std::endl;
	std::cout << "a - Przykladowe sprawdzenie dzialania programu" << std::endl;
	std::cout << "b - Sprawdzenie czasu dla grafu na macierzy i liscie 10 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "c - Sprawdzenie czasu dla grafu na macierzy i liscie 50 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "d - Sprawdzenie czasu dla grafu na macierzy i liscie 100 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "e - Sprawdzenie czasu dla grafu na macierzy i liscie 500 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "f - Sprawdzenie czasu dla grafu na macierzy i liscie 1000 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "g - czyszczenie konsoli" << std::endl;
	std::cout << "q - wyjscie" << std::endl;
	std::cout << "Twoj wybor: ";
}

void Testy::Menu_Do_Testow() {
	srand(time(NULL));
	char znak;
	do
	{
		Komunikacja();
		std::cin >> znak;
	
		switch (znak) {
		case 'a': {
			Macierz M(6, 75);
			M.Wypisz_Macierz(6);
			std::cout << std::endl << std::endl;
			Bellman_Ford_Pierwszy(M);
			M.Usun_Macierz(6);

			Graf_Lista L(6, 75);
			L.Wypisz_Liste(6);
			std::cout << std::endl;
			Bellman_Ford_Drugi(L);
			L.Usun_Liste(6);
			break;
		}
		case 'b': {
			Testuj_Macierz(10, 25);
			Testuj_Macierz(10, 50);
			Testuj_Macierz(10, 75);
			Testuj_Macierz(10, 100);

			Testuj_Liste(10, 25);
			Testuj_Liste(10, 50);
			Testuj_Liste(10, 75);
			Testuj_Liste(10, 100);
			break;
		}
		case'c': {
			Testuj_Macierz(50, 25);
			Testuj_Macierz(50, 50);
			Testuj_Macierz(50, 75);
			Testuj_Macierz(50, 100);

			Testuj_Liste(50, 25);
			Testuj_Liste(50, 50);
			Testuj_Liste(50, 75);
			Testuj_Liste(50, 100);
			break;
		}
		case 'd': {
			Testuj_Macierz(100, 25);
			Testuj_Macierz(100, 50);
			Testuj_Macierz(100, 75);
			Testuj_Macierz(100, 100);

			Testuj_Liste(100, 25);
			Testuj_Liste(100, 50);
			Testuj_Liste(100, 75);
			Testuj_Liste(100, 100);
			break;
		}
		case 'e': {
			Testuj_Macierz(500, 25);
			Testuj_Macierz(500, 50);
			Testuj_Macierz(500, 75);
			Testuj_Macierz(500, 100);

			Testuj_Liste(500, 25);
			Testuj_Liste(500, 50);
			Testuj_Liste(500, 75);
			Testuj_Liste(500, 100);
			break;
		}
		case 'f': {
			Testuj_Macierz(1000, 25);
			Testuj_Macierz(1000, 50);
			Testuj_Macierz(1000, 75);
			Testuj_Macierz(1000, 100);

			Testuj_Liste(1000, 25);
			Testuj_Liste(1000, 50);
			Testuj_Liste(1000, 75);
			Testuj_Liste(1000, 100);
			break;
		}
		case'g': {
			system("cls");
		}
		}

	} while (znak != 'q');
}

#endif