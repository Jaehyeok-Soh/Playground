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

struct data
{
	path path[32];

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(data, path);
};

struct path
{
	char save[MAX_PATH];

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(path, save);
};