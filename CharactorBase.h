#pragma once

#include "json.hpp"

#include <iostream>

#define baseHealth 100;
#define baseDamage 10;

using namespace std;
using json = nlohmann::json;

enum classes
{
	WARRIOR = 1,
	MAGE,
	ROGUE,
	BEGINNER,
	INTERMEDIATE,
	ADVANCED,
};

struct CharactorBase
{
	classes eMyClass;
	int iMyMaxHealth = baseHealth;
	int iMyHealth = baseHealth;
	int iMyDamage = baseDamage;
	bool bIsEnemy = false;
	int iMyLevel = 1;
	int iMyExp = 0;

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(
		CharactorBase
		, eMyClass
		, iMyMaxHealth
		, iMyHealth
		, iMyDamage
		, bIsEnemy
		, iMyLevel
		, iMyExp);

	void PrintMyClass()
	{
		switch (eMyClass)
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

	void PrintMyState()
	{
		cout << "=================================\n";
		cout << "이름 : ";
		PrintMyClass();
		cout << '\n';
		cout << "체력 : " << iMyMaxHealth << '/' << iMyHealth << " 공격력 : " << iMyDamage << '\n';
		if (!bIsEnemy)
		{
			cout << "LEVEL : " << iMyLevel << "EXP : " << iMyExp << '\n';
		}
	}

	bool Battle(CharactorBase* pTagEnemy)
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
				cout << "플레이어 사망\n";
				iMyHealth = iMyMaxHealth;

				bIsContinued = false;
				return bIsContinued;
			}
		}

		return bIsContinued;
	}

	CharactorBase() {};
	CharactorBase(classes eInitMyClass, int iInitHealth, int iInitDamage, int iInitLevel, bool bInitIsEnemy = true)
	{
		eMyClass = eInitMyClass;
		iMyMaxHealth = iInitHealth;
		iMyHealth = iInitHealth;
		iMyDamage = iInitDamage;
		iMyLevel = iInitLevel;
		iMyExp = iInitLevel * 10;
		bIsEnemy = bInitIsEnemy;
	}
};

inline void to_json(nlohmann::json& j, const classes& c) {
	switch (c) {
	case classes::WARRIOR: j = "Warrior"; break;
	case classes::MAGE:    j = "Mage"; break;
	case classes::ROGUE:  j = "Rogue"; break;
	case classes::BEGINNER: j = "Beginner"; break;
	case classes::INTERMEDIATE: j = "Intermediate"; break;
	case classes::ADVANCED: j = "Advanced"; break;
	}
}

inline void from_json(const nlohmann::json& j, classes& c) {
	std::string s = j.get<std::string>();
	if (s == "Warrior") c = classes::WARRIOR;
	else if (s == "Mage") c = classes::MAGE;
	else if (s == "Rogue") c = classes::ROGUE;
	else if (s == "Beginner") c = classes::BEGINNER;
	else if (s == "Intermediate") c = classes::INTERMEDIATE;
	else if (s == "Advanced") c = classes::ADVANCED;
	else throw std::invalid_argument("Invalid role: " + s);
}