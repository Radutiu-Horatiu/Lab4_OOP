#pragma once
#include <vector>
#include "Medikament.h"

using namespace std;

class Repository
{
public:

	vector <Medicine> meds;

	Repository();

	~Repository();

	//returns new meddication that was added
	Medicine add_medication(string name, double concentration, double price, int quantity);

	//returneaza medicamentul sters
	Medicine delete_medication(string name, double concentration);

	//returneaza medicamentul modificat
	Medicine update_medication(string name, double concentration, double price);

	Medicine get_element(string name, double concentration);

	bool search_medication_by_name(string Z);

	bool search_medication_by_quantity(int QQQQ);

	bool group_meds_by_price();


	void write_file(vector <Medicine> v, string filename);

	void read_file(vector <Medicine>& v, string filename);
};

