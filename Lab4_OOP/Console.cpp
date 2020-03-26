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

	int opt;

	cout << "Choose option:\n1 - add medication\n2 - delete medication\n3 - update medication\n";

	cin >> opt;

	if (opt == 1)
		Controller::add_med();

	else if (opt == 2)
		Controller::delete_med();

	else if (opt == 3)
		Controller::update_med();

}