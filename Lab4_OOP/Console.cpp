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
	cout << "Menu\n";
	Controller::functie();
}