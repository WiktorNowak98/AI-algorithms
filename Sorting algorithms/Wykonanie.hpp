#ifndef WYKONANIE_H
#define WYKONANIE_H

#include "pch.h"
#include "Sortowanie.hpp"
#include "Tablice.hpp"

template<typename T>
class Wykonanie {

public:

	void Sortowanie_Wszystko_Losowe();

	void Odwrotna_Kolejnosc(T tablica[], int Rozmiar);

	void Sortowanie_Odwrotna_Kolejnosc();

	void Sortowanie_Czesc_Posortowane(double ile);

	void Menu();

	void Komunikacja() const;

	void WyczyscPlik();

	void ZapiszDoPliku(T tablica[], int Rozmiar);
};

template<typename T>
void Wykonanie<T>::ZapiszDoPliku(T tablica[],int Rozmiar) {

	std::string linia;
	std::fstream plik;
	
	plik.open("plik.txt", std::ios::out | std::ios::app);
	if (plik.good() == true) {

		for (int i = 0; i < Rozmiar; i++) {
			plik << tablica[i] << " ";
		}
		plik << std::endl << " Kolejna Tablica " << std::endl;
		plik.close();
	}
}

template<typename T>
void Wykonanie<T>::WyczyscPlik() {

	std::string linia;
	std::fstream plik;

	plik.open("plik.txt", std::ios::out | std::ios::trunc);
}

template<typename T>
void Wykonanie<T>::Odwrotna_Kolejnosc(T tablica[], int Rozmiar) {

	T temp;

	for (int i = 0; i < Rozmiar / 2; i++) {

		temp = tablica[Rozmiar - i - 1];
		tablica[Rozmiar - i - 1] = tablica[i];
		tablica[i] = temp;
	}
}

template<typename T>
void Wykonanie<T>::Sortowanie_Odwrotna_Kolejnosc() {

	int IloscTablic;
	int Rozmiar;

	std::cout << "Podaj ilosc tablic do posortowania:" << std::endl;
	std::cin >> IloscTablic;
	std::cout << "Podaj rozmiary tablic do posortowania:" << std::endl;
	std::cin >> Rozmiar;

	Tablica<T> tab(Rozmiar);
	Sortowania<T> sort;

	T* tablica_pomocnicza = new T[Rozmiar];

	sort.QuickSort(tab.tablica_sort, 0, Rozmiar - 1);
	Odwrotna_Kolejnosc(tab.tablica_sort, Rozmiar);

	WyczyscPlik();
	ZapiszDoPliku(tab.tablica_sort, Rozmiar);

	std::clock_t start;
	double czas_wykonania;

	start = std::clock();

	for (int i = 0; i < IloscTablic; i++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.QuickSort(tab.tablica_kop, 0, Rozmiar - 1);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);

	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << std::endl;
	std::cout << "Czas wykonania QuickSort " << czas_wykonania << " sekund";
	std::cout << std::endl;

	ZapiszDoPliku(tab.tablica_sort, Rozmiar);
	start = std::clock();

	for (int j = 0; j < IloscTablic; j++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.MergeSort(tab.tablica_kop, 0, Rozmiar - 1, tablica_pomocnicza);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);

	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania MergeSort " << czas_wykonania << " sekund";
	std::cout << std::endl;

	ZapiszDoPliku(tab.tablica_sort, Rozmiar);
	start = std::clock();

	for (int k = 0; k < IloscTablic; k++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.ShellSort(tab.tablica_kop, Rozmiar);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);

	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania ShellSort " << czas_wykonania << " sekund";
	std::cout << std::endl;
	std::cout << std::endl;
}

template<typename T>
void Wykonanie<T>::Sortowanie_Czesc_Posortowane(double ile) {

	srand(time(NULL));

	int Rozmiar;
	int IloscTablic;

	std::cout << "Podaj ilosc tablic do posortowania:" << std::endl;
	std::cin >> IloscTablic;
	std::cout << "Podaj rozmiary tablic do posortowania:" << std::endl;
	std::cin >> Rozmiar;

	Tablica<T> tab(Rozmiar);
	Sortowania<T> sort;

	T* tablica_pomocnicza = new T[Rozmiar];

	int pomocnicza = Rozmiar * ile;

	sort.QuickSort(tab.tablica_sort, 0, pomocnicza - 1);

	WyczyscPlik();
	ZapiszDoPliku(tab.tablica_sort, Rozmiar);

	std::clock_t start;
	double czas_wykonania;

	start = std::clock();

	for (int i = 0; i < IloscTablic; i++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.QuickSort(tab.tablica_kop, 0, Rozmiar - 1);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);
	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << std::endl;
	std::cout << "Czas wykonania QuickSort " << czas_wykonania << " sekund";
	std::cout << std::endl;

	ZapiszDoPliku(tab.tablica_sort, Rozmiar);
	start = std::clock();

	for (int j = 0; j < IloscTablic; j++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.MergeSort(tab.tablica_kop, 0, Rozmiar - 1, tablica_pomocnicza);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);

	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania MergeSort " << czas_wykonania << " sekund";
	std::cout << std::endl;

	ZapiszDoPliku(tab.tablica_sort, Rozmiar);
	start = std::clock();

	for (int k = 0; k < IloscTablic; k++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.ShellSort(tab.tablica_kop, Rozmiar);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);

	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania ShellSort " << czas_wykonania << " sekund";
	std::cout << std::endl;
	std::cout << std::endl;
}

