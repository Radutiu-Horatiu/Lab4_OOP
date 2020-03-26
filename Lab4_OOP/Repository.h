#pragma once
#include <vector>
#include "Medikament.h"

using namespace std;

class Repository
{
private:

	vector <Medicine> repo_meds;

public:

	Repository();

	~Repository();
};

