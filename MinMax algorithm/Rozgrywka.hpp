#ifndef ROZGRYWKA_HPP
#define ROZGRYWKA_HPP

#include "pch.h"
#include "Pion1.hpp"
#include "AI.hpp"
#include "Plansza.hpp"

class Rozgrywka {

public:

	void Zagraj(Plansza &P, Pion1 &A, AI& C);
};

void Rozgrywka::Zagraj(Plansza &P, Pion1 &A, AI& C) {

	int Wersja;

	std::cout << "-------------- Proste Warcaby --------------" << std::endl;
	P.Inicjuj_Plansze();
	P.Rozklad_Startowy();
	P.Pokaz_Plansze();
	std::cout << "Jeden gracz - 1" << std::endl;
	std::cout << "Dwoch graczy - 2" << std::endl;
	std::cout << "Twoj wybor:" << std::endl;
	std::cin >> Wersja;
	system("cls");
	if (Wersja == 1) {
		P.Inicjuj_Plansze();
		P.Rozklad_Startowy();

		while (P.Wygrana() == false) {

			char pom1, pom2;
			int pom3, pom4, tura = 0;

			while (tura != 4) {
				std::cout << "Tura 'o':" << std::endl;
				P.Pokaz_Plansze();
				std::cout << "Wybierz pion:" << std::endl;
				std::cin >> pom1 >> pom3;
				std::cout << "Ruch:" << std::endl;
				std::cin >> pom2 >> pom4;
				system("cls");
				if (A.Czy_Litera(pom1) == true and A.Czy_Litera(pom2) == true) {

					int kolumna = A.Litera_na_liczbe(pom1);
					int kolumna2 = A.Litera_na_liczbe(pom2);

					int wiersz = pom3 - 1;
					int wiersz2 = pom4 - 1;

					tura = A.Rusz_Pion_O(kolumna, wiersz, P, kolumna2, wiersz2);
					A.Sprawdz_Blad(tura);
				}
				else {
					std::cout << "Niepoprawny zapis" << std::endl;
				}
			}
			tura = 0;
			while (tura != 4) {
				C.Ruch_Koncowy(P, A);
				tura = A.Rusz_Pion_X(C.Tablica_ruch[1], C.Tablica_ruch[0], P, C.Tablica_ruch[3], C.Tablica_ruch[2]);
				A.Sprawdz_Blad(tura);
			}
		}
		std::cout << "Koniec gry" << std::endl;
	}
	else if (Wersja == 2) {

		P.Inicjuj_Plansze();
		P.Rozklad_Startowy();

		while (P.Wygrana() == false) {

			char pom1, pom2;
			int pom3, pom4, tura = 0;

			while (tura != 4) {
				std::cout << "Tura 'o':" << std::endl;
				P.Pokaz_Plansze();
				std::cout << "Wybierz pion:" << std::endl;
				std::cin >> pom1 >> pom3;
				std::cout << "Ruch:" << std::endl;
				std::cin >> pom2 >> pom4;
				system("cls");
				if (A.Czy_Litera(pom1) == true and A.Czy_Litera(pom2) == true) {

					int kolumna = A.Litera_na_liczbe(pom1);
					int kolumna2 = A.Litera_na_liczbe(pom2);

					int wiersz = pom3 - 1;
					int wiersz2 = pom4 - 1;

					tura = A.Rusz_Pion_O(kolumna, wiersz, P, kolumna2, wiersz2);
					A.Sprawdz_Blad(tura);
				}
				else {
					std::cout << "Niepoprawny zapis" << std::endl;
				}
			}
			tura = 0;
			while (tura != 4) {
				std::cout << "Tura 'x':" << std::endl;
				P.Pokaz_Plansze();
				std::cout << "Wybierz pion:" << std::endl;
				std::cin >> pom1 >> pom3;
				std::cout << "Ruch:" << std::endl;
				std::cin >> pom2 >> pom4;
				system("cls");
				C.Ruch_Koncowy(P, A);
			
				if (A.Czy_Litera(pom1) == true and A.Czy_Litera(pom2) == true) {

					int kolumna = A.Litera_na_liczbe(pom1);
					int kolumna2 = A.Litera_na_liczbe(pom2);

					int wiersz = pom3 - 1;
					int wiersz2 = pom4 - 1;

					tura = A.Rusz_Pion_X(kolumna, wiersz, P, kolumna2, wiersz2);
					A.Sprawdz_Blad(tura);
				}
				else {
					std::cout << "Niepoprawny zapis" << std::endl;
				}
			}
		}
		std::cout << "Koniec gry" << std::endl;
	}
}


#endif
