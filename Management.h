#pragma once

#include "Types.h"
#include "Charactor.h"

class Management
{
public:
	Charactor* player = new Charactor();
	bool bIsQuit = false;
	int iInput = 0;

	bool Start();
	void MainLobby();
	void SelectEnemy();
	void Battle(JOBS eEnemyJob);
	void SelectJob(Charactor* player);
	void Save();
	void Load();
	void Quit();
	bool CheckInputRange(int iCheckInput, int iStart, int iEnd);

private:
};