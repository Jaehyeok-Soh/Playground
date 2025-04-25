#pragma once

#include "Define.h"
#include "Player.h"
#include "RendererService.h"

class Management
{
public:
	bool Start();
	void MainLobby();
	void SelectEnemy();
	void Battle(EnemyType _eType);
	void SelectJob();
	void Save();
	void Load();
	void Quit();
	bool CheckInputRange(int _iCheckInput, int _iStart, int _iEnd);
	void Release();

	Management() = default;
	~Management();

private:
	Character* m_pPlayer = new Player();
	RendererService m_Renderer;
	bool m_bIsQuit = false;
	int m_iInput = 0;
};