#include "pch.h"

#include "Character.h"

void Character::SetMyJob(JOBS _eJob)
{
	this->m_eMyJobs = _eJob;
}

void Character::PrintMyJob()
{
	switch (m_eMyJobs)
	{
	case WARRIOR:
		cout << "����";
		break;

	case MAGE:
		cout << "������";
		break;

	case ROGUE:
		cout << "����";
		break;

	case BEGINNER:
		cout << "�ʱ�";
		break;

	case INTERMEDIATE:
		cout << "�߱�";
		break;

	case ADVANCED:
		cout << "���";
		break;
	}
}

void Character::PrintMyState()
{
	cout << "=================================\n";
	cout << "�̸� : ";
	PrintMyJob();
	cout << '\n';
	cout << "ü�� : " << m_iMyHealth << '/' << m_iMyMaxHealth << "\t���ݷ� : " << m_iMyDamage << '\n';
	if (!m_bIsEnemy)
	{
		cout << "LEVEL : " << m_iMyLevel << "\tEXP : " << m_iMyExp << '\n';
	}
}

bool Character::Battle(Character* _pEnemy)
{
	bool bIsContinued = true;
	m_iMyHealth -= _pEnemy->m_iMyDamage;
	_pEnemy->m_iMyHealth -= m_iMyDamage;

	if (!m_bIsEnemy)
	{
		if (_pEnemy->m_iMyHealth <= 0)
		{
			cout << "�¸�\n";
			if (m_iMyHealth <= 0)
			{
				m_iMyHealth = 1;
			}

			m_iMyExp += _pEnemy->m_iMyExp;
			if (m_iMyExp >= m_iMyLevel * 10)
			{
				m_iMyLevel += 1;
				m_iMyExp = 0;

				m_iMyMaxHealth += 10;
				m_iMyHealth = m_iMyMaxHealth;
				m_iMyDamage += 1;
			}
			bIsContinued = false;
			return bIsContinued;
		}

		if (m_iMyHealth <= 0)
		{
			cout << "�÷��̾� ���\n";
			m_iMyHealth = m_iMyMaxHealth;

			bIsContinued = false;
			return bIsContinued;
		}
	}

	return bIsContinued;
}

Character::Character()
{
	//empty
}

Character::Character(JOBS _eInitMyJob, int _iInitHealth, int _iInitDamage, int _iInitLevel, bool _bInitIsEnemy)
{
	m_eMyJobs = _eInitMyJob;
	m_iMyMaxHealth = _iInitHealth;
	m_iMyHealth = _iInitHealth;
	m_iMyDamage = _iInitDamage;
	m_iMyLevel = _iInitLevel;
	m_iMyExp = _iInitLevel * 10;
	m_bIsEnemy = _bInitIsEnemy;
}

void to_json(nlohmann::json& j, const JOBS& c) {
	switch (c) {
	case JOBS::WARRIOR: j = "Warrior"; break;
	case JOBS::MAGE:    j = "Mage"; break;
	case JOBS::ROGUE:  j = "Rogue"; break;
	case JOBS::BEGINNER: j = "Beginner"; break;
	case JOBS::INTERMEDIATE: j = "Intermediate"; break;
	case JOBS::ADVANCED: j = "Advanced"; break;
	}
}

void from_json(const nlohmann::json& j, JOBS& c) {
	std::string s = j.get<std::string>();
	if (s == "Warrior") c = JOBS::WARRIOR;
	else if (s == "Mage") c = JOBS::MAGE;
	else if (s == "Rogue") c = JOBS::ROGUE;
	else if (s == "Beginner") c = JOBS::BEGINNER;
	else if (s == "Intermediate") c = JOBS::INTERMEDIATE;
	else if (s == "Advanced") c = JOBS::ADVANCED;
	else throw std::invalid_argument("Invalid role: " + s);
}