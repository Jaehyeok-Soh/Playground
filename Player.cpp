#include "pch.h"
#include "Player.h"

Player::Player()
{
	m_eState = WAIT;
}

Player::~Player() {}

bool Player::SetEquipment(int _iKey)
{
	bool result = false;

	auto item = m_inventory.GetItem(_iKey);

	if (item.m_iId < 200 && m_iHealth < m_iMaxHealth)
	{
		m_iHealth += item.m_tEffects.value().m_iHeal;
		item.m_sAmount--;
		if (item.m_sAmount <= 0)
			m_inventory.Remove(item.m_iId);
		result = true;
	}

	if (item.m_iId >= 200)
	{
		item.m_bIsEquip = !item.m_bIsEquip;

		if (item.m_bIsEquip)
		{
			m_iMaxHealth += item.m_tStats.value().m_iHealth;
			m_iDamage += item.m_tStats.value().m_iAttack;
		}
		else
		{
			m_iMaxHealth -= item.m_tStats.value().m_iHealth;
			m_iDamage -= item.m_tStats.value().m_iAttack;
		}
		m_inventory.UpdateItem(item);
		result = true;
	}

	if (m_iHealth > m_iMaxHealth)
	{
		m_iHealth = m_iMaxHealth;
	}

	return result;
}

void Player::Set_Type(ENEMY_TYPES _eType) {}

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

void Player::OpenInventory()
{
	if (m_inventory.IsEmpty())
	{
		cout << "가방이 비었습니다." << endl;
		system("pause");
		return;
	}

	int input(0);

	m_inventory.PrintInventory(true);
	cout << "사용/해제 할 품목 번호를 입력하세요(0. 나가기) : ";
	cin >> input;
	if (!input)
	{
		return;
	}

	int key = m_inventory.GetKey(input - 1);
	if (key && SetEquipment(key))
	{
		cout << "사용/장착 완료." << endl;
	}
	else
	{
		cout << "사용/장착하지 못했습니다." << endl;
	}

	system("pause");
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