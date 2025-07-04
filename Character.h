#pragma once

#include <iostream>
#include <windows.h>
#include <string>

#include "CharacterInfo.h"
//#include "Player.h"

using namespace std;

class Character
{
public:
	CHARACTER_STATES GetState();
	void SetState(CHARACTER_STATES _eValue);

	int GetMaxHealth();
	void SetMaxHealth(int _iValue);

	int GetHealth();
	void SetHealth(int _iValue);

	int GetDamage();
	void SetDamage(int _iValue);

	bool GetIsEnemy();
	void SetIsEnemy(bool _iValue);

	std::string GetName();
	void SetName(const string& _strValue);
	
	int GetLevel();
	void SetLevel(int _iValue);

	int GetExp();
	void SetExp(int _iValue);
	
	int GetGold();
	void SetGold(short _iValue);

	COORD GetPos();
	void SetPos(int _iX, int _iY);

	virtual void PrintStatus() = 0;
	virtual bool Battle(Character* _pEnemy) = 0;
	virtual void Set_Job(JOB_TYPES job) = 0;
	virtual void Set_Type(ENEMY_TYPES _eType) = 0;

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