#pragma once

#include "json.hpp"

#include <iostream>

#include "Types.h"

using namespace std;
using json = nlohmann::json;

class Charactor
{
public:
	JOBS eMyJobs;
	int iMyMaxHealth = BASEHEALTH;
	int iMyHealth = BASEHEALTH;
	int iMyDamage = BASEDAMAGE;
	bool bIsEnemy = false;
	int iMyLevel = 1;
	int iMyExp = 0;

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Charactor, name, level);

	void PrintMyJob();

	void PrintMyState();

	bool Battle(Charactor* pEnemy);

	Charactor() {};
	Charactor(JOBS eInitMyJob, int iInitHealth, int iInitDamage, int iInitLevel, bool bInitIsEnemy = true)
	{
		eMyJobs = eInitMyJob;
		iMyMaxHealth = iInitHealth;
		iMyHealth = iInitHealth;
		iMyDamage = iInitDamage;
		iMyLevel = iInitLevel;
		iMyExp = iInitLevel * 10;
		bIsEnemy = bInitIsEnemy;
	}

private:
	
};

