#pragma once

#include "Field.h"

class RendererService
{
public:
	void FieldRender();
	void PlayerRender();
	void EnemyRender();
	void MoveCursor(short _x, short _y);
	void GetCurrentCursorPosition();

	RendererService();
	~RendererService();

private:
	HANDLE m_hConsole;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD m_pos;
	Field m_Field;
};

