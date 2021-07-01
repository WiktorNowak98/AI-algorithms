#ifndef MACIERZ_HPP
#define MACIERZ_HPP

#include "pch.h"

class Macierz {

public:
	int W, K, G;

	int** tablica;

	int* koszt;

	int* numer;

	int Zwroc_Wierzch() { return W; }

	int Zwroc_Kraw() { return K; }

	Macierz(int wierzch, int dens);

	void Usun_Macierz(int wierzch);

	void Wypisz_Macierz(int wierzch);

};

Macierz::Macierz(int wierzch, int dens) {
	tablica = new int*[wierzch];
	int kraw = (dens*wierzch*(wierzch - 1) / 200);

	W = wierzch;
	K = kraw;
	G = dens;

	for (int i = 0; i < wierzch; i++) {
		
		tablica[i] = new int[wierzch];
	}
	for (int i = 0; i < wierzch; i++) {
		for (int j = 0; j < wierzch; j++) {

			tablica[i][j] = 0;
		}
	}
	int temp = kraw;
	if (dens < 100) {
		while (temp) {
			int i = rand() % wierzch;
			int j = rand() % wierzch;
			if (j > i && !tablica[i][j]) {
				temp--;
				tablica[i][j] = 1 + rand() % 9;
			}
			else if (i > j && !tablica[j][i]) {
				temp--;
				tablica[j][i] = 1 + rand() % 9;
			}
		}
	}
	else {
		for (int i = 0; i < wierzch; i++) {
			for (int j = 0; j < wierzch; j++) {
				if (j > i) {
					tablica[i][j] = 1 + rand() % 9;
				}
			}
		}
	}
}

void Macierz::Wypisz_Macierz(int wierzch) {

	std::cout << "Graf na macierzy:";

	for (int i = 0; i < wierzch; i++) {

		std::cout << std::endl << std::setw(2);

		for (int j = 0; j < wierzch; j++) {

			std::cout << std::setw(2) << tablica[i][j];
		}
	}
}

void Macierz::Usun_Macierz(int wierzch) {

	for (int i = 0; i < wierzch; i++) {

		delete[] tablica[i];
	}
	delete[] tablica;
}

bool Bellman_Ford_alg(Macierz& M, int start = 0) {
	M.koszt = new int[M.Zwroc_Wierzch()];
	M.numer = new int[M.Zwroc_Wierzch()];

	for (int i = 0; i < M.Zwroc_Wierzch(); i++) {
		M.numer[i] = -1;
		M.koszt[i] = INF;
	}
	M.koszt[start] = 0;

	for (int i = 1; i <= M.Zwroc_Wierzch(); i++) {
		for (int w = 0; w < M.Zwroc_Wierzch(); w++) {
			for (int k = 0; k < M.Zwroc_Wierzch(); k++) {
				if ((M.tablica[w][k] != 0) && (M.koszt[k]) >= (M.koszt[w] + M.tablica[w][k])) {
					M.koszt[k] = M.koszt[w] + M.tablica[w][k];
					M.numer[k] = w;
				}
			}
		}
	}
	for (int i = 0; i < M.Zwroc_Wierzch(); i++) {
		if (M.koszt[i] < 0) return false;
	}
	return true;
}

void Bellman_Ford_Pierwszy(Macierz& M) {
	int *S;
	if (Bellman_Ford_alg(M)) {
		S = new int[M.Zwroc_Wierzch()];
		int sptr = 0;
		for (int i = 0; i < M.Zwroc_Wierzch(); i++) {
			std::cout << i << ": ";
			for (int x = i; x != -1; x = M.numer[x]) {
				S[sptr++] = x;
			}
			while (sptr) {
				std::cout << S[--sptr] << " ";
			}
			std::cout << "$" << M.koszt[i] << std::endl;
		}
		delete[]S;
	}
	else {
		std::cout << "Ujemny cykl" << std::endl;
	}
	delete M.koszt;
	delete M.numer;
}

float Czas_M(Macierz& M) {
	clock_t start, stop;
	float czas;
	bool test;

	start = std::clock();
	test = Bellman_Ford_alg(M);
	stop = std::clock();

	if (test == true) {
		czas = (float)(stop - start) / CLOCKS_PER_SEC;
		return czas;
	}
	else {
		return -1;
	}
}
#endif