#pragma once
#include "Item.h"

class Inventory
{
public:
	bool AddItem(const Item& _newItem);
	std::vector<int> PrintInventory(bool _bEquip = false);
	void UpdateItem(Item item);
	Item GetItem(int _iKey);
	int GetKey(int _index);
	bool IsEmpty();
	bool Remove(int _iKey);
	
	const std::map<int, Item>& GetItems() const;
	void SetItems(const std::map<int, Item>& items);

	Inventory() = default;

private:
	std::map<int, Item> m_mapInventory;
	std::vector<int> iKey;
};

inline void to_json(json& j, const Inventory& inven)
{
	j = inven.GetItems();
}
inline void from_json(const json& j, Inventory& inven)
{
	std::map<int, Item> items = j.get<std::map<int, Item>>();
	inven.SetItems(items);
}