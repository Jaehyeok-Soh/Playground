#include "pch.h"
#include "Player.h"

Player::Player()
{
	m_eState = WAIT;
}

Player::~Player() {}

void Player::Set_Job(JOBS job)
{
	m_eJob = job;
	switch (job)
	{
	case WARRIOR:
		m_sName = "전사";
		break;

	case MAGE:
		m_sName = "마법사";
		break;

	case ROGUE:
		m_sName = "도적";
		break;
	}
}

void to_json(nlohmann::json& j, const Player& p) {
	j = json{
		{"m_iMaxHealth", p.m_iMaxHealth},
		{"m_iHealth", p.m_iHealth},
		{"m_iDamage", p.m_iDamage},
		{"m_bIsEnemy", p.m_bIsEnemy},
		{"m_sName", p.m_sName},
		{"m_iLevel", p.m_iLevel},
		{"m_iExp", p.m_iExp},
		{"m_eState", p.m_eState},
		{"m_eJob", p.m_eJob}
	};
}

void from_json(const nlohmann::json& j, Player& p) {
	j.at("m_iMaxHealth").get_to(p.m_iMaxHealth);
	j.at("m_iHealth").get_to(p.m_iHealth);
	j.at("m_iDamage").get_to(p.m_iDamage);
	j.at("m_bIsEnemy").get_to(p.m_bIsEnemy);
	j.at("m_sName").get_to(p.m_sName);
	j.at("m_iLevel").get_to(p.m_iLevel);
	j.at("m_iExp").get_to(p.m_iExp);
	j.at("m_eState").get_to(p.m_eState);
	j.at("m_eJob").get_to(p.m_eJob);
}

//void to_json(nlohmann::json& j, const Player& p) {
//	j = json{
//		{"m_eJob", p.m_eJob}
//	};
//}
//
//void from_json(const nlohmann::json& j, Player& p) {
//	j.at("m_eJob").get_to(p.m_eJob);
//}

void to_json(nlohmann::json& j, const JOBS& c) {
	switch (c) {
	case JOBS::WARRIOR: j = "WARRIOR"; break;
	case JOBS::MAGE:    j = "MAGE"; break;
	case JOBS::ROGUE:  j = "ROGUE"; break;
	}
}

void from_json(const nlohmann::json& j, JOBS& c) {
	std::string s = j.get<std::string>();
	if (s == "WARRIOR") c = JOBS::WARRIOR;
	else if (s == "MAGE") c = JOBS::MAGE;
	else if (s == "ROGUE") c = JOBS::ROGUE;
	else throw std::invalid_argument("Invalid role: " + s);
}

void to_json(nlohmann::json& j, const CHARACTERSTATE& c) {
	switch (c) {
	case CHARACTERSTATE::WAIT: j = "WAIT"; break;
	case CHARACTERSTATE::WALK:    j = "WALK"; break;
	case CHARACTERSTATE::RUN:  j = "RUN"; break;
	case CHARACTERSTATE::ATTACK:  j = "ATTACK"; break;
	case CHARACTERSTATE::DEAD:  j = "DEAD"; break;
	}
}

void from_json(const nlohmann::json& j, CHARACTERSTATE& c) {
	std::string s = j.get<std::string>();
	if (s == "WAIT") c = CHARACTERSTATE::WAIT;
	else if (s == "WALK") c = CHARACTERSTATE::WALK;
	else if (s == "RUN") c = CHARACTERSTATE::RUN;
	else if (s == "ATTACK") c = CHARACTERSTATE::ATTACK;
	else if (s == "DEAD") c = CHARACTERSTATE::DEAD;
	else throw std::invalid_argument("Invalid role: " + s);
}