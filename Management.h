#pragma once

#include "Define.h"
#include "Character.h"

class Management
{
public:
	bool Start();
	void MainLobby();
	void SelectEnemy();
	void Battle(JOBS _eEnemyJob);
	void SelectJob(Character* _pPlayer);
	void Save();
	void Load();
	void Quit();
	bool CheckInputRange(int _iCheckInput, int _iStart, int _iEnd);
	void Release();

public :
	~Management();

private:
	Character* m_pPlayer = new Character();
	bool m_bIsQuit = false;
	int m_iInput = 0;
};