template<typename T>
void Wykonanie<T>::Sortowanie_Wszystko_Losowe() {

	srand(time(NULL));

	int Rozmiar;
	int IloscTablic;

	std::cout << "Podaj ilosc tablic do posortowania:" << std::endl;
	std::cin >> IloscTablic;
	std::cout << "Podaj rozmiary tablic do posortowania:" << std::endl;
	std::cin >> Rozmiar;

	Tablica<T> tab(Rozmiar);
	Sortowania<T> sort;

	T* tablica_pomocnicza = new T[(Rozmiar)];
	
	WyczyscPlik();
	ZapiszDoPliku(tab.tablica_sort, Rozmiar);

	std::clock_t start;
	double czas_wykonania;

	start = std::clock();

	for (int i = 0; i < IloscTablic; i++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.QuickSort(tab.tablica_kop, 0, Rozmiar - 1);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);
		//std::cout << "Tablica " << i << std::endl;
	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << std::endl;
	std::cout << "Czas wykonania QuickSort " << czas_wykonania << " sekund";
	std::cout << std::endl;

	ZapiszDoPliku(tab.tablica_sort, Rozmiar);
	start = std::clock();

	for (int j = 0; j < IloscTablic; j++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.MergeSort(tab.tablica_kop, 0, Rozmiar - 1, tablica_pomocnicza);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);
		
	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania MergeSort " << czas_wykonania << " sekund";
	std::cout << std::endl;

	ZapiszDoPliku(tab.tablica_sort, Rozmiar);
	start = std::clock();

	for (int k = 0; k < IloscTablic; k++) {

		tab.Kopiuj_Tablice(tab.tablica_sort, Rozmiar);
		sort.ShellSort(tab.tablica_kop, Rozmiar);
		ZapiszDoPliku(tab.tablica_kop, Rozmiar);
		tab.Usun_Tablice(tab.tablica_kop);
	}

	czas_wykonania = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania ShellSort " << czas_wykonania << " sekund";
	std::cout << std::endl;
	std::cout << std::endl;

}

template<typename T>
void Wykonanie<T>::Komunikacja() const {

	std::cout << "Badanie roznych rodzajow sortowania" << std::endl;
	std::cout << "Quicksort, Mergesort oraz ShellSort" << std::endl;
	std::cout << "Opcje: " << std::endl;
	std::cout << "a - Wszystkie elementy tablicy sa losowe" << std::endl;
	std::cout << "b - 25% jest posortowane" << std::endl;
	std::cout << "c - 50% jest posortowane" << std::endl;
	std::cout << "d - 75% jest posortowane" << std::endl;
	std::cout << "e - 95% jest posortowane" << std::endl;
	std::cout << "f - 99% jest posortowane" << std::endl;
	std::cout << "g - wszystkie elementy sa posortowane ale w odwrotnej kolejnosci" << std::endl;
	std::cout << "q - wyjdz" << std::endl;
	std::cout << "Twoj wybor: " << std::endl;
}

template<typename T>
void Wykonanie<T>::Menu() {

	char znak;
	do {
		Komunikacja();
		std::cin >> znak;

		switch (znak) {

		case 'a': {

			Sortowanie_Wszystko_Losowe();
			break;
		}
		case 'b': {

			Sortowanie_Czesc_Posortowane(0.25);
			break;
		}
		case 'c': {

			Sortowanie_Czesc_Posortowane(0.5);
			break;
		}
		case 'd': {

			Sortowanie_Czesc_Posortowane(0.75);
			break;
		}
		case 'e': {

			Sortowanie_Czesc_Posortowane(0.95);
			break;
		}
		case 'f': {

			Sortowanie_Czesc_Posortowane(0.997);
			break;
		}
		case 'g': {

			Sortowanie_Odwrotna_Kolejnosc();
			break;
		}
		case 'q': {

			break;
		}
		}
	} while (znak != 'q');
}

#endif
