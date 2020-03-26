#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller() : Repository()
{

}

void Controller::add_med()
{
	cout << "Add med\n";
}

void Controller::delete_med()
{
	cout << "Delete med\n";
}

void Controller::update_med()
{
	cout << "Update med\n";
}

void Controller::search_med_name()
{

}

void Controller::search_med_quantity()
{

}

void Controller::group_by_price()
{

}

Controller::~Controller()
{

}