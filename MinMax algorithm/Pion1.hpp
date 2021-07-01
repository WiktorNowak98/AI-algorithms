#ifndef PION_HPP
#define PION_HPP

#include "pch.h"
#include "Plansza.hpp"

class Pion1 {
public:
	void Zamien_W_Damke(int kolumna, int wiersz, Plansza &P);

	bool Czy_Litera(char litera);

	bool Czy_Ruch(int kolumna, int wiersz, int kolumna2, int wiersz2, Plansza &P);

	int Litera_na_liczbe(char litera);

	bool Czy_Na_Planszy(int kolumna, int wiersz);

	bool Czy_Pion(int kolumna, int wiersz, Plansza &P);

	int Jaki_Pion(int kolumna, int wiersz, Plansza &P);

	int Zbij_Pion(Plansza &P, int kolumna, int wiersz, int kolumna2, int wiersz2, int wart);

	void Sprawdz_Blad(int wartosc);

	int Rusz_Pion_O(int kolumna, int wiersz, Plansza &P, int kolumna2, int wiersz2);

	int Rusz_Pion_X(int kolumna, int wiersz, Plansza &P, int kolumna2, int wiersz2);

	char Liczba_na_litere(int liczba);

	bool Zbij_AI(Plansza &P, int kolumna, int wiersz, int kolumna2, int wiersz2);

	bool Czy_Pion_AI(int kolumna, int wiersz, Plansza &P);

};

bool Pion1::Czy_Litera(char litera) {

	if (litera != 'A' and litera != 'B' and litera != 'C' and litera != 'D' and litera != 'E' and litera != 'F' and litera != 'G' and litera != 'H') {

		return false;
	}
	return true;
}

