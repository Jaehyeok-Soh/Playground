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

	void PrintMyState()
	{
		cout << "=================================\n";
		cout << "�̸� : ";
		PrintMyClass();
		cout << '\n';
		cout << "ü�� : " << iMyHealth << " ���ݷ� : " << iMyDamage << '\n';
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