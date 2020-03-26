#pragma once
#include <string>
#include <vector>
using namespace std;

class Medicine
{
private:

	string name;
	double concentration;
	double price;
	int quantity;

public:

	Medicine();

	Medicine(string n, double c, double p, int q);

	//adds medicine to container
	void add_medicine(vector <Medicine>& v);

	~Medicine();

};
