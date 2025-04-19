#pragma once

class Field
{
private :
	POINT m_tPlayer_Point = { 0, 0 };
	int m_iCol;
	int m_iRow;
	int m_iEnemy_Count;
	bool m_bBattleEnable;
};