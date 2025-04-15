#include "pch.h"

#include <iostream>

#include "Management.h"
#include "Types.h"
#include "Character.h"
#include "FileManager.h"

bool Management::Start()
{
	SelectJob(player);

	while (!bIsQuit)
	{
		MainLobby();
	}

	Quit();

	return bIsQuit;
}

void Management::MainLobby()
{
	bool loop = true;

	while (loop)
	{
		system("cls");
		player->PrintMyState();

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

void Management::SelectEnemy()
{
	bool loop = true;

	while (loop)
	{
		system("cls");

		player->PrintMyState();

		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 5. 저장하기 : ";
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
			Save();

		system("pause");
	}
}

void Management::Battle(JOBS eEnemyJob)
{
	Character tagEnemy;

	switch (eEnemyJob)
	{
	case BEGINNER:
		tagEnemy = Character(BEGINNER, 30, 3, 3);
		break;
	case INTERMEDIATE:
		tagEnemy = Character(INTERMEDIATE, 60, 6, 6);
		break;
	case ADVANCED:
		tagEnemy = Character(ADVANCED, 90, 9, 9);
		break;
	}

	bool loop = true;

	while (loop)
	{
		system("cls");
		player->PrintMyState();
		tagEnemy.PrintMyState();

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;
		if (!CheckInputRange(iInput, 1, 2))
		{
			continue;
		}

		if (iInput == 1)
		{
			loop = player->Battle(&tagEnemy);

			continue;
		}
		else
		{
			return;
		}
		system("pause");
	}
}

void Management::SelectJob(Character* player)
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

		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 불러오기) : ";
		cin >> iInput;

		if (!CheckInputRange(iInput, 1, 4))
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

	if (iInput == 4)
	{
		Load();
		return;
	}

	player->eMyJobs = (JOBS)iInput;

	return;
}

void Management::Save()
{
	FileManager fileManager;
	fileManager.Save(player);
}

void Management::Load()
{
	FileManager fileManager;
	fileManager.Load(player);
}

void Management::Quit()
{
	delete player;
	player = nullptr;
}

bool Management::CheckInputRange(int iCheckInput, int iStart, int iEnd)
{
	if (iCheckInput >= iStart && iCheckInput <= iEnd)
		return true;
	else
		return false;
}