#pragma once
#include "Repository.h"
class Controller: public Repository
{
public:
	Controller();

	~Controller();

	//adds medicine
	void add_med();

	//deletes medicine
	void delete_med();

	//updates name, concentration, price, quantity
	void update_med();
};

