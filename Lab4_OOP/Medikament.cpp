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

Medicine::Medicine()
{};


Medicine::~Medicine()
{};


