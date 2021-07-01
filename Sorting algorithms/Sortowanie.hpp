#ifndef SORTOWANIE_H
#define SORTOWANIE_H

#include"pch.h"

template<typename T> 
class Sortowania {

public:

	int Podzia³Pivot(T tablica[], int poczatek, int koniec) const;

	void QuickSort(T tablica[], int poczatek, int koniec) const;

	void Scalenie(T tablica[], int poczatek, int srodek, int koniec, T tablica_pomocnicza[]) const;

	void MergeSort(T tablica[], int poczatek, int koniec, T tablica_pomocnicza[]) const;

	void ShellSort(T tablica[], int Rozmiar) const;
};

template<typename T>
int Sortowania<T>::Podzia³Pivot(T tablica[], int poczatek, int koniec) const {

	T pivot = tablica[poczatek];
	int i = poczatek, j = koniec, k;

	while (true) {
		while (tablica[j] > pivot) {
			j--;
		}
		while (tablica[i] < pivot) {
			i++;
		}
		if (i < j) {
			k = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = k;
			i++;
			j--;
		}
		else {
			return j;
		}
	}
}

template<typename T>
void Sortowania<T>::QuickSort(T tablica[], int poczatek, int koniec) const {

	int i = poczatek;
	int j = koniec;
	T pivot = tablica[(poczatek + koniec) / 2];

	do {
		while (tablica[i] < pivot)
			i++;

		while (tablica[j] > pivot)
			j--;
		if (i <= j) {

			std::swap(tablica[i], tablica[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (poczatek < j)
		QuickSort(tablica, poczatek, j);

	if (koniec > i)
		QuickSort(tablica, i, koniec);
}

template<typename T>
void Sortowania<T>::Scalenie(T tablica[], int poczatek, int srodek, int koniec, T tablica_pomocnicza[]) const {
	
	int i = poczatek, j = srodek + 1, k = 0;

	while (i <= srodek && j <= koniec) {
		if (tablica[j] < tablica[i]) {
			tablica_pomocnicza[k] = tablica[j];
			j++;
		}
		else {
			tablica_pomocnicza[k] = tablica[i];
			i++;
		}
		k++;
	}
	if (i <= srodek) {
		while (i <= srodek) {
			tablica_pomocnicza[k] = tablica[i];
			i++;
			k++;
		}
	}
	else {
		while (j <= koniec) {
			tablica_pomocnicza[k] = tablica[j];
			j++;
			k++;
		}
	}
	for (i = 0; i <= koniec - poczatek; i++) {
		tablica[poczatek + i] = tablica_pomocnicza[i];
	}
}

template<typename T>
void Sortowania<T>::MergeSort(T tablica[], int poczatek, int koniec, T tablica_pomocnicza[]) const {

	int srodek;

	if (poczatek != koniec) {

		srodek = (poczatek + koniec) / 2;
		MergeSort(tablica, poczatek, srodek, tablica_pomocnicza);
		MergeSort(tablica, srodek + 1, koniec, tablica_pomocnicza);
		Scalenie(tablica, poczatek, srodek, koniec, tablica_pomocnicza);
	}
}

template<typename T>
void Sortowania<T>::ShellSort(T tablica[], int Rozmiar) const {

	for (int gap = Rozmiar / 2; gap > 0; gap /= 2) {
		
		for (int i = gap; i < Rozmiar; i++) {

			T pom = tablica[i];
			int j;
			for (j = i; j >= gap && tablica[j - gap] > pom; j -= gap) {
				tablica[j] = tablica[j - gap];
			}
			tablica[j] = pom;
		}
	}
}

#endif