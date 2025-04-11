#include "Charactor.h"

void Charactor::PrintMyJob()
{
	switch (eMyJobs)
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

void Charactor::PrintMyState()
{
	cout << "=================================\n";
	cout << "�̸� : ";
	PrintMyJob();
	cout << '\n';
	cout << "ü�� : " << iMyMaxHealth << '/' << iMyHealth << " ���ݷ� : " << iMyDamage << '\n';
	if (!bIsEnemy)
	{
		cout << "LEVEL : " << iMyLevel << "EXP : " << iMyExp << '\n';
	}
}

bool Charactor::Battle(Charactor* pTagEnemy)
{
	bool bIsContinued = true;
	iMyHealth -= pTagEnemy->iMyDamage;
	pTagEnemy->iMyHealth -= iMyDamage;

	if (!bIsEnemy)
	{
		if (pTagEnemy->iMyHealth <= 0)
		{
			cout << "�¸�\n";
			if (iMyHealth <= 0)
			{
				iMyHealth = 1;
			}

			iMyExp += pTagEnemy->iMyExp;
			if (iMyExp >= iMyLevel * 10)
			{
				int iOverExp = (iMyLevel * 10) % iMyExp;
				iMyLevel += 1;
				iMyExp = iOverExp;

				iMyDamage += 1;
			}
			bIsContinued = false;
			return bIsContinued;
		}

		if (iMyHealth <= 0)
		{
			cout << "�÷��̾� ���\n";
			iMyHealth = iMyMaxHealth;

			bIsContinued = false;
			return bIsContinued;
		}
	}

	return bIsContinued;
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