#pragma once

class Enemy : public Character
{
public:
	//TODO:20250425
	Enemy() = default;
	Enemy(ENEMY_TYPES _eType);
	~Enemy();
	
	void Set_Type(ENEMY_TYPES _eType);
	ENEMY_TYPES Get_Type();

	virtual void PrintStatus() override;

private:
	ENEMY_TYPES m_eType;
};

