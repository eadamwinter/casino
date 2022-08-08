#include "Gra.h"
#include <iostream>
#include "Gracz.cpp"
using namespace std;

class Gra
{
public:

	double pula;
	double _stawka;
	Gracz _gracz;


	Gra(Gracz gracz)
	{
		_gracz = gracz;
		cout << "Stworzenie obiektu Gra z graczem o imieniu " << _gracz.Imie << "\n";
	}

	~Gra()
	{
		cout << "Zniszczenie obiektu Gra" << "\n";
	}

	void WybierzGre()
	{
		
		bool wybor = false;
		while (wybor == false)
		{
			cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << "\n";
			cout << "Wybierz wariant gry!" << "\n";
			cout << "1. Obstaw jedno pole z 24??. Dzwignia 24:1" << "\n";
			cout << "2. Obstaw kolor (czarne lub czerwone). Dzwignia 1:1" << "\n";
			cout << "3. Powrot do menu glownego" << "\n";
			
			int WariantGry;
			cin >> WariantGry;

			switch (WariantGry)
			{
			case 1: {
				cout << "Gramy w Ruletke, dzwignia = 24:1" << "\n";
				PobierzStawke();
				RozliczSie(Gra241(), 24);
				break;
			}
			case 2:
				cout << "Gramy w kolor, dzwignia = 1:1" << "\n";
				PobierzStawke();
				RozliczSie(GraKolory(), 1);
				break;
			case 3:
				cout << "Wracam do Menu glownego." << "\n";
				wybor = true;
				break;
			}

			// stworz abstrakcje klasy Gra - funkcje to pobierz kase , wyplac kase
			// stworz dziedziczaca klase Ruletka
			// stworz klase do losowania (z parametrami)
			// zapisz wynik do pliku i dopisz sprawdzenie salda - jesli 0 to wypad

		}
	};

	void PobierzStawke() {
		double stawka;

		do {
			cout << "Za ile chcesz zagrac ? Masz do dyspozycji " << _gracz.Saldo << " $$" << "\n";
			cin >> stawka;

		} while (SprawdzSaldoGracza(stawka) == false);

		_stawka = stawka;
	};

	bool SprawdzSaldoGracza(double stawka)
	{


		if (stawka > _gracz.Saldo) {
			cout << "Niestety nie masz tyle hajsu. Jeszcze raz!" << "\n";
			return false;
		}
		else {
			cout << "Ok. Stawka wynosi " << stawka << "\n";
			return true;
		}
	};

	void RozliczSie(bool czyGraczWygral, int dzwignia)
	{
		if (czyGraczWygral == true) {
			WyplacKaseBoWygral(dzwignia);
		}
		else {
			WezKaseBoPrzegral(dzwignia);
		}
	};

	void WezKaseBoPrzegral(int dzwignia)
	{
		_gracz.Saldo = _gracz.Saldo - _stawka;
		cout << "Konto gracza wynosi " << _gracz.Saldo << "\n";
	};

	void WyplacKaseBoWygral(int dzwignia)
	{
		_gracz.Saldo = _gracz.Saldo + _stawka * dzwignia;
		cout << "Stawka razy dzwignia to " << _stawka * dzwignia << "\n";
		cout << "Stawka razy dzwignia po zaokragleniu to " << _stawka * dzwignia << "\n";
		cout << "Konto gracza wynosi " << _gracz.Saldo << "\n";
	};

	bool Gra241()
	{
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << "\n";
		cout << "Wybierz numer od 1 do 24" << "\n";

		int numer;
		cin >> numer;

		// tu bedzie losowanie a nie 13 zhardkodowana ...
		if (numer == 13) {
			cout << "Mia³eœ fart. Wyp³acam ile postawi³eœ razy 24 .." << "\n";
			return true;
			// wyplacasz mu - to moze byc funkcja z klasy abstract
		}
		else {
			cout << "No có¿ .. Zarobilismy. Sprobuj jeszcze raz" << "\n";
			return false;
			// pobierasz - to moze byc funkcja z klasy abstract
		}
	};

	bool GraKolory()
	{
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << "\n";
		cout << "Wybierz które obstawiasz - czerwone czy czarne ?" << "\n";
		cout << "1. Czerwone" << "\n";
		cout << "2. Czarne" << "\n";

		int kolor;
		cin >> kolor;

		// tu bedzie losowanie a nie kolor zhardkodowany ...
		if (kolor == 2) {
			cout << "Mia³eœ fart. Wyp³acam ile postawi³eœ razy 2 .." << "\n";
			return true;
			// wyplacasz mu - to moze byc funkcja z klasy abstract
		}
		else {
			cout << "No có¿ .. Zarobilismy. Sprobuj jeszcze raz" << "\n";
			return false;
			// pobierasz - to moze byc funkcja z klasy abstract
		}
	};
};

