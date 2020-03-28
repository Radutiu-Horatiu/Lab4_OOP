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

	bool OK = Repository::add_medication(N, C);

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

		OK = Repository::add_medication(N, C);
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


	bool OK = Repository::update_medication(N, C);
	while (OK == false)
	{
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

		OK = Repository::update_medication(N, C);
	}

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