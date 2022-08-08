
#pragma once

#include "Gracz.h"
#include <string>
#include <iostream>
using namespace std;

class Gracz
{
public:
	string Imie;
	double Saldo;

	
	Gracz() = default;

	Gracz(string imie, double saldo) {
		Imie = imie;
		Saldo = saldo;
		cout << "Hej " << imie << ", masz do wydania " << saldo << " pieniazkow!" << "\n";
	}

	~Gracz()
	{
		cout << "Zniszczenie obiektu Gracz" << "\n";
	}



};