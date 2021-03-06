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

	Medicine old = get_element(name, concentration);

	Medicine m = update_medication(name, concentration, price);

	if (m.get_price() == price)
		cout << "Updated succesfully!\n";
	else
		cout << "Could not update.\n";

	int opt;
	cout << "\nRedo = 0/Undo = 1 ?\nOption: ";
	cin >> opt;

	if (opt == 1 and m.get_price() == price)
	{
		Medicine q = update_medication(name, concentration, old.get_price());
		cout << "Updated back!\n";
	}
	else if (opt == 0)
		update_med();
}

void Controller::search_med_name()
{
	cout << "Geben sie die bestimmte Zeichenkette fur die sie suchen:\n";

	string StringToLookFor;

	cin >> StringToLookFor;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> StringToLookFor;
	}

	vector<Medicine> ToBePrinted = Repository::search_medication_by_name(StringToLookFor);
	for (int i = 0; i < ToBePrinted.size(); i++)
		cout << ToBePrinted[i].ToString() << "\n";
	

}

void Controller::search_med_quantity()
{
	cout << "Geben sie die bestimmte Menge fur die sie suchen:\n";
	cout << "Es werden alle Produkte(falls es gibt) gezeigt dessen Menge streng kleiner( < ) ist als die eingegebene Wert!\n";

	int SearchedQuantity;

	cin >> SearchedQuantity;
	while (std::cin.fail()) {
		std::cout << "Error" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> SearchedQuantity;
	}

	vector<Medicine> ToBePrinted = Repository::search_medication_by_quantity(SearchedQuantity);
	for (int i = 0; i < ToBePrinted.size(); i++)
		cout << ToBePrinted[i].ToString() << "\n";

}

void Controller::group_by_price()
{
	vector<Medicine> ToBePrinted = Repository::group_medication_by_price();
	for (int i = 0; i < ToBePrinted.size(); i++)
		cout << ToBePrinted[i].ToString() << "\n";
}

Controller::~Controller() {};
