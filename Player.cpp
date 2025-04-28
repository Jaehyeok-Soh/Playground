#include "pch.h"
#include "Player.h"

Player::Player()
{
	m_eState = WAIT;
}

Player::~Player() {}

void Player::PrintStatus()
{
	cout << "=================================\n";
	cout << "이름 : " << m_strName << '\n';
	cout << "체력 : " << m_iHealth << '/' << m_iMaxHealth << "\t공격력 : " << m_iDamage << "\t골드 : " << m_iGold << '\n';
	cout << "LEVEL : " << m_iLevel << "\tEXP : " << m_iExp << '\n';
}

void Player::Set_Job(JOB_TYPES job)
{
	m_eJob = job;
	switch (job)
	{
	case WARRIOR:
		m_strName = "WARRIOR";
		break;

	case MAGE:
		m_strName = "MAGE";
		break;

	case ROGUE:
		m_strName = "ROGUE";
		break;
	}
}

JOB_TYPES Player::Get_Job()
{
	return m_eJob;
}

bool Player::Battle(Character* _pEnemy)
{
	bool bIsContinued = true;
	m_iHealth -= _pEnemy->GetDamage();
	_pEnemy->SetHealth(-m_iDamage);

	if (!m_bIsEnemy)
	{
		if (_pEnemy->GetHealth() <= 0)
		{
			cout << "승리\n";
			if (m_iHealth <= 0)
			{
				m_iHealth = 1;
			}

			m_iExp += _pEnemy->GetExp();
			SetGold(_pEnemy->GetGold());
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