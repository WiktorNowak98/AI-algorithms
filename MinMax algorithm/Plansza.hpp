#ifndef PLANSZA_HPP
#define PLANSZA_HPP

#include "pch.h"

class Plansza {
public:

	char Pole_gry[ROZMIAR][ROZMIAR];

	int Tablica_flag[ROZMIAR][ROZMIAR];

	void Inicjuj_Plansze();

	void Rozklad_Startowy();

	void Pokaz_Plansze();

	void Sprawdz_Gdzie_Pionek();

	void Pokaz_Flagi();

	bool Wygrana();

};

void Plansza::Inicjuj_Plansze() {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {

			Pole_gry[i][j] = ' ';
		}
	}
}

void Plansza::Pokaz_Plansze() {

	for (int i = 0; i < ROZMIAR; i++) {
		std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
		std::cout << i + 1 << " | " << Pole_gry[i][0] << " | " << Pole_gry[i][1] << " | " << Pole_gry[i][2] << " | " << Pole_gry[i][3] << " | ";
		std::cout << Pole_gry[i][4] << " | " << Pole_gry[i][5] << " | " << Pole_gry[i][6] << " | " << Pole_gry[i][7] << " | " << std::endl;
	}
	std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
	std::cout << "    A   B   C   D   E   F   G   H  " << std::endl;
}

void Plansza::Rozklad_Startowy() {

	for (int i = 0; i < ROZMIAR; i = i + 2) {

		Pole_gry[0][i] = 'x';
	}
	for (int j = 1; j < ROZMIAR; j = j + 2) {

		Pole_gry[1][j] = 'x';
	}
	for (int i = 0; i < ROZMIAR; i = i + 2) {

		Pole_gry[6][i] = 'o';
	}
	for (int j = 1; j < ROZMIAR; j = j + 2) {

		Pole_gry[7][j] = 'o';
	}
}

void Plansza::Sprawdz_Gdzie_Pionek() {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (Pole_gry[i][j] == 'x' or Pole_gry[i][j] == 'o') {
				Tablica_flag[i][j] = 1;
			}
			else {
				Tablica_flag[i][j] = 0;
			}
		}
	}
}

void Plansza::Pokaz_Flagi() {
	for (int i = 0; i < ROZMIAR; i++) {
		std::cout << std::endl << std::setw(2);
		for (int j = 0; j < ROZMIAR; j++) {
			std::cout << std::setw(2) << Tablica_flag[i][j] << std::setw(2);
		}
	}
}

bool Plansza::Wygrana() {

	int licznik1 = 0, licznik2 = 0;

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (Pole_gry[i][j] == 'o') {
				licznik1++;
			}
			if (Pole_gry[i][j] == 'x') {
				licznik2++;
			}
		}
	}
	if ((licznik2 == 0) or (licznik1 == 0)) { return true; }
	else { return false; }
}

#endif