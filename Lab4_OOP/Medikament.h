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
	//void add_medicine(vector <Medicine>& v);

	string get_name() { return name; }

	double get_concentration() { return concentration;  }

	double get_price() { return price; }

	int get_quantity() { return quantity;  }

	void set_name(string& N) { name = N; }

	void set_concentration(double& C) { concentration = C; }

	void set_price(double& P) { price = P; }

	void set_quantity(int& Q) { quantity = Q; }

	void add_to_quantity(int& QQ) { quantity += QQ; }

	bool operator< (const Medicine& obj) const
	{
		return (this->name < obj.name);
	}
	
	~Medicine();

};

