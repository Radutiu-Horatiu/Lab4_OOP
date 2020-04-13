#include "Repository.h"
#include <iostream>
#include <fstream>
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

vector<Medicine> Repository::search_medication_by_name(string StringToLookFor)
{
	vector<Medicine> TemporalMedicineReturnVector;

	if (meds.empty() == false)
	{
		if (StringToLookFor.empty())
		{

			std::sort(meds.begin(), meds.end());

			return meds;
		}
		else
		{
			
			for (int i = 0; i != meds.size(); ++i)
			{
				
				std::size_t found = meds[i].get_name().find(StringToLookFor);
				if (found != std::string::npos)
				{
					TemporalMedicineReturnVector.push_back(meds[i]);
				}
			}
			return TemporalMedicineReturnVector;
		}
	}
	else {
		return TemporalMedicineReturnVector;
	}
		

}

vector<Medicine> Repository::search_medication_by_quantity(int SearchedQuantity)
{
	vector<Medicine> TemporalMedicineReturnVector;
	if (meds.empty() == false)
	{
		for (int i = 0; i != meds.size(); ++i)
		{
			if (meds[i].get_quantity() < SearchedQuantity)
			{
				TemporalMedicineReturnVector.push_back(meds[i]);
			}
		}

		return TemporalMedicineReturnVector;
	}
	else {
		return TemporalMedicineReturnVector;
	}
		
}

vector<Medicine> Repository::group_medication_by_price()
{
	vector<Medicine> TemporalMedicineReturnVector;
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

		return meds;
	}
	else {
		return TemporalMedicineReturnVector;
	}
		
}

void Repository::write_file(vector <Medicine> v, string filename)
{
	ofstream fin;
	fin.open(filename, ofstream::out | ofstream::trunc);

	for (int i = 0; i < v.size(); i++)
		fin << v[i].get_name() << " " << v[i].get_concentration() << " " << v[i].get_price() << " " << v[i].get_quantity() << '\n';

	fin.close();
}

void Repository::read_file(vector <Medicine>& v, string file)
{
	ifstream myReadFile;
	string word;
	string filename = file;
	myReadFile.open(filename.c_str());

	string name;
	double con;
	double price;
	int quant;

	string temp;

	string::size_type sz;

	while (!myReadFile.eof())
	{
		Medicine m;

		myReadFile >> name;
		if (name != "")
			m.set_name(name);

		myReadFile >> temp;
		if (temp != "")
		{
			con = stod(temp, &sz);
			m.set_concentration(con);
		}

		myReadFile >> temp;
		if (temp != "")
		{
			price = stod(temp, &sz);
			m.set_price(price);
		}

		myReadFile >> temp;
		if (temp != "")
		{
			quant = stoi(temp, &sz);
			m.set_quantity(quant);
		}

		if (name != "")
			v.push_back(m);

	}

	if (v.size() > 0)
		v.erase(v.end() - 1);
	myReadFile.close();

}