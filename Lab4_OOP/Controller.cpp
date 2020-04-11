#include "Controller.h"
#include <iostream>
#include <string>

using namespace std;

Controller::Controller() : Repository() 
{

}

void Controller::add_med()
{
	cout << "Add med\n";

	cout << "Geben sie bitte der Name des Produkts sie einfugen wollen:\n";

	string N;

	cin >> N;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> N;
	}

	double C;

	cout << "Geben sie bitte der Koncentration des Produkts sie einfugen wollen:\n";

	cin >> C;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> C;
	}

	cout << "Geben sie bitte die gewunschte Menge die sie eingeben wollen:\n";

	int QQQ;
	cin >> QQQ;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> QQQ;
	}

	cout << "Geben sie bitte die gewunschte Preis fur die Meds:\n";
	double Pri;
	cin >> Pri;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> Pri;
	}

	bool OK = Repository::add_medication(N, C, QQQ, Pri);

	while (OK == false)
	{
		cout << "Geben sie bitte der Name des Produkts sie einfugen wollen:\n";

		string N;

		cin >> N;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> N;
		}

		double C;

		cout << "Geben sie bitte der Koncentration des Produkts sie einfugen wollen:\n";

		cin >> C;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> C;
		}

		cout << "Geben sie bitte die gewunschte Menge die sie eingeben wollen:\n";

		int QQQ;
		cin >> QQQ;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> QQQ;
		}

		cout << "Geben sie bitte die gewunschte Preis fur die Meds:\n";
		double Pri;
		cin >> Pri;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> Pri;
		}

		OK = Repository::add_medication(N, C, QQQ, Pri);
	}
	
}

void Controller::delete_med()
{
	cout << "Delete med\n";

	cout << "Geben sie bitte der Name des Produkts die sie loschen wollen:\n";

	string N;

	cin >> N;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> N;
	}

	double C;

	cout << "Geben sie bitte der Koncentration des Produkts sie loschen wollen:\n";

	cin >> C;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> C;
	}

	bool OK = Repository::delete_medication(N, C);

	while (OK == false)
	{
		cout << "Geben sie bitte der Name des Produkts die sie loschen wollen:\n";

		string N;

		cin >> N;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> N;
		}

		double C;

		cout << "Geben sie bitte der Koncentration des Produkts sie loschen wollen:\n";

		cin >> C;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> C;
		}

		OK = Repository::delete_medication(N, C);
	}
}

void Controller::update_med()
{
	cout << "Update med\n";

	cout << "Geben sie bitte der Name des Produkts die sie verarbeiten wollen:\n";

	string N;

	cin >> N;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> N;
	}

	double C;

	cout << "Geben sie bitte der Koncentration des Produkts sie verarbeiten wollen:\n";

	cin >> C;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> C;
	}

	cout << "Was wollen sie verarbeiten?\n";

	cout << "\n1 - Preis verandern\n2 - Menge verandern\n0 - Nichts";

	int opt = 69;
	int update_price = -1;
	int update_quantity = -1;


	while (opt != 0) {

		cin >> opt;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> opt;
		}

		if (opt == 1)
		{
			
			cout << "Geben sie bitte die gewunschte Preis fur die Meds:\n";
			double Pri;
			cin >> Pri;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> Pri;
			}
			update_price = Pri;
		}

		if (opt == 2)
		{
			
			cout << "Geben sie bitte die gewunschte Menge die sie eingeben wollen:\n";

			int QQQ;
			cin >> QQQ;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> QQQ;
			}
			update_quantity = QQQ;
		}

		cout << "Was wollen sie verarbeiten?\n";

		cout << "\n1 - Preis verandern\n2 - Menge verandern\n0 - Nichts";

	}

	bool OK = true;

	if (update_price == -1 && update_quantity == -1) {
		return;
	}
	else
	{
		OK = Repository::update_medication(N, C, update_quantity, update_price);
	}

	while (OK == false) {

		cout << "Was wollen sie verarbeiten?\n";

		cout << "\n1 - Preis verandern\n2 - Menge verandern\n0 - Nichts";

		int opt = 69;
		int update_price = -1;
		int update_quantity = -1;


		while (opt != 0) {

			cin >> opt;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> opt;
			}

			if (opt == 1)
			{

				cout << "Geben sie bitte die gewunschte Preis fur die Meds:\n";
				double Pri;
				cin >> Pri;
				while (std::cin.fail()) {
					std::cout << "Error" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> Pri;
				}
				update_price = Pri;
			}

			if (opt == 2)
			{

				cout << "Geben sie bitte die gewunschte Menge die sie eingeben wollen:\n";

				int QQQ;
				cin >> QQQ;
				while (std::cin.fail()) {
					std::cout << "Error" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> QQQ;
				}
				update_quantity = QQQ;
			}

			cout << "Was wollen sie verarbeiten?\n";

			cout << "\n1 - Preis verandern\n2 - Menge verandern\n0 - Nichts";

		}

		OK = Repository::update_medication(N, C, update_quantity, update_price);
	}


	/*
	while (OK == false)
	{
		cout << "Geben sie bitte der Name des Produkts die sie suchen wollen:\n";

		string N;

		cin >> N;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> N;
		}

		double C;

		cout << "Geben sie bitte der Koncentration des Produkts sie suchen wollen:\n";

		cin >> C;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> C;
		}

		cout << "Was wollen sie verarbeiten?\n";

		cout << "\n1 - Name verandern\n2 - Koncentration verandern\n3 - Preis verandern\n4 - Menge verandern\n";

		int opt = 69;

		vector <bool> updates = { false, false, false, false };

		while (opt != 0) {

			cin >> opt;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> opt;
			}

			if (opt == 1) 
			{
				updates[0] = true;
			}

			if (opt == 2) 
			{
				updates[1] = true;
			}

			if (opt == 3) 
			{
				updates[2] = true;
			}

			if (opt == 4) 
			{
				updates[3] = true;
			}

			else if (opt == 0) 
			{
			
			}
		}

		OK = Repository::update_medication(N, C);
	}
	*/
}

void Controller::search_med_name()
{
	cout << "Geben sie die bestimmte Zeichenkette fur die sie suchen:\n";

	string Z;

	cin >> Z;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> Z;
	}

	Repository::search_medication_by_name(Z);
}

void Controller::search_med_quantity()
{
	cout << "Geben sie die bestimmte Menge fur die sie suchen:\n";

	int QQQQ;

	cin >> QQQQ;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> QQQQ;
	}

	cout << "Es werden alle Produkte(falls es gibt) gezeigt dessen Menge streng kleiner( < ) ist als die eingegebene Wert!\n";

	Repository::search_medication_by_quantity(QQQQ);
}

void Controller::group_by_price()
{
	Repository::group_meds_by_price();
}

Controller::~Controller()
{

}