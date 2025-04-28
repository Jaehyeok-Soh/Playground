#pragma once
#include "Inventory.h"

class Shop
{
public:
	void Render(Player* Player);
	Shop();

private:
	Inventory m_inventory;

	void Buy(Player* Player, int _iValue);
	//void Sell(Player* Player);
	void GetList();
};