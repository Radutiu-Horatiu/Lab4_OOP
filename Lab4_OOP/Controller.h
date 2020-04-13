#pragma once
#include "Repository.h"
class Controller: public Repository
{
private:


public:
	Controller();

	~Controller();

	//Controller Options:

	//adds medicine
	void add_med();

	//deletes medicine
	void delete_med();

	//updates name, concentration, price, quantity
	void update_med();

	//search meds by name
	void search_med_name();

	//search by quantity
	void search_med_quantity();

	//print meds grouped by price
	void group_by_price();
};

