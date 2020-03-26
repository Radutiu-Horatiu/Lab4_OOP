#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller() : Repository()
{

}

void Controller::add_med()
{
	cout << "Add med\n";
	Repository::add_medication();
}

void Controller::delete_med()
{
	cout << "Delete med\n";
	Repository::delete_medication();
}

void Controller::update_med()
{
	cout << "Update med\n";
	Repository::update_medication();
}

void Controller::search_med_name()
{
	Repository::search_medication_by_name();
}

void Controller::search_med_quantity()
{
	Repository::search_medication_by_quantity();
}

void Controller::group_by_price()
{
	Repository::group_meds_by_price();
}

Controller::~Controller()
{

}