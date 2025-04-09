#pragma once

#include <iostream>

#define baseHealth 100;
#define baseDamage 10;

using namespace std;

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

	void Battle(CharactorBase* pTagEnemy)
	{
		iMyHealth -= pTagEnemy->iMyDamage;
		pTagEnemy->iMyHealth -= iMyDamage;

		if (!bIsEnemy)
		{
			if (pTagEnemy->iMyHealth == 0)
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

				return;
			}

			if (iMyHealth <= 0)
			{
				cout << "플레이어 사망\n";
				iMyHealth = iMyMaxHealth;
				return;
			}
		}
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