#ifndef AI_HPP
#define AI_HPP

#include "pch.h"
#include "Plansza.hpp"
#include "Pion1.hpp"

using namespace std;

class AI {

public:

	int Tablica_pom[3];

	int Tablica_ruch[4];

	int Tab_bic[3];

	int TablicaWag[ROZMIAR][ROZMIAR];

	int wzorzec[ROZMIAR][ROZMIAR];

	int sila_x = 0;

	int sila_o = 0;

	AI();

	void Sprawdz_Sile_Bojowa(Plansza &P);  //niepotrzebne

	void Wyzeruj_Sile_Bojowa(); //niepotrzebne

	int Polozenie_Na_Planszy(Plansza &P,int wiersz, int kolumna); //niepotrzebne

	int Taktyka_gry();  //niepotrzebne

	int Rusz_AI(Plansza &P, Pion1 &A ,int wiersz, int kolumna);

	int Rusz_Dam(Plansza &P, Pion1 &A, int wiersz, int kolumna);

	void Ruch_Koncowy(Plansza &P, Pion1 &A);

	int Czy_Mozliwe_Bicie(int wiersz, int kolumna, Plansza &P, Pion1 &A);

	int Mozliwe_Bicie(int wiersz, int kolumna, Plansza &P, Pion1 &A);

	void Wchodzenie_Pod_Bicie(int wiersz, int kolumna, Plansza& P, Pion1& A);
};

AI::AI() {

	int wag = 1;
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR/2; j++) {
			TablicaWag[i][j] = i+wag;
			wag++;
		}
		wag--;
		for (int j = ROZMIAR / 2; j < ROZMIAR; j++) {
			TablicaWag[i][j] = i + wag;
			wag--;
		}
	}
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			TablicaWag[i][j] += i;
		}
	}

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			wzorzec[i][j] = TablicaWag[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		Tablica_pom[i] = 0;
		Tab_bic[i] = 0;
		Tablica_ruch[i] = 0;
	}
	Tablica_ruch[3] = 0;
}

void AI::Sprawdz_Sile_Bojowa(Plansza &P) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (P.Pole_gry[i][j] == 'x') {
				sila_x = sila_x + 1;
			}
			else if (P.Pole_gry[i][j] == 'X') {
				sila_x = sila_x + 5;
			}
			else if (P.Pole_gry[i][j] == 'o') {
				sila_o = sila_o + 1;
			}
			else if (P.Pole_gry[i][j] == 'O') {
				sila_o = sila_o + 1;
			}
		}
	}
}

void AI::Wyzeruj_Sile_Bojowa() {
	sila_x = 0;
	sila_o = 0;
}

int AI::Polozenie_Na_Planszy(Plansza &P,int wiersz, int kolumna) {
	
	int waga = 0;

	if (wiersz == 0) { waga = waga + 0; }
	if (wiersz == 1) { waga = waga + 1; }
	if (wiersz == 2) { waga = waga + 2; }
	if (wiersz == 3) { waga = waga + 3; }
	if (wiersz == 4) { waga = waga + 4; }
	if (wiersz == 5) { waga = waga + 5; }
	if (wiersz == 6) { waga = waga + 6; }
	if (wiersz == 7) { waga = waga + 7; }

	return waga;
}

int AI::Taktyka_gry() {
	if (sila_x > sila_o) {
		Wyzeruj_Sile_Bojowa();
		return 0;
	}
	else {
		Wyzeruj_Sile_Bojowa();
		return 1;
	}
}

int AI::Rusz_AI(Plansza &P, Pion1 &A,int wiersz, int kolumna) {
	
	int waga=0;

	if (A.Czy_Na_Planszy(kolumna + 1, wiersz + 1) && !A.Czy_Pion(kolumna + 1, wiersz + 1, P)) {
		if (A.Czy_Ruch(kolumna, wiersz, kolumna + 1, wiersz + 1, P)) {

			waga = TablicaWag[wiersz + 1][kolumna + 1];
			Tablica_pom[0] = wiersz + 1;
			Tablica_pom[1] = kolumna + 1;
			Tablica_pom[2] = waga;
		}
	}

	if (A.Czy_Na_Planszy(kolumna - 1, wiersz + 1) && !A.Czy_Pion(kolumna - 1, wiersz + 1, P)) {
		if (A.Czy_Ruch(kolumna, wiersz, kolumna - 1, wiersz + 1, P)) {

			if (waga < TablicaWag[wiersz + 1][kolumna - 1]) {
				waga = TablicaWag[wiersz + 1][kolumna - 1];
				Tablica_pom[0] = wiersz + 1;
				Tablica_pom[1] = kolumna - 1;
				Tablica_pom[2] = waga;
			}
		}
	}

	return waga;
}

int AI::Rusz_Dam(Plansza &P, Pion1 &A, int wiersz, int kolumna) {
	return 0;
}

