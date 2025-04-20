#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p = nullptr;}

#include "json.hpp"

#define BASEHEALTH 100;
#define BASEDAMAGE 10;

//Render_Info
#define FIELD_WIDTH 120
#define FIELD_HEIGHT 20
#define FIELD_END_LINE '#'
#define PLAYER_1X9 "(/.^¤µ^.)/"
#define FIELD_WALL_OBJECT '='
#define FIELD_DOOR_OBJECT '+'

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

struct FieldInfo
{
	char m_cMap[FIELD_HEIGHT][FIELD_WIDTH];
	int m_iEnemy_Count = 0;
	bool m_bEnableBattle = true;
};


