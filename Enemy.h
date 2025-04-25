#pragma once

class Enemy : public Character
{
public:
	//TODO:20250425
	Enemy() = default;
	Enemy(EnemyType _eType);
	//Enemy(int _iHealth, int _iDamage, int _iLevel, EnemyType _eType) : m_eType(_eType) {}
	~Enemy();
	
	void SetType(EnemyType _eType);

private:
	EnemyType m_eType;
};