bool Pion1::Czy_Ruch(int kolumna , int wiersz, int kolumna2, int wiersz2, Plansza &P) {

	int pom2 = wiersz2;
	int pom3 = wiersz;

	if (Jaki_Pion(kolumna, wiersz, P) == 0) {
		if (Czy_Na_Planszy(kolumna2, wiersz2) == true) {
			if (kolumna2 > kolumna and pom2 > pom3 and kolumna2 == kolumna + 1 and pom2 == pom3 + 1) {
				return true;
			}
			else if (kolumna2 < kolumna and pom2 > pom3 and kolumna2 == kolumna - 1 and pom2 == pom3 + 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else if (Jaki_Pion(kolumna, wiersz, P) == 1) {
		if (Czy_Na_Planszy(kolumna, wiersz) == true) {
			if (kolumna2 > kolumna and pom2 < pom3 and kolumna2 == kolumna + 1 and pom2 == pom3 - 1) {
				return true;
			}
			else if (kolumna2 < kolumna and pom2 < pom3 and kolumna2 == kolumna - 1 and pom2 == pom3 - 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else if (Jaki_Pion(kolumna, wiersz, P) == 2) {
		if (Czy_Na_Planszy(kolumna2, wiersz2) == true) {
			if (kolumna2 > kolumna and pom2 > pom3) {
				return true;
			}
			else if (kolumna2 < kolumna and pom2 > pom3) {
				return true;
			}
			else if (kolumna2 > kolumna and pom2 < pom3) {
				return true;
			}
			else if (kolumna2 < kolumna and pom2 < pom3) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else if (Jaki_Pion(kolumna, wiersz, P) == 3) {
		if (Czy_Na_Planszy(kolumna2, wiersz2) == true) {
			if (kolumna2 > kolumna and pom2 < pom3) {
				return true;
			}
			else if (kolumna2 < kolumna and pom2 < pom3) {
				return true;
			}
			else if (kolumna2 > kolumna and pom2 > pom3) {
				return true;
			}
			else if (kolumna2 < kolumna and pom2 > pom3) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else return false;
}

int Pion1::Litera_na_liczbe(char litera) {

	int pom;

	if (litera == 'A') { pom = 0; }
	if (litera == 'B') { pom = 1; }
	if (litera == 'C') { pom = 2; }
	if (litera == 'D') { pom = 3; }
	if (litera == 'E') { pom = 4; }
	if (litera == 'F') { pom = 5; }
	if (litera == 'G') { pom = 6; }
	if (litera == 'H') { pom = 7; }

	return pom;
}

bool Pion1::Czy_Na_Planszy(int kolumna, int wiersz) {

	int pom = kolumna;
	int pom2 = wiersz;

	if (pom <= 7 and pom >= 0 and pom2 <= 7 and pom2 >= 0) {

		return true;
	}
	else {
		return false;
	}
}

bool Pion1::Czy_Pion(int kolumna, int wiersz, Plansza &P) {

	int pom = kolumna;
	int pom2 = wiersz;

	if (P.Pole_gry[pom2][pom] != ' ') {

		return true;
	}
	else {
		return false;
	}
}

int Pion1::Jaki_Pion(int kolumna, int wiersz, Plansza &P) {

	int pom = kolumna;
	int pom2 = wiersz;

	if (P.Pole_gry[pom2][pom] == 'x') {
		return 0;
	}
	else if (P.Pole_gry[pom2][pom] == 'o') {
		return 1;
	}
	else if (P.Pole_gry[pom2][pom] == 'X') {
		return 2;
	}
	else if (P.Pole_gry[pom2][pom] == 'O') {
		return 3;
	}
}

int Pion1::Zbij_Pion(Plansza &P, int kolumna, int wiersz, int kolumna2, int wiersz2, int wart) {

	int pom, pom2;

	pom = kolumna;
	pom2 = kolumna2;

	if (Jaki_Pion(kolumna, wiersz, P) == 0 and (Jaki_Pion(kolumna2, wiersz2, P) == 1 or Jaki_Pion(kolumna2, wiersz2, P) == 3) and wart == 0) {

		if (pom < pom2 and P.Pole_gry[wiersz2+1][pom2 + 1] == ' ') {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2 + 1][pom2 + 1] = 'x';
			Zamien_W_Damke((pom2 + 1), wiersz2 + 1, P);
			return 4; //Poprawne ukonczenie bicia
		}
		else if (pom > pom2 and P.Pole_gry[wiersz2+1][pom2 - 1] == ' ') {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2+1][pom2 - 1] = 'x';
			Zamien_W_Damke((pom2 - 1), wiersz2 + 1, P);
			return 4; //Poprawne ukonczenie bicia
		}
		else { return 3; /* Kod oznaczajacy niedozwolone bicie */ }
	}
	else if (Jaki_Pion(kolumna, wiersz, P) == 1 and (Jaki_Pion(kolumna2, wiersz2, P) == 0 or Jaki_Pion(kolumna2, wiersz2, P) == 2) and wart == 1) {

		if (pom < pom2 and P.Pole_gry[wiersz2 - 1][pom2 + 1] == ' ') {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2 - 1][pom2 + 1] = 'o';
			Zamien_W_Damke((pom2 + 1), wiersz2-1, P);
			return 4; //Poprawne ukonczenie bicia
		}
		else if (pom > pom2 and P.Pole_gry[wiersz2 - 1][pom2 - 1] == ' ') {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2 - 1][pom2 - 1] = 'o';
			Zamien_W_Damke((pom2 - 1), wiersz2-1, P);
			return 4; //Poprawne ukonczenie bicia
		}
	}
	else if (Jaki_Pion(kolumna, wiersz, P) == 2 and (Jaki_Pion(kolumna2, wiersz2, P) == 1 or Jaki_Pion(kolumna2, wiersz2, P) == 3) and wart == 0) {

		if (pom < pom2 and P.Pole_gry[wiersz2+1][pom2 + 1] == ' ' and wiersz2+1 > wiersz+1) {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2+1][pom2 + 1] = 'X';
			//std::cout << "1" << std::endl;
			return 4; //Poprawne ukonczenie bicia
		}
		else if (pom > pom2 and P.Pole_gry[wiersz2+1][pom2 - 1] == ' ' and wiersz2+1 > wiersz+1) {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2+1][pom2 - 1] = 'X';
			//std::cout << "2" << std::endl;
			return 4; //Poprawne ukonczenie bicia
		}
		else if (pom < pom2 and P.Pole_gry[wiersz2+1][pom2 + 1] == ' ' and wiersz2+1 < wiersz+1) {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2 - 1][pom2 + 1] = 'X';
			//std::cout << "3" << std::endl;
			return 4; //Poprawne ukonczenie bicia
		}
		else if (pom > pom2 and P.Pole_gry[wiersz2+1][pom2 - 1] == ' ' and wiersz2+1 < wiersz+1) {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2 - 1][pom2 - 1] = 'X';
			//std::cout << "4" << std::endl;
			return 4; //Poprawne ukonczenie bicia
		}
	}

	else if (Jaki_Pion(kolumna, wiersz, P) == 3 and (Jaki_Pion(kolumna2, wiersz2, P) == 0 or Jaki_Pion(kolumna2, wiersz2, P) == 2) and wart == 1) {

		if (P.Pole_gry[wiersz2+1][pom2 + 1] == ' ' and pom < pom2 and wiersz2+1 < wiersz+1) {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2 - 1][pom2 + 1] = 'O';
			//std::cout << "1" <<std::endl;
			return 4; //Poprawne ukonczenie bicia
		}
		else if (P.Pole_gry[wiersz2+1][pom2 - 1] == ' ' and pom > pom2 and wiersz2+1 < wiersz+1) {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2-1][pom2 - 1] = 'O';
			//std::cout << "2" << std::endl;
			return 4; //Poprawne ukonczenie bicia
		}
		else if (P.Pole_gry[wiersz2+1][pom2 - 1] == ' ' and pom<pom2 and wiersz2+1>wiersz+1) {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2+1][pom2 + 1] = 'O';
			//std::cout << "3" << std::endl;
			return 4; //Poprawne ukonczenie bicia
		}
		else if (P.Pole_gry[wiersz2+1][pom2 + 1] == ' ' and pom > pom2 and wiersz2+1 > wiersz+1) {
			P.Pole_gry[wiersz][pom] = ' ';
			P.Pole_gry[wiersz2][pom2] = ' ';
			P.Pole_gry[wiersz2+1][pom2 - 1] = 'O';
			//std::cout << "4" << std::endl;
			return 4; //Poprawne ukonczenie bicia
		}
		else return 3;
	}
}

