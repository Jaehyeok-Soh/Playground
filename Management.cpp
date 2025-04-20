#include "pch.h"

#include <iostream>

#include "Management.h"
#include "Define.h"
#include "Character.h"
#include "FileManager.h"

bool Management::Start()
{
	SelectJob(m_pPlayer);

	while (!m_bIsQuit)
	{
		MainLobby();
	}

	Quit();

	return m_bIsQuit;
}

void Management::MainLobby()
{
	bool loop = true;

	while (loop)
	{
		system("cls");
		m_pPlayer->PrintMyState();

		cout << "1. 사냥터 2. 종료 : ";
		cin >> m_iInput;
		if (!CheckInputRange(m_iInput, 1, 2))
		{
			continue;
		}

		if (m_iInput == 1)
		{
			SelectEnemy();
		}
		else
		{
			m_bIsQuit = true;
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

		m_pPlayer->PrintMyState();

		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 5. 저장하기 : ";
		cin >> m_iInput;
		if (!CheckInputRange(m_iInput, 1, 5))
		{
			continue;
		}

		if (m_iInput == 1)
			Battle(BEGINNER);
		else if (m_iInput == 2)
			Battle(INTERMEDIATE);
		else if (m_iInput == 3)
			Battle(ADVANCED);
		else if (m_iInput == 4)
			return;
		else if (m_iInput == 5)
			Save();

		system("pause");
	}
}

void Management::Battle(JOBS _eEnemyJob)
{
	Character tagEnemy;

	switch (_eEnemyJob)
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
		m_pPlayer->PrintMyState();
		tagEnemy.PrintMyState();

		m_Renderer.FieldRender();

		cout << "1. 공격 2. 도망 : ";
		cin >> m_iInput;
		if (!CheckInputRange(m_iInput, 1, 2))
		{
			continue;
		}

		if (m_iInput == 1)
		{
			loop = m_pPlayer->Battle(&tagEnemy);

			continue;
		}
		else
		{
			return;
		}
		system("pause");
	}
}

void Management::SelectJob(Character* _pPlayer)
{
	int repeatCnt(0);

	while (1)
	{
		system("cls");

		if (repeatCnt > 3)
		{
			cout << "반복적인 잘못된 입력으로 종료합니다.";
			m_bIsQuit = true;
			return;
		}

		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 불러오기) : ";
		cin >> m_iInput;

		if (!CheckInputRange(m_iInput, 1, 4))
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

	if (m_iInput == 4)
	{
		Load();
		return;
	}

	_pPlayer->SetMyJob((JOBS)m_iInput);

	return;
}

void Management::Save()
{
	FileManager fileManager;
	fileManager.Save(m_pPlayer);
}

void Management::Load()
{
	FileManager fileManager;
	fileManager.Load(m_pPlayer);
}

void Management::Quit()
{
	delete m_pPlayer;
	m_pPlayer = nullptr;
}

bool Management::CheckInputRange(int _iCheckInput, int _iStart, int _iEnd)
{
	if (_iCheckInput >= _iStart && _iCheckInput <= _iEnd)
		return true;
	else
		return false;
}

void Management::Release()
{
	SAFE_DELETE(m_pPlayer)
}

Management::~Management()
{
	Release();
}
