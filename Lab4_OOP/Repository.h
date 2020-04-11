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

	bool add_medication(string N, double C, int QQQ, double Pri,  bool okay = true);

	bool delete_medication(string N, double C, bool okay = true);

	bool update_medication(string N, double C, int Q, double P, bool okay = true);

	void search_medication_by_name(string Z);

	void search_medication_by_quantity(int QQQQ);

	void group_meds_by_price();
};

