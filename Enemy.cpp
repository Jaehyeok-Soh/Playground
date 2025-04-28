#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(ENEMY_TYPES _eType)
{
	Set_Type(_eType);
}

Enemy::~Enemy() {}

void Enemy::Set_Type(ENEMY_TYPES _eType)
{
	int iValue = (int)_eType;

	m_iMaxHealth = iValue * 30;
	m_iHealth = iValue * 30;
	m_iDamage = iValue * 3;
	m_iLevel = iValue * 3;
	m_iExp = iValue * 5;
	m_iGold = m_iLevel * 10;
	m_bIsEnemy = true;

	switch (_eType)
	{
	case BEGINNER:
		m_strName = "�ʱ�";
		break;
	case INTERMEDIATE:
		m_strName = "�߱�";
		break;
	case ADVANCED:
		m_strName = "���";
		break;
	}
}

ENEMY_TYPES Enemy::Get_Type()
{
	return m_eType;
}

void Enemy::PrintStatus()
{
	cout << "=================================\n";
	cout << "�̸� : " << m_strName << '\n';
	cout << "ü�� : " << m_iHealth << '/' << m_iMaxHealth << "\t���ݷ� : " << m_iDamage << '\n';
}

bool Enemy::Battle(Character* _pEnemy)
{
	return false;
}

void Enemy::Set_Job(JOB_TYPES job)
{
}
