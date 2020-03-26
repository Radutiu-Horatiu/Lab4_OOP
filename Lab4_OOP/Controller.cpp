#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller() : Repository()
{

}

Controller::~Controller()
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