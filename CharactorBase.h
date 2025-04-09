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
	int iMyHealth = baseHealth;
	int iMyDamage = baseDamage;
	int exp = 0;

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
		cout << "체력 : " << iMyHealth << " 공격력 : " << iMyDamage << '\n';
	}

	void Battle(CharactorBase* pTagEnemy)
	{
		iMyHealth -= pTagEnemy->iMyDamage;
		pTagEnemy->iMyHealth -= iMyDamage;
	}

	CharactorBase() {};
	CharactorBase(classes eInitMyClass, int iInitHealth, int iInitDamage)
	{
		eMyClass = eInitMyClass;
		iMyHealth = iInitHealth;
		iMyDamage = iInitDamage;
	}
};