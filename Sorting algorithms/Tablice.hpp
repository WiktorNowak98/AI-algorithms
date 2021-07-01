#ifndef TABLICE_H
#define TABLICE_H

#include "pch.h"

template<typename T>
class Tablica {

public:

	T* tablica_sort;

	T* tablica_kop;

	Tablica(int Rozmiar);

	virtual ~Tablica();

	void Tworz_Tablice(int Rozmiar);

	void Kopiuj_Tablice(T TablicaMatka[], int RozmiarMatki);

	void Usun_Tablice(T* Tablica_Do_Usuniecia) const;

};

template<typename T>
Tablica<T>::Tablica(int Rozmiar) {

	tablica_sort = new T[Rozmiar];

	for (int i = 0; i < Rozmiar; i++) {

		tablica_sort[i] = rand() % Rozmiar;
	}
}

template<typename T>
Tablica<T>::~Tablica() {

	delete[] tablica_sort;
}

template<typename T>
void Tablica<T>::Usun_Tablice(T* Tablica_Do_Usuniecia) const {

	delete[] Tablica_Do_Usuniecia;
}

template<typename T>
void Tablica<T>::Tworz_Tablice(int Rozmiar) {

	tablica_sort = new T[Rozmiar];

	for (int i = 0; i < Rozmiar; i++) {

		tablica_sort[i] = rand() % Rozmiar;
	}
}

template<typename T>
void Tablica<T>::Kopiuj_Tablice(T TablicaMatka[], int RozmiarMatki) {

	tablica_kop = new T[RozmiarMatki];

	for (int i = 0; i < RozmiarMatki; i++) {

		tablica_kop[i] = TablicaMatka[i];
	}
}

#endif
