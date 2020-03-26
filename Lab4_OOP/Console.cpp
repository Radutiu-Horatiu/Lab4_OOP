#include "Console.h"
#include <iostream>

using namespace std;

Console::Console()
{
}

Console::~Console()
{
}

void Console::main()
{
	cout << "Menu\n\n";

	int opt = 69;

	cout << "Choose option:\n1 - add medication\n2 - delete medication\n3 - update medication\n4 - search meds by name\n5 - search meds by quantity\n6 - group by price\n\nYour option: ";

	while (opt != 0)
	{
		cin >> opt;

		if (opt == 1)
			Controller::add_med();

		else if (opt == 2)
			Controller::delete_med();

		else if (opt == 3)
			Controller::update_med();

		else if (opt == 4)
			Controller::search_med_name();

		else if (opt == 5)
			Controller::search_med_quantity();

		else if (opt == 6)
			Controller::group_by_price();

		else if (opt == 0)
			break;

		else
			cout << "\nInvalid option!";
	}

}