void Pion1::Sprawdz_Blad(int wartosc) {

	switch (wartosc) {
	case 0: {
		std::cout << "Niepoprawny ruch" << std::endl;
		break;
	}
	case 1: {
		std::cout << "Wyjscie poza plansze" << std::endl;
		break;
	}
	case 2: {
		std::cout << "Niepoprawny pion" << std::endl;
		break;
	}
	case 3: {
		std::cout << "Niedozwolone bicie" << std::endl;
		break;
	}
	case 4: {
		break;
	}
	case 5: {
		std::cout << "To nie twoja tura" << std::endl;
		break;
	}
	}
}

int Pion1::Rusz_Pion_O(int kolumna, int wiersz, Plansza &P, int kolumna2, int wiersz2) {

	int pom, pom2;

	pom = kolumna;
	pom2 = kolumna2;

	if (Czy_Ruch(kolumna, wiersz, kolumna2, wiersz2, P) == true) {
		if (Czy_Na_Planszy(kolumna, wiersz) == true and Czy_Na_Planszy(kolumna2, wiersz2) == true) {
			if (Czy_Pion(kolumna, wiersz, P) == true) {
				if (Czy_Pion(kolumna2, wiersz2, P) == false) {
					if (Jaki_Pion(kolumna, wiersz, P) == 1) {

						P.Pole_gry[wiersz][pom] = ' ';
						P.Pole_gry[wiersz2][pom2] = 'o';
						Zamien_W_Damke(kolumna2, wiersz2, P);
						return 4; //Kod oznaczajacy poprawne ukonczenie ruchu
					}
					else if (Jaki_Pion(kolumna, wiersz, P) == 3) {
						P.Pole_gry[wiersz][pom] = ' ';
						P.Pole_gry[wiersz2][pom2] = 'O';
						return 4;
					}
					else { return 5; }
				}
				else {

					return Zbij_Pion(P, kolumna, wiersz, kolumna2, wiersz2, 1);
				}
			}
			else { return 2; /* Kod oznaczajacy brak piona do ruszenia */ }
		}
		else { return 1; /* Kod oznaczajacy wyjscie poza plansze */ }
	}
	else { return 0; /* Kod oznaczajacy niepoprawny ruch */ }
}

