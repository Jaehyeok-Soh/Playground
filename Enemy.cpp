#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(EnemyType _eType)
{
	SetType(_eType);
}

//Enemy::Enemy(int _iHealth, int _iDamage, int _iLevel, EnemyType _eType)
//{
//}

Enemy::~Enemy() {}

void Enemy::SetType(EnemyType _eType)
{
	int iValue = (int)_eType;

	m_iMaxHealth = iValue * 30;
	m_iHealth = iValue * 30;
	m_iDamage = iValue * 3;
	m_iLevel = iValue * 3;
	m_iExp = iValue * 5;
	m_bIsEnemy = true;

	switch (_eType)
	{
	case BEGINNER:
		m_sName = "초급";
		break;
	case INTERMEDIATE:
		m_sName = "중급";
		break;
	case ADVANCED:
		m_sName = "고급";
		break;
	}
}
