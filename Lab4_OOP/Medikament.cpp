#include "Repository.h"
#include "Medikament.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Medicine::Medicine() {};


Medicine::Medicine(string n, double c, double p, int q)
{
	name = n;
	concentration = c;
	price = p;
	quantity = q;
}

Medicine::~Medicine() {}

namespace patch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}

string Medicine::ToString()
{
	string StringRepresentationOfMedicine;

	StringRepresentationOfMedicine = "Name: ";

	StringRepresentationOfMedicine += name;

	StringRepresentationOfMedicine += " Concentration: ";
	StringRepresentationOfMedicine += patch::to_string(concentration);

	StringRepresentationOfMedicine += " Price: ";
	StringRepresentationOfMedicine += patch::to_string(price);


	StringRepresentationOfMedicine += " Quantity: ";
	StringRepresentationOfMedicine += patch::to_string(quantity);

	return StringRepresentationOfMedicine;
}




