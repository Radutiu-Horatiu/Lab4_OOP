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

	void add_medication();

	void delete_medication();

	void update_medication();

	void search_medication_by_name();

	void search_medication_by_quantity();

	void group_meds_by_price();
};

