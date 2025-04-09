#pragma once

#include <iostream>
#include "CharactorBase.h"

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

using namespace std;
using json = nlohmann::json;

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

		return bIsQuit;
	}

	void MainLobby()
	{
		bool loop = true;

		while (loop)
		{
			system("cls");
			tagCharactor->PrintMyState();

			cout << "1. 사냥터 2. 종료 : ";
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

			cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 5. 저장하기 6. 불러오기 : ";
			cin >> iInput;
			if (!CheckInputRange(iInput, 1, 5))
			{
				continue;
			}

			if (iInput == 1)
				Battle(BEGINNER);
			else if (iInput == 2)
				Battle(INTERMEDIATE);
			else if (iInput == 3)
				Battle(ADVANCED);
			else if (iInput == 4)
				return;
			else if (iInput == 5)
				break;
			else if (iInput == 5)
				break;

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

			cout << "1. 공격 2. 도망 : ";
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
					cout << "승리\n";
					if (tagCharactor->iMyHealth <= 0)
					{
						tagCharactor->iMyHealth = 1;
					}
					return;
				}

				if (tagCharactor->iMyHealth <= 0)
				{
					cout << "플레이어 사망\n";
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
				cout << "반복적인 잘못된 입력으로 종료합니다.";
				bIsQuit = true;
				return;
			}

			cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
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
	}
};