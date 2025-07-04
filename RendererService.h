#pragma once

#include "Field.h"
#include "Character.h"

class Character;

class IRenderer
{
public:
	virtual void TextRender(const string* _text) = 0;
	virtual void OptionsRender(const vector<std::string>& _opstions) = 0;
	virtual void StatusRender(Character* _characterBase) = 0;
	virtual void FieldRender() = 0;
	virtual void PlayerRender() = 0;
	virtual void EnemyRender() = 0;

	IRenderer() = default;
	virtual ~IRenderer() = default;
};

class RendererService : public IRenderer
{
public:
	void TextRender(const string* _text) override;
	void OptionsRender(const vector<std::string>& _options) override;
	void StatusRender(Character* _characterBase) override;
	void FieldRender() override;
	void PlayerRender() override;
	void EnemyRender() override;

	void MoveCursor(short _x, short _y);
	void GetCurrentCursorPosition();

	RendererService();
	~RendererService();

private:
	HANDLE m_hConsole;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD m_pos;
	Field m_Field;
	Player m_cCharacterObj;
};

