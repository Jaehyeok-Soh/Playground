#include "pch.h"

#include "json.hpp"
#include "Character.h"
using json = nlohmann::json;

void Character::PrintStatus() {}

int Character::GetDamage()
{
	return m_iDamage;
}

int Character::GetHealth()
{
	return m_iHealth;
}

void Character::SetHealth(int _iValue)
{
	m_iHealth += _iValue;
}

int Character::GetExp()
{
	return m_iExp;
}

void Character::SetGold(short _iValue)
{
	m_iGold += _iValue;
}

int Character::GetGold()
{
	return m_iGold;
}

bool Character::Battle(Character* _pEnemy) { return false; }

void Character::Set_Job(JOB_TYPES job) {}

void Character::Set_Type(ENEMY_TYPES _eType) {}

Character::Character(int _iInitHealth, int _iInitDamage, int _iInitLevel, bool _bInitIsEnemy)
{
	//TODO: fix
	//m_iMaxHealth = _iInitHealth;
	//m_iHealth = _iInitHealth;
	//m_iDamage = _iInitDamage;
	//m_iLevel = _iInitLevel;
	//m_iExp = _iInitLevel * 10;
	//m_bIsEnemy = _bInitIsEnemy;
}

Character::~Character() {};