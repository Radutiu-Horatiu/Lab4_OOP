#pragma once
#include <string>

using namespace std;

class Medicine
{
private:

	string name;
	double concentration;
	double price;
	string quantity;

public:

	Medicine(string n, double c, double p, string q);

	~Medicine();



};
