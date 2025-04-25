#pragma once

#include <iostream>
#include <windows.h>

#include "Define.h"
#include "Player.h"

using namespace std;

class Character
{
public:
	void PrintStatus();
	bool Battle(Character* _pEnemy);
	virtual void Set_Job(JOBS job);
	virtual void SetType(EnemyType _eType);

	Character() = default;
	Character(int _iInitHealth, int _iInitDamage, int iInitLevel, bool _bInitIsEnemy = true);
	virtual ~Character();

protected:
	CHARACTERSTATE m_eState;
	int m_iMaxHealth = BASEHEALTH;
	int m_iHealth = BASEHEALTH;
	int m_iDamage = BASEDAMAGE;
	bool m_bIsEnemy = false;
	std::string m_sName = "";
	int m_iLevel = 1;
	int m_iExp = 0;
	COORD pos;
};