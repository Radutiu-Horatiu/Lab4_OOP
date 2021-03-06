#include "Console.h"
#include <iostream>
#include <fstream>
#include "Medikament.h"

using namespace std;

Console::Console()
{
}

Console::~Console()
{
}

void Console::main()
{

	read_file(meds_getter(), "meds.txt");

	cout << "Menu\n\n";

	int opt = 69;

	cout << "Choose option:\n0 - Exit\n1 - add medication\n2 - delete medication\n3 - update medication\n4 - search meds by name\n5 - search meds by quantity\n6 - group by price\n\nYour option: ";

	while (opt != 0)
	{
		cin >> opt;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> opt;
		}

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

		cout << "Choose option:\n0 - Exit\n1 - add medication\n2 - delete medication\n3 - update medication\n4 - search meds by name\n5 - search meds by quantity\n6 - group by price\n\nYour option: ";

	}

	write_file(meds_getter(), "meds.txt");

}

