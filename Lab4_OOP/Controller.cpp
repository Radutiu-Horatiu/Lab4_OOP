#include "Controller.h"
#include <iostream>
#include <string>

using namespace std;

Controller::Controller() : Repository() {}

void Controller::add_med()
{
	cout << "Add med\n\n";

	string name;
	double concentration;
	double price;
	int quantity;

	cout << "Name(string): ";
	cin >> name;

	cout << "Concentration(double): ";
	cin >> concentration;

	cout << "Price(double): ";
	cin >> price;

	cout << "Quantity(int): ";
	cin >> quantity;

	Medicine q = add_medication(name, concentration, price, quantity);
	cout << "Medication added succesfully!\n";

	int opt;
	cout << "\nRedo = 0/Undo = 1 ?\nOption: ";
	cin >> opt;

	if (opt == 0)
		add_med();
	else if (opt == 1)
	{
		Medicine m = delete_medication(name, concentration);
		cout << "Previous deleted!\n";
	}
}

void Controller::delete_med()
{
	cout << "Delete med\n\n";

	string name;
	double concentration;

	cout << "Name(string): ";
	cin >> name;

	cout << "Concentration(double): ";
	cin >> concentration;

	Medicine m = delete_medication(name, concentration);

	if (m.get_name() == "?")
		cout << "Medicine does not exist!\n";
	else
		cout << "Medication deleted succesfully!\n";

	int opt;
	cout << "\nRedo = 0/Undo = 1 ?\nOption: ";
	cin >> opt;

	if (opt == 1 and m.get_name() != "?")
	{
		Medicine q = add_medication(m.get_name(), m.get_concentration(), m.get_price(), m.get_quantity());
		cout << "Added back!\n";
	}
	else if (opt == 0)
		delete_med();
}

void Controller::update_med()
{
	cout << "Update med\n\n";

	string name;
	double concentration;
	double price;

	cout << "Name(string): ";
	cin >> name;

	cout << "Concentration(double): ";
	cin >> concentration;

	cout << "New Price(double): ";
	cin >> price;

	Medicine m = update_medication(name, concentration, price);

	if (m.get_price() != price)
		cout << "Updated succesfully!\n";
	else
		cout << "Could not update.\n";

	int opt;
	cout << "\nRedo = 0/Undo = 1 ?\nOption: ";
	cin >> opt;

	if (opt == 1 and m.get_price() != price)
	{
		Medicine q = update_medication(name, concentration, m.get_price());
		cout << "Updated back!\n";
	}
	else if (opt == 0)
		update_med();
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