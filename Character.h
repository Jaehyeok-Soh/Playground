#pragma once

#include "json.hpp"

#include <iostream>

#include "Define.h"

using namespace std;
using json = nlohmann::json;

class Character
{
protected:
	JOBS m_eMyJobs;
	int m_iMyMaxHealth = BASEHEALTH;
	int m_iMyHealth = BASEHEALTH;
	int m_iMyDamage = BASEDAMAGE;
	bool m_bIsEnemy = false;
	int m_iMyLevel = 1;
	int m_iMyExp = 0;

public:
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Character
		, m_eMyJobs
		, m_iMyMaxHealth
		, m_iMyHealth
		, m_iMyDamage
		, m_bIsEnemy
		, m_iMyLevel
		, m_iMyExp);

	void SetMyJob(JOBS _job);
	void PrintMyJob();
	void PrintMyState();
	bool Battle(Character* _pEnemy);

public :
	Character();
	Character(JOBS _eInitMyJob, int _iInitHealth, int _iInitDamage, int iInitLevel, bool _bInitIsEnemy = true);
private:
};