void AI::Ruch_Koncowy(Plansza &P, Pion1 &A) {

	int waga = 0;

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (P.Pole_gry[i][j] == 'x') {
				Wchodzenie_Pod_Bicie(j,i,P,A);
				if (waga < Rusz_AI(P, A, i, j)) {
					waga = Tablica_pom[2];
					Tablica_ruch[0] = i;
					Tablica_ruch[1] = j;
					Tablica_ruch[2] = Tablica_pom[0];
					Tablica_ruch[3] = Tablica_pom[1];
				}
				
				if (waga < Mozliwe_Bicie(j, i, P, A)) {
					waga = Tab_bic[2];
					Tablica_ruch[0] = i;
					Tablica_ruch[1] = j;
					Tablica_ruch[2] = Tab_bic[0];
					Tablica_ruch[3] = Tab_bic[1];

				}
			}
			
			Tab_bic[0] = 0;
			Tab_bic[1] = 0;
			Tab_bic[2] = 0;

			Tablica_pom[0] = 0;
			Tablica_pom[1] = 0;
			Tablica_pom[2] = 0;
		}
	}
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			TablicaWag[i][j] = wzorzec[i][j];
		}
	}
}

int AI::Czy_Mozliwe_Bicie(int kolumna, int wiersz, Plansza &P, Pion1 &A) {

	if (A.Czy_Na_Planszy(kolumna + 1, wiersz + 1) and wiersz + 1 != 7 and wiersz + 1 != 0 and kolumna + 1 != 7 and kolumna + 1 != 0) {
		if (A.Zbij_AI(P, kolumna, wiersz, kolumna + 1, wiersz + 1)) { return 3; }
	}
	if (A.Czy_Na_Planszy(kolumna - 1, wiersz + 1) and wiersz + 1 != 7 and wiersz + 1 != 0 and kolumna - 1 != 7 and kolumna - 1 != 0) {
		if (A.Zbij_AI(P, kolumna, wiersz, kolumna - 1, wiersz + 1)) { return 2; }
	}

	return -1;

}

int AI::Mozliwe_Bicie(int kolumna, int wiersz, Plansza &P, Pion1 &A) {

	int waga = 0;

	switch (Czy_Mozliwe_Bicie(kolumna, wiersz, P, A)) {
	case 0: {
		waga = 50;
		Tab_bic[0] = wiersz - 1;
		Tab_bic[1] = kolumna - 1;
		Tab_bic[2] = waga;
		break;
	}
	case 1: {
		waga = 50;
		Tab_bic[0] = wiersz - 1;
		Tab_bic[1] = kolumna + 1;
		Tab_bic[2] = waga;
		break;
	}
	case 2: {
		waga = 50;
		Tab_bic[0] = wiersz + 1;
		Tab_bic[1] = kolumna - 1;
		Tab_bic[2] = waga;
		break;
	}
	case 3: {
		waga = 50;
		Tab_bic[0] = wiersz + 1;
		Tab_bic[1] = kolumna + 1;
		Tab_bic[2] = waga;
		break;
	}
	case -1: {
		waga = -1;
		Tab_bic[0] = wiersz;
		Tab_bic[1] = kolumna;
		Tab_bic[2] = waga;
		break;
	}
	}
	return waga;
}

void AI::Wchodzenie_Pod_Bicie(int kolumna, int wiersz, Plansza& P, Pion1& A) {

	if (A.Czy_Na_Planszy(kolumna + 2, wiersz + 2)) {
		if (A.Czy_Pion(kolumna + 2, wiersz + 2, P) and (A.Jaki_Pion(kolumna + 2, wiersz + 2,P) == 1 or A.Jaki_Pion(kolumna + 2, wiersz + 2, P) == 3)) {
			TablicaWag[wiersz + 1][kolumna + 1] = 1;
		}
	}

	if (A.Czy_Na_Planszy(kolumna, wiersz + 2)) {
		if (A.Czy_Pion(kolumna , wiersz + 2, P) and (A.Jaki_Pion(kolumna , wiersz + 2, P) == 1 or A.Jaki_Pion(kolumna , wiersz + 2, P) == 3) and A.Czy_Na_Planszy(kolumna+2,wiersz)) {
			TablicaWag[wiersz + 1][kolumna +1] = 1;
		}
	}

	if (A.Czy_Na_Planszy(kolumna -2, wiersz + 2)) {
		if (A.Czy_Pion(kolumna -2, wiersz + 2, P) and (A.Jaki_Pion(kolumna - 2, wiersz + 2, P) == 1 or A.Jaki_Pion(kolumna - 2, wiersz + 2, P) == 3)) {
			TablicaWag[wiersz + 1][kolumna - 1] = 1;
		}
	}

	if (A.Czy_Na_Planszy(kolumna, wiersz + 2)) {
		if (A.Czy_Pion(kolumna , wiersz + 2, P) and (A.Jaki_Pion(kolumna , wiersz + 2, P) == 1 or A.Jaki_Pion(kolumna , wiersz + 2, P) == 3) and A.Czy_Na_Planszy(kolumna -2, wiersz)) {
			TablicaWag[wiersz + 1][kolumna - 1] = 1;
		}
	}
}

#endif