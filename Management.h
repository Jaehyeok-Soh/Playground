#pragma once

#include <iostream>
#include "CharactorBase.h"

using namespace std;

struct Management
{
	CharactorBase* tagCharactor;
	bool bIsQuit = false;
	int iInput = 0;

	bool Start()
	{
		tagCharactor = new CharactorBase();
		SelectClass(tagCharactor);

		while (!bIsQuit)
		{
			MainLobby();
		}

		Quit();

		return false;
	}

	void MainLobby()
	{
		bool loop = true;

		while (loop)
		{
			system("cls");
			tagCharactor->PrintMyState();

			cout << "1. ����� 2. ���� : ";
			cin >> iInput;
			if (!CheckInputRange(iInput, 1, 2))
			{
				continue;
			}

			if (iInput == 1)
			{
				SelectEnemy();
			}
			else
			{
				bIsQuit = true;
				return;
			}

			system("pause");
		}
	}

	void SelectEnemy()
	{
		bool loop = true;

		while (loop)
		{
			system("cls");

			if (tagCharactor->iMyHealth <= 0)
			{
				tagCharactor->iMyHealth = baseHealth;
			}

			tagCharactor->PrintMyState();

			cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
			cin >> iInput;
			if (!CheckInputRange(iInput, 1, 4))
			{
				continue;
			}

			if (iInput == 1)
				Battle(BEGINNER);
			else if (iInput == 2)
				Battle(INTERMEDIATE);
			else if (iInput == 3)
				Battle(ADVANCED);
			else
				return;

			system("pause");
		}
	}

	void Battle(classes eEnemyClass)
	{
		CharactorBase tagEnemy;

		switch (eEnemyClass)
		{
		case BEGINNER:
			tagEnemy = CharactorBase(BEGINNER, 30, 3);
			break;
		case INTERMEDIATE:
			tagEnemy = CharactorBase(INTERMEDIATE, 60, 6);
			break;
		case ADVANCED:
			tagEnemy = CharactorBase(ADVANCED, 90, 9);
			break;
		}

		bool loop = true;

		while (loop)
		{
			system("cls");
			tagCharactor->PrintMyState();
			tagEnemy.PrintMyState();

			cout << "1. ���� 2. ���� : ";
			cin >> iInput;
			if (!CheckInputRange(iInput, 1, 2))
			{
				continue;
			}

			if (iInput == 1)
			{
				tagCharactor->Battle(&tagEnemy);
				if (tagEnemy.iMyHealth == 0)
				{
					cout << "�¸�\n";
					if (tagCharactor->iMyHealth <= 0)
					{
						tagCharactor->iMyHealth = 1;
					}
					return;
				}

				if (tagCharactor->iMyHealth <= 0)
				{
					cout << "�÷��̾� ���\n";
					return;
				}
				continue;
			}
			else
			{
				return;
			}
			system("pause");
		}
	}

	void SelectClass(CharactorBase* tagBase)
	{
		int repeatCnt(0);

		while (1)
		{
			system("cls");

			if (repeatCnt > 3)
			{
				cout << "�ݺ����� �߸��� �Է����� �����մϴ�.";
				bIsQuit = true;
				return;
			}

			cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";
			cin >> iInput;

			if (!CheckInputRange(iInput, 1, 3))
			{
				repeatCnt++;
				continue;
			}
			else
			{
				break;
			}

			system("pause");
		}

		tagBase->eMyClass = (classes)iInput;

		return;
	}

	bool CheckInputRange(int iCheckInput, int iStart, int iEnd)
	{
		if (iCheckInput >= iStart && iCheckInput <= iEnd)
			return true;
		else
			return false;
	}

	void Quit()
	{
		delete tagCharactor;
		tagCharactor = nullptr;

		exit(0);
	}
};