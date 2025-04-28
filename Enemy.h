#pragma once

class Enemy : public Character
{
public:
	//TODO:20250425
	Enemy() = default;
	Enemy(ENEMY_TYPES _eType);
	~Enemy();
	
	virtual void Set_Type(ENEMY_TYPES _eType) override;
	ENEMY_TYPES Get_Type();

	virtual void PrintStatus() override;

private:
	ENEMY_TYPES m_eType;

	// Character을(를) 통해 상속됨
	bool Battle(Character* _pEnemy) override;
	void Set_Job(JOB_TYPES job) override;
};

