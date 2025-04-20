#include "pch.h"
#include "Field.h"

void Field::Initialize()
{
}

void Field::Update()
{
}

void Field::Release()
{
}

void Field::MapInit()
{
	for (short y = 0; y < FIELD_HEIGHT; y++)
	{
		for (short x = 0; x < FIELD_WIDTH; x++)
		{
			if (y == 0 || y == FIELD_HEIGHT - 1 || x == 0 || x == FIELD_WIDTH - 1)
				m_tInfo.m_cMap[y][x] = FIELD_END_LINE;
			else
				m_tInfo.m_cMap[y][x] = ' ';
		}
	}
}

FieldInfo Field::GetInfo()
{
	return m_tInfo;
}

Field::Field()
{
	MapInit();
}

Field::~Field()
{
}