// Casino.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Gra.cpp"
using namespace std;

int main()
{
	
	Gracz gracz("Adam", 150.0);
	
	bool wyjscie = false;

	while (wyjscie == false) 
	{
		cout << "Wybierz co chcesz zrobic. Wprowadz odpowiednia cyfre." << "\n";
		cout << "1. Ruletka" << "\n";
		cout << "2. Oczko" << "\n";
		cout << "3. Jednoreki bandyta" << "\n";
		cout << "4. Podejrzyj najlepsze wyniki" << "\n";
		cout << "5. Wyjdz" << "\n";

		int WyborMenu;
		cin >> WyborMenu;

		switch (WyborMenu) 
		{
		case 1: {
			Gra gra(gracz);
			gra.WybierzGre();

			cout << "Gramy w Ruletke" << "\n";
			break;
		}
		case 2:
			cout << "Oczko" << "\n";
			break;
		case 3:
			cout << "Jednoreki bandyta" << "\n";
			break;
		case 4:
			cout << "Najlepsze wyniki to : ...." << "\n";
			break;
		case 5:
			wyjscie = true;
			cout << "Zapraszamy ponownie !" << "\n";
			break;
		}
	}

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
