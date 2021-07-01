#include "pch.h"
#include "Plansza.hpp"
#include "Pion1.hpp"
#include "AI.hpp"
#include "Rozgrywka.hpp"

int main()
{
	Rozgrywka R;
	Pion1 A;
	Plansza P;
	AI C;

	R.Zagraj(P, A, C);
}
