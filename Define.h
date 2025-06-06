#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p = nullptr;}

///Render_Info
#define FIELD_WIDTH 120
#define FIELD_HEIGHT 20
#define FIELD_END_LINE '#'
#define PLAYER_1X9 "(/.^��^.)/"
#define FIELD_WALL_OBJECT '='
#define FIELD_DOOR_OBJECT '+'
//Render_Info_End

struct FieldInfo
{
	char m_cMap[FIELD_HEIGHT][FIELD_WIDTH];
	int m_iEnemy_Count = 0;
	bool m_bEnableBattle = true;
};