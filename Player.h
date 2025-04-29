#pragma once
#include "json.hpp"
using json = nlohmann::json;
#include "Character.h"
#include "CharacterInfo.h"
#include "Inventory.h"

class Player : public Character
{
public:
	Inventory m_inventory;
	
	JOB_TYPES Get_Job();
	void OpenInventory();

	virtual void PrintStatus() override;
	virtual void Set_Job(JOB_TYPES job) override;
	virtual bool Battle(Character* _pEnemy) override;

	Player();
	~Player();

private:
	JOB_TYPES m_eJob;

	virtual void Set_Type(ENEMY_TYPES _eType) override;

	bool SetEquipment(int _iKeyIndex);

	friend void to_json(nlohmann::json& j, const Player& p);
	friend void from_json(const nlohmann::json& j, Player& p);
};

inline void to_json(nlohmann::json& j, const Player& p) {
	j = json{
		{"m_iMaxHealth", p.m_iMaxHealth},
		{"m_iHealth", p.m_iHealth},
		{"m_iDamage", p.m_iDamage},
		{"m_bIsEnemy", p.m_bIsEnemy},
		{"m_sName", p.m_strName},
		{"m_iLevel", p.m_iLevel},
		{"m_iExp", p.m_iExp},
		{"m_iGold", p.m_iGold},
		{"m_eState", p.m_eState},
		{"m_eJob", p.m_eJob},
		{"m_inventory", p.m_inventory},
	};
}

inline void from_json(const nlohmann::json& j, Player& p) {
	j.at("m_iMaxHealth").get_to(p.m_iMaxHealth);
	j.at("m_iHealth").get_to(p.m_iHealth);
	j.at("m_iDamage").get_to(p.m_iDamage);
	j.at("m_bIsEnemy").get_to(p.m_bIsEnemy);
	j.at("m_sName").get_to(p.m_strName);
	j.at("m_iLevel").get_to(p.m_iLevel);
	j.at("m_iExp").get_to(p.m_iExp);
	j.at("m_iGold").get_to(p.m_iGold);
	j.at("m_eState").get_to(p.m_eState);
	j.at("m_eJob").get_to(p.m_eJob);
	j.at("m_inventory").get_to(p.m_inventory);
}