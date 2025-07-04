#include "pch.h"
#include "RendererService.h"

void RendererService::TextRender(const string* _text)
{
	std::cout << _text << std::endl;
}

void RendererService::OptionsRender(const vector<std::string>& _options)
{
	int i(1);
	for (auto item : _options)
	{
		std::cout << i << ". " << item << "  ";
		i++;
	}
}

void RendererService::StatusRender(Character* _characterBase)
{
	cout << "=================================\n";
	cout << "이름 : " << _characterBase->GetName() << '\n';

	cout << "체력 : " << _characterBase->GetHealth() << '/' << _characterBase->GetMaxHealth()
		<< "\t공격력 : " << _characterBase->GetDamage() << '\n';

	if (!_characterBase->GetIsEnemy())
	{
		cout << "골드 : " << _characterBase->GetGold()
			<< "\tLEVEL : " << _characterBase->GetLevel()
			<< "\tEXP : " << _characterBase->GetExp() << '\n';
	}
}

void RendererService::FieldRender()
{
	FieldInfo tFieldInfo = m_Field.GetInfo();
	GetCurrentCursorPosition();
	COORD currentCursorPosition = { m_pos.X, m_pos.Y };

	for (SHORT y = 0; y < FIELD_HEIGHT; y++)
	{
		for (SHORT x = 0; x < FIELD_WIDTH; x++)
		{
			MoveCursor(currentCursorPosition.X + x, currentCursorPosition.Y + y);
			cout << tFieldInfo.m_cMap[y][x];
		}
		cout << '\n';
	}
	cout << '\n';

	//for (auto y = 0; y < FIELD_HEIGHT; y++)
	//{
	//	for (auto x = 0; x < FIELD_WIDTH; x++)
	//	{
	//		cout << tFieldInfo.m_cMap[y][x];
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
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

void RendererService::MoveCursor(SHORT _x, SHORT _y)
{
	//m_pos = { _x, _y };
	//SetConsoleCursorPosition(m_hConsole, m_pos);
	SetConsoleCursorPosition(m_hConsole, {_x , _y});
}

void RendererService::GetCurrentCursorPosition()
{
	GetConsoleScreenBufferInfo(m_hConsole, &csbi);
	m_pos = { csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
}

RendererService::RendererService()
{
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	csbi = CONSOLE_SCREEN_BUFFER_INFO();
	m_pos = { 0, 0 };
}

RendererService::~RendererService()
{
}
