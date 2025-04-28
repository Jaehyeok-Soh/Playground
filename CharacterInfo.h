#pragma once

#include "json.hpp"

#define BASEHEALTH 100;
#define BASEDAMAGE 10;

struct DATA_JSON
{
	std::string save_path;
	std::string item_path;

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(DATA_JSON, save_path, item_path);
};

/// <summary>
/// Character obj info
/// </summary>
enum JOB_TYPES
{
	NONE = 0,
	WARRIOR,
	MAGE,
	ROGUE,
};

enum ENEMY_TYPES
{
	BEGINNER = 1,
	INTERMEDIATE,
	ADVANCED,
};

enum CHARACTER_STATES
{
	WAIT = 1,
	WALK,
	RUN,
	ATTACK,
	DEAD,
};
/// Character obj info End

inline void to_json(json& j, const JOB_TYPES& job)
{
	j = static_cast<int>(job);
}

inline void from_json(const json& j, JOB_TYPES& job)
{
	job = static_cast<JOB_TYPES>(j.get<int>());
}

inline void to_json(json& j, const CHARACTER_STATES& c)
{
	j = static_cast<int>(c);
}

inline void from_json(const json& j, CHARACTER_STATES& c)
{
	c = static_cast<CHARACTER_STATES>(j.get<int>());
}