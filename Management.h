#pragma once

#include "Types.h"
#include "Character.h"

class Management
{
public:
	Character* player = new Character();
	bool bIsQuit = false;
	int iInput = 0;

	bool Start();
	void MainLobby();
	void SelectEnemy();
	void Battle(JOBS eEnemyJob);
	void SelectJob(Character* player);
	void Save();
	void Load();
	void Quit();
	bool CheckInputRange(int iCheckInput, int iStart, int iEnd);

private:
};