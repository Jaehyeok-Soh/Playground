#include "pch.h"

#include <iostream>

#include "Management.h"
#include "Define.h"
#include "FileManager.h"

bool Management::Start()
{
	SelectJob();

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
		m_pPlayer->PrintStatus();

		cout << "1. ����� 2. ���� 3. ���� 4. ���� : ";
		cin >> m_iInput;
		if (!CheckInputRange(m_iInput, 1, 4))
		{
			continue;
		}

		if (m_iInput == 1)
		{
			SelectEnemy();
		}
		else if (m_iInput == 2)
		{
			shop.Render(static_cast<Player*>(m_pPlayer));
		}
		else if (m_iInput == 3)
		{
			static_cast<Player*>(m_pPlayer)->m_inventory.PrintInventory();
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

		m_pPlayer->PrintStatus();

		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� 5. �����ϱ� : ";
		cin >> m_iInput;
		if (!CheckInputRange(m_iInput, 1, 5))
		{
			continue;
		}

		if (m_iInput >= 1 && m_iInput <= 3)
			Battle((ENEMY_TYPES)m_iInput);
		else if (m_iInput == 4)
			return;
		else if (m_iInput == 5)
			Save();

		system("pause");
	}
}

void Management::Battle(ENEMY_TYPES _eType)
{
	Enemy cEnemy = Enemy(_eType);

	bool loop = true;

	while (loop)
	{
		system("cls");
		m_pPlayer->PrintStatus();
		cEnemy.PrintStatus();

		m_Renderer.FieldRender();

		cout << "1. ���� 2. ���� : ";
		cin >> m_iInput;
		if (!CheckInputRange(m_iInput, 1, 2))
		{
			continue;
		}

		if (m_iInput == 1)
		{
			loop = m_pPlayer->Battle(&cEnemy);

			continue;
		}
		else
		{
			return;
		}
		system("pause");
	}
}

void Management::SelectJob()
{
	int repeatCnt(0);

	while (1)
	{
		system("cls");

		if (repeatCnt > 3)
		{
			cout << "�߸��� �Է��� �ݺ����� �����մϴ�.";
			m_bIsQuit = true;
			return;
		}

		cout << "������ �����ϼ���.(1. ���� 2. ������ 3. ���� 4. �ҷ�����) : ";
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

	m_pPlayer->Set_Job((JOB_TYPES)m_iInput);

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
