#include "Repository.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Repository::Repository() {}

Repository::~Repository() {}

Medicine Repository::add_medication(string name, double concentration, double price, int quantity)
{
	bool exista = false; //nu mai avem medicamentu

	int i;
	for (i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name and meds[i].get_concentration() == concentration)
		{
			exista = true; //exista deja
			break;
		}

	if (exista == true)
	{
		meds[i].set_concentration(price);
		meds[i].set_quantity(quantity);

		return meds[i];
	}
	else
	{
		Medicine m(name, concentration, price, quantity);
		meds.push_back(m);

		return m;
	}

}

Medicine Repository::delete_medication(string name, double concentration)
{

	Medicine sters;
	vector <Medicine> temp;

	for (int i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name and meds[i].get_concentration() == concentration)
			sters = meds[i];

	for (int i = 0; i < meds.size(); i++)
		if (meds[i].get_name() != name and meds[i].get_concentration() != concentration)
			temp.push_back(meds[i]);

	meds.clear();
	meds = temp;

	return sters;
}

Medicine Repository::get_element(string name, double concentration)
{
	Medicine m;
	for (int i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name and meds[i].get_concentration() == concentration)
			return meds[i];

	return m;
}

Medicine Repository::update_medication(string name, double concentration, double price)
{
	Medicine modificat;
	vector <Medicine> temp;

	for (int i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name and meds[i].get_concentration() == concentration)
		{
			meds[i].set_price(price);
			modificat = meds[i];
			temp.push_back(meds[i]);
		}
		else
			temp.push_back(meds[i]);

	meds.clear();
	meds = temp;

	return modificat;

}

bool Repository::search_medication_by_name(string Z)
{
	if (meds.empty() == false)
	{
		if (Z.empty())
		{
			cout << "Eingegebene Zeichenkette ist leer! Diese sind alle Produkte die enthalten sind:\n";

			std::sort(meds.begin(), meds.end());

			cout << " -------------------------------------------\n";

			for (int i = 0; i != meds.size(); ++i)
			{
				cout << "Name: " << meds[i].get_name() << "\nKoncentration: " << meds[i].get_concentration() << "\nPreis: " << meds[i].get_price() << "\nMenge: " << meds[i].get_quantity() << endl;
				cout << " -------------------------------------------\n";
			}
			cout << "\n";
			cout << "Fertig!\n";

			cout << " -------------------------------------------\n";
			return true;
		}
		else
		{
			cout << " -------------------------------------------\n";
			for (int i = 0; i != meds.size(); ++i)
			{

				std::size_t found = meds[i].get_name().find(Z);
				if (found != std::string::npos)
				{
					cout << "Name: " << meds[i].get_name() << "\nKoncentration: " << meds[i].get_concentration() << "\nPreis: " << meds[i].get_price() << "\nMenge: " << meds[i].get_quantity() << endl;
					cout << " -------------------------------------------\n";
				}
			}
			cout << "\n";
			cout << "Fertig!\n";

			cout << " -------------------------------------------\n";
			return true;
		}
	}
	else {
		cout << "Container ist leer!\n";
		return false;
	}
		

}

bool Repository::search_medication_by_quantity(int QQQQ)
{
	if (meds.empty() == false)
	{
		cout << " -------------------------------------------\n";
		for (int i = 0; i != meds.size(); ++i)
		{
			if (meds[i].get_quantity() < QQQQ)
			{
				cout << "Name: " << meds[i].get_name() << "\nKoncentration: " << meds[i].get_concentration() << "\nPreis: " << meds[i].get_price()
					<< "\nMenge: " << meds[i].get_quantity() << endl;

				cout << " -------------------------------------------\n";
			}
		}

		cout << "Fertig!\n";
		cout << " -------------------------------------------\n";
		return true;
	}
	else {
		cout << "Container ist leer!\n";
		return false;
	}
		
}

bool Repository::group_meds_by_price()
{

	if (meds.empty() == false)
	{
		for (int i = 0; i != meds.size() - 1; ++i)
			for (int j = i + 1; j != meds.size(); ++j)
				if (meds[i].get_price() > meds[j].get_price())
				{
					Medicine aux = meds[i];
					meds[i] = meds[j];
					meds[j] = aux;
				}

		cout << " -------------------------------------------\n";
		for (int i = 0; i != meds.size(); ++i)
		{
			cout << "Name: " << meds[i].get_name() << "\nPreis: " << meds[i].get_price() << endl;
			cout << " -------------------------------------------\n";
		}
		cout << "Fertig!\n";
		cout << " -------------------------------------------\n";
		return true;
	}
	else {
		cout << "Container ist leer!\n";
		return false;
	}
		
}