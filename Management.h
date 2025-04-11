#pragma once

#include <iostream>

#include "json.hpp"

#include "Charactor.h"

using namespace std;
using json = nlohmann::json;

struct Management
{
	Charactor* player = new Charactor();
	bool bIsQuit = false;
	int iInput = 0;

	bool Start()
	{
		SelectJob(player);

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
			player->PrintMyState();

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

			player->PrintMyState();

			cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� 5. �����ϱ� 6. �ҷ����� : ";
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
			else if (iInput == 6)
				Save();
				break;

			system("pause");
		}
	}

	void Battle(JOBS eEnemyJob)
	{
		Charactor tagEnemy;

		switch (eEnemyJob)
		{
		case BEGINNER:
			tagEnemy = Charactor(BEGINNER, 30, 3, 3);
			break;
		case INTERMEDIATE:
			tagEnemy = Charactor(INTERMEDIATE, 60, 6, 6);
			break;
		case ADVANCED:
			tagEnemy = Charactor(ADVANCED, 90, 9, 9);
			break;
		}

		bool loop = true;

		while (loop)
		{
			system("cls");
			player->PrintMyState();
			tagEnemy.PrintMyState();

			cout << "1. ���� 2. ���� : ";
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

	void SelectJob(Charactor* plyaer)
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

		plyaer->eMyJobs = (JOBS)iInput;

		return;
	}

	bool Save()
	{
		json j;
		j = *player;
		cout << j.dump(4);
		return true;
	}

	bool Load()
	{

		return true;
	}

	void Quit()
	{
		delete player;
		player = nullptr;
	}

	bool CheckInputRange(int iCheckInput, int iStart, int iEnd)
	{
		if (iCheckInput >= iStart && iCheckInput <= iEnd)
			return true;
		else
			return false;
	}
};