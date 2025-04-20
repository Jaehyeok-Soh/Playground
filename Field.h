#pragma once

class Field
{
public :
	void Initialize();
	void Update();
	void Release();
	void MapInit();
	FieldInfo GetInfo();
	Field();
	~Field();

protected :
	FieldInfo m_tInfo;
};