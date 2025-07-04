#include "pch.h"

//#include "json.hpp"
#include "Character.h"
//using json = nlohmann::json;

CHARACTER_STATES Character::GetState()
{
	return m_eState;
}

void Character::SetState(CHARACTER_STATES _eValue)
{
	m_eState = _eValue;
}

int Character::GetMaxHealth()
{
	return m_iMaxHealth;
}

void Character::SetMaxHealth(int _iValue)
{
	m_iMaxHealth = _iValue;
}

int Character::GetHealth()
{
	return m_iHealth;
}

void Character::SetHealth(int _iValue)
{
	m_iHealth = _iValue;
}

int Character::GetDamage()
{
	return m_iDamage;
}

void Character::SetDamage(int _iValue)
{
	m_iDamage = _iValue;
}

bool Character::GetIsEnemy()
{
	return m_bIsEnemy;
}

void Character::SetIsEnemy(bool _iValue)
{
	m_bIsEnemy = _iValue;
}

std::string Character::GetName()
{
	return m_strName;
}

void Character::SetName(const string& _strValue)
{
	m_strName = _strValue;
}

int Character::GetLevel()
{
	return m_iLevel;
}

void Character::SetLevel(int _iValue)
{
	m_iLevel = _iValue;
}

int Character::GetExp()
{
	return m_iExp;
}

void Character::SetExp(int _iValue)
{
	m_iExp = _iValue;
}

void Character::SetGold(short _iValue)
{
	m_iGold = _iValue;
}

int Character::GetGold()
{
	return m_iGold;
}

COORD Character::GetPos()
{
	return COORD();
}

void Character::SetPos(int _iX, int _iY)
{
}

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