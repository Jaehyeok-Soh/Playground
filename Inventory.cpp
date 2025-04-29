#include "pch.h"
#include "Inventory.h"

bool Inventory::AddItem(const Item& _newItem)
{
	bool result = false;
	auto item = m_mapInventory.find(_newItem.m_iId);

	if (item != m_mapInventory.end())
	{
		if (item->second.m_iId >= ItemInfo::TYPE::ARMOUR)
			return result;

		item->second.m_sAmount += 1;
	}
	else
	{
		m_mapInventory.insert({ _newItem.m_iId, _newItem });
		m_mapInventory.find(_newItem.m_iId)->second.m_sAmount = 1;
	}
	result = true;

	return result;
}

std::vector<int> Inventory::PrintInventory(bool _bEquip)
{
	int i = 1;
	iKey.clear();
	for (auto item : m_mapInventory)
	{
		iKey.push_back(item.first);

		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << i << ". " << item.second.m_strName << endl;
		cout << "가격 : " << item.second.m_sPrice << endl;
		if (item.second.m_tStats.has_value())
		{
			cout << "공격력 : " << item.second.m_tStats.value().m_iAttack << endl;
			cout << "체력 : " << item.second.m_tStats.value().m_iHealth << endl;
			if (_bEquip)
			{
				const char* c = item.second.m_bIsEquip ? "장착 중" : "장착 가능";
				cout << c << endl;
			}
		}
		if (item.second.m_tEffects.has_value())
		{
			cout << "체력 회복 : " << item.second.m_tEffects.value().m_iHeal << endl;
			cout << "개수 : " << item.second.m_sAmount << endl;
		}

		i++;
	}

	return iKey;
}

void Inventory::UpdateItem(Item item)
{
	m_mapInventory.find(item.m_iId)->second = item;
}

Item Inventory::GetItem(int _iKey)
{
	return m_mapInventory.find(_iKey)->second;
}

int Inventory::GetKey(int _index)
{
	if (iKey.size() - 1 < _index)
		return 0;

	return iKey[_index];
}

bool Inventory::IsEmpty()
{
	return m_mapInventory.empty();
}

bool Inventory::Remove(int _iKey)
{
	return m_mapInventory.erase(_iKey);
}

const std::map<int, Item>& Inventory::GetItems() const
{
	return m_mapInventory;
}

void Inventory::SetItems(const std::map<int, Item>& items)
{
	m_mapInventory = items;
}

