#pragma once
#include "Controller.h"
class Console : public Controller
{
public:
	Console();

	~Console();

	void main();

};

void write_file(vector <Medicine> v);

void read_file(vector <Medicine>& v);