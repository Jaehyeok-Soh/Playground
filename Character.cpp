#include "pch.h"

#include "Character.h"

void Character::SetMyJob(JOBS job)
{
	this->eMyJobs = job;
}

void Character::PrintMyJob()
{
	switch (eMyJobs)
	{
	case WARRIOR:
		cout << "전사";
		break;

	case MAGE:
		cout << "마법사";
		break;

	case ROGUE:
		cout << "도적";
		break;

	case BEGINNER:
		cout << "초급";
		break;

	case INTERMEDIATE:
		cout << "중급";
		break;

	case ADVANCED:
		cout << "고급";
		break;
	}
}

void Character::PrintMyState()
{
	cout << "=================================\n";
	cout << "이름 : ";
	PrintMyJob();
	cout << '\n';
	cout << "체력 : " << iMyMaxHealth << '/' << iMyHealth << "\t공격력 : " << iMyDamage << '\n';
	if (!bIsEnemy)
	{
		cout << "LEVEL : " << iMyLevel << "\tEXP : " << iMyExp << '\n';
	}
}

bool Character::Battle(Character* pTagEnemy)
{
	bool bIsContinued = true;
	iMyHealth -= pTagEnemy->iMyDamage;
	pTagEnemy->iMyHealth -= iMyDamage;

	if (!bIsEnemy)
	{
		if (pTagEnemy->iMyHealth <= 0)
		{
			cout << "승리\n";
			if (iMyHealth <= 0)
			{
				iMyHealth = 1;
			}

			iMyExp += pTagEnemy->iMyExp;
			if (iMyExp >= iMyLevel * 10)
			{
				iMyLevel += 1;
				iMyExp = 0;

				iMyMaxHealth += 10;
				iMyHealth = iMyMaxHealth;
				iMyDamage += 1;
			}
			bIsContinued = false;
			return bIsContinued;
		}

		if (iMyHealth <= 0)
		{
			cout << "플레이어 사망\n";
			iMyHealth = iMyMaxHealth;

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

Character::Character(JOBS eInitMyJob, int iInitHealth, int iInitDamage, int iInitLevel, bool bInitIsEnemy)
{
	eMyJobs = eInitMyJob;
	iMyMaxHealth = iInitHealth;
	iMyHealth = iInitHealth;
	iMyDamage = iInitDamage;
	iMyLevel = iInitLevel;
	iMyExp = iInitLevel * 10;
	bIsEnemy = bInitIsEnemy;
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