#include "pch.h"

void RendererService::FieldRender()
{
	FieldInfo tFieldInfo = m_Field.GetInfo();
	GetCurrentCursorPosition();
	COORD currentCursorPosition = { m_pos.X, m_pos.Y };

	for (auto y = 0; y < FIELD_HEIGHT; y++)
	{
		for (auto x = 0; x < FIELD_WIDTH; x++)
		{
			cout << tFieldInfo.m_cMap[y][x];
		}
		cout << '\n';
	}
	cout << '\n';
}

void RendererService::PlayerRender()
{
	m_pos = { 40, 20 };
	SetConsoleCursorPosition(m_hConsole, m_pos);
	WriteConsoleW(m_hConsole, PLAYER_1X9, 9, NULL, NULL);
}

void RendererService::EnemyRender()
{
}

void RendererService::MoveCursor(short _x, short _y)
{
	m_pos = { _x, _y };
	SetConsoleCursorPosition(m_hConsole, m_pos);
}

void RendererService::GetCurrentCursorPosition()
{
	GetConsoleScreenBufferInfo(m_hConsole, &csbi);
	m_pos = { csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
}

RendererService::RendererService()
{
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

RendererService::~RendererService()
{
}
