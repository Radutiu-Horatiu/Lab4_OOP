#include "Repository.h"
#include "Medikament.h"
#include <iostream>
#include <string>

using namespace std;

Medicine::Medicine(string n, double c, double p, int q)
{
	name = n;
	concentration = c;
	price = p;
	quantity = q;
}

void Medicine::add_medicine(vector <Medicine>& v)
{
	Medicine m;
	m.name = name;
	m.concentration = concentration;
	m.price = price;
	m.quantity = quantity;

	v.push_back(m);
}

Medicine::~Medicine()
{};