int Pion1::Rusz_Pion_X(int kolumna, int wiersz, Plansza &P, int kolumna2, int wiersz2) {

	int pom, pom2;

	pom = kolumna;
	pom2 = kolumna2;

	if (Czy_Ruch(kolumna, wiersz, kolumna2, wiersz2, P) == true) {
		if (Czy_Na_Planszy(kolumna, wiersz) == true and Czy_Na_Planszy(kolumna2, wiersz2) == true) {
			if (Czy_Pion(kolumna, wiersz, P) == true) {
				if (Czy_Pion(kolumna2, wiersz2, P) == false) {
					if (Jaki_Pion(kolumna, wiersz, P) == 0) {

						P.Pole_gry[wiersz][pom] = ' ';
						P.Pole_gry[wiersz2][pom2] = 'x';
						Zamien_W_Damke(kolumna2, wiersz2, P);
						return 4; // Kod oznaczajacy poprawne ukonczenie ruchu
					}
					else if (Jaki_Pion(kolumna, wiersz, P) == 2) {
						P.Pole_gry[wiersz][pom] = ' ';
						P.Pole_gry[wiersz2][pom2] = 'X';
						return 4;
					}
					else { return 5; }
				}
				else {

					return Zbij_Pion(P, kolumna, wiersz, kolumna2, wiersz2, 0);
				}
			}
			else { return 2; /* Kod oznaczajacy brak piona do ruszenia */ }
		}
		else { return 1; /* Kod oznaczajacy wyjscie poza plansze */ }
	}
	else { return 0; /* Kod oznaczajacy niepoprawny ruch */ }
}

void Pion1::Zamien_W_Damke(int kolumna, int wiersz, Plansza &P) {

	int pom = kolumna;

	if (Jaki_Pion(kolumna, wiersz, P) == 0 and wiersz == 7) {
		P.Pole_gry[wiersz][pom] = 'X';
		//std::cout << "Zamienilem w danke" << std::endl;
	}
	else if (Jaki_Pion(kolumna, wiersz, P) == 1 and wiersz == 0) {
		//std::cout << "Zamienilem w danke" << std::endl;
		P.Pole_gry[wiersz][pom] = 'O';
	}
}

char Pion1::Liczba_na_litere(int liczba) {
	char litera;

	if (liczba == 0) { litera = 'A'; }
	if (liczba == 1) { litera = 'B'; }
	if (liczba == 2) { litera = 'C'; }
	if (liczba == 3) { litera = 'D'; }
	if (liczba == 4) { litera = 'E'; }
	if (liczba == 5) { litera = 'F'; }
	if (liczba == 6) { litera = 'G'; }
	if (liczba == 7) { litera = 'H'; }

	return litera;

}

bool Pion1::Zbij_AI(Plansza &P, int kolumna, int wiersz, int kolumna2, int wiersz2) {
	int pom, pom2;

	pom = kolumna;
	pom2 = kolumna2;
	if (Jaki_Pion(kolumna, wiersz, P) == 0 and (Jaki_Pion(kolumna2, wiersz2, P) == 1 or Jaki_Pion(kolumna2, wiersz2, P) == 3)) {
		
		if (pom < pom2 and P.Pole_gry[wiersz2 + 1][pom2 + 1] == ' ' and (P.Pole_gry[wiersz2][pom2] == 'o' or P.Pole_gry[wiersz2][pom2] == 'O')) {
			
			return true;
		}
		else if (pom > pom2 and P.Pole_gry[wiersz2 + 1][pom2 - 1] == ' ' and (P.Pole_gry[wiersz2][pom2] == 'o' or P.Pole_gry[wiersz2][pom2] == 'O')) {
			
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Pion1::Czy_Pion_AI(int kolumna, int wiersz, Plansza &P) {
	int pom = kolumna;
	int pom2 = wiersz;

	if (P.Pole_gry[pom2][pom] == 'x') {

		return true;
	}
	else if(P.Pole_gry[pom2][pom] == ' ' or P.Pole_gry[pom2][pom] == 'o') {
		return false;
	}
}
#endif