#include "pch.h"

#include "json.hpp"
#include "Character.h"
using json = nlohmann::json;

void Character::PrintStatus()
{
	cout << "=================================\n";
	cout << "이름 : " << m_sName << '\n';
	cout << "체력 : " << m_iHealth << '/' << m_iMaxHealth << "\t공격력 : " << m_iDamage << '\n';
	if (!m_bIsEnemy)
	{
		cout << "LEVEL : " << m_iLevel << "\tEXP : " << m_iExp << '\n';
	}
}

bool Character::Battle(Character* _pEnemy)
{
	bool bIsContinued = true;
	m_iHealth -= _pEnemy->m_iDamage;
	_pEnemy->m_iHealth -= m_iDamage;

	if (!m_bIsEnemy)
	{
		if (_pEnemy->m_iHealth <= 0)
		{
			cout << "승리\n";
			if (m_iHealth <= 0)
			{
				m_iHealth = 1;
			}

			m_iExp += _pEnemy->m_iExp;
			if (m_iExp >= m_iLevel * 10)
			{
				m_iLevel += 1;
				m_iExp = 0;

				m_iMaxHealth += 10;
				m_iHealth = m_iMaxHealth;
				m_iDamage += 1;
			}
			bIsContinued = false;
			return bIsContinued;
		}

		if (m_iHealth <= 0)
		{
			cout << "플레이어 사망\n";
			m_iHealth = m_iMaxHealth;

			bIsContinued = false;
			return bIsContinued;
		}
	}

	return bIsContinued;
}

void Character::Set_Job(JOBS job) {}

void Character::SetType(EnemyType _eType) {}

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