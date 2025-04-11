#pragma once

#include "json.hpp"

#include <Windows.h>

using json = nlohmann::json;

#define BASEHEALTH 100;
#define BASEDAMAGE 10;

enum JOBS
{
	WARRIOR = 1,
	MAGE,
	ROGUE,
	BEGINNER,
	INTERMEDIATE,
	ADVANCED,
};

struct Data
{
	std::string save_path;

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, save_path);
};