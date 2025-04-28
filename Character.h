#pragma once

#include <iostream>
#include <windows.h>
#include <string>

#include "CharacterInfo.h"
#include "Player.h"

using namespace std;

class Character
{
public:
	int GetDamage();
	
	int GetHealth();
	void SetHealth(int _iValue);
	
	int GetExp();
	
	void SetGold(short _iValue);
	int GetGold();

	virtual void PrintStatus();
	virtual bool Battle(Character* _pEnemy);
	virtual void Set_Job(JOB_TYPES job);
	virtual void Set_Type(ENEMY_TYPES _eType);

	Character() = default;
	Character(int _iInitHealth, int _iInitDamage, int iInitLevel, bool _bInitIsEnemy = true);
	virtual ~Character();

protected:
	CHARACTER_STATES m_eState;
	int m_iMaxHealth = BASEHEALTH;
	int m_iHealth = BASEHEALTH;
	int m_iDamage = BASEDAMAGE;
	bool m_bIsEnemy = false;
	std::string m_strName;
	int m_iLevel = 1;
	int m_iExp = 0;
	short m_iGold = 0;
	COORD pos = {0, 0};
};