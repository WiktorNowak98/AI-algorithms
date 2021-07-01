#ifndef LISTA_HH
#define LISTA_HH

#include "pch.h"

class Lista {

public:
	Lista * next1;
	int v1;
	int w;
};

class Graf_Lista {

public:

	int *koszt;

	int *numer;

	int W, K, G;

	int v1, v2;

	int **tablica_pom;

	Lista **tablica;

	Lista *p, *r;

	Graf_Lista(int wierzch,int dens);

	void Wypisz_Liste(int wierzch);

	void Usun_Liste(int wierzch);

	void Usun_Tablice_Flag(int wierzch);
};

Graf_Lista::Graf_Lista(int wierzch, int dens) {

	tablica = new Lista* [wierzch];

	int kraw = (dens*wierzch*(wierzch - 1) / 200);

	W = wierzch;
	K = kraw;
	G = dens;

	for (int i = 0; i < wierzch; i++) {

		tablica[i] = NULL;
	}

	tablica_pom = new int*[wierzch];

	for (int i = 0; i < wierzch; i++) {

		tablica_pom[i] = new int[wierzch];
	}

	for (int i = 0; i < wierzch; i++) {
		for (int j = 0; j < wierzch; j++) {

			tablica_pom[i][j] = 0;
		}
	}

	int temp = kraw;

	if (dens < 100) {
		while (temp) {

			v1 = rand() % wierzch;
			v2 = rand() % wierzch;
			int waga = 1 + rand() % 9;

			if (v1 > v2 && !tablica_pom[v2][v1]) {
			
				p = new Lista;
				p->v1 = v1;
				p->w = waga;
				p->next1 = tablica[v2];
				tablica[v2] = p;
				tablica_pom[v2][v1] = 1;
				temp--;
			}
			else if (v2 > v1 && !tablica_pom[v1][v2]) {
	
				p = new Lista;
				p->v1 = v2;
				p->w = waga;
				p->next1 = tablica[v1];
				tablica[v1] = p;
				tablica_pom[v1][v2] = 1;
				temp--;
			}
		}
	}
	else {
		for (int i = 0; i < wierzch; i++) {
			for (int j = 0; j < wierzch; j++) {
				if (j > i) {

					int waga = 1 + rand() % 9;
					p = new Lista;
					p->v1 = j;
					p->w = waga;
					p->next1 = tablica[i];
					tablica[i] = p;
					tablica_pom[i][j] = 1;
				}
			}
		}
	}
}

void Graf_Lista::Wypisz_Liste(int wierzch) {

	std::cout << "Graf na liscie:" << std::endl;

	for (int i = 0; i < wierzch; i++) {

		std::cout << "tablica[" << i << "] =";
		p = tablica[i];
		while (p) {

			std::cout << std::setw(3) << p->v1;
			p = p->next1;

		}
		std::cout << std::endl;
	}
	std::cout << "Wagi w liscie:" << std::endl;

	for (int i = 0; i < wierzch; i++) {

		std::cout << "tablica[" << i << "] =";
		p = tablica[i];
		while (p) {

			std::cout << std::setw(3) << p->w;
			p = p->next1;

		}
		std::cout << std::endl;
	}
}

void Graf_Lista::Usun_Liste(int wierzch) {

	for (int i = 0; i < wierzch; i++) {
		p = tablica[i];
		while (p) {
			r = p;
			p = p->next1;
			delete r;
		}
	}
	delete[] tablica;
}

bool Bellman_Ford_alg2(Graf_Lista& L, int wierz_start = 0) {
	Lista *pv;

	for (int i = 0; i < L.W; i++) {
		L.koszt = new int[L.W];
		L.numer = new int[L.W];
	}
	for (int i = 0; i < L.W; i++) {
		L.koszt[i] = INF;
		L.numer[i] = -1;
	}
	L.koszt[wierz_start] = 0;

	for (int i = 0; i < L.W; i++) {
		for (int x = 0; x < L.W; x++) {
			for (pv = L.tablica[x]; pv; pv = pv->next1) {
				if (L.koszt[pv->v1] > L.koszt[x] + pv->w) {
					L.koszt[pv->v1] = L.koszt[x] + pv->w;
					L.numer[pv->v1] = x;
				}
			}
		}
	}
	for (int x = 0; x < L.W; x++) 
		if (L.koszt[x] < 0)
			return false;
		
		return true;
}

void Bellman_Ford_Drugi(Graf_Lista& L) {
	int *S;
	if (Bellman_Ford_alg2(L)) {
		S = new int[L.W];
		int sptr = 0;
		for (int i = 0; i < L.W; i++) {
			std::cout << i << ": ";
			for (int x = i; x != -1; x = L.numer[x]) {
				S[sptr++] = x;
			}
			while (sptr) {
				std::cout << S[--sptr] << " ";
			}
			std::cout << "$" << L.koszt[i] << std::endl;
		}
		delete[] S;
	}
	else {
		std::cout << "Ujemny cykl" << std::endl;
	}
}

float Czas_L(Graf_Lista& L) {
	clock_t start, stop;
	float czas;
	bool test;

	start = std::clock();
	test = Bellman_Ford_alg2(L);
	stop = std::clock();

	if (test == true) {
		czas = (float)(stop - start) / CLOCKS_PER_SEC;
		return czas;
	}
	else {
		return -1;
	}
}

void Graf_Lista::Usun_Tablice_Flag(int wierzch) {

	for (int i = 0; i < wierzch; i++) {

		delete[] tablica_pom[i];
	}
	delete[] tablica_pom;
}
#endif