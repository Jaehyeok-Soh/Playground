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
		cout << "ü�� : " << iMyMaxHealth << '/' << iMyHealth << " ���ݷ� : " << iMyDamage << '\n';
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

				return;
			}

			if (iMyHealth <= 0)
			{
				cout << "�÷��̾� ���\n";
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