#pragma once
#include "json.hpp"
using json = nlohmann::json;
#include "Character.h"

class Player : public Character
{
public:
	void Set_Job(JOBS job);

	Player();
	~Player();
private:
	JOBS m_eJob;

	friend void to_json(nlohmann::json& j, const Player& p);
	friend void from_json(const nlohmann::json& j, Player& p);
};