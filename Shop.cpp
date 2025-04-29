#include "pch.h"
#include "Shop.h"
#include "FileManager.h"

void Shop::GetList()
{
	FileManager fileManager;
	auto items = fileManager.LoadItemList();
	for (auto item : items)
	{
		item.m_sAmount = 99;
		m_inventory.AddItem(item);
	}
}

void Shop::Render(Player* Player)
{
	bool loop(true);
	int input(0);

	while (loop)
	{
		system("cls");

		m_inventory.PrintInventory();

		cout << endl << "1. ���� 2. �Ǹ� 3. ������ : ";
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "���� ǰ���� ��ȣ�� �Է��ϼ��� : ";
			cin >> input;
			Buy(Player, input);
			break;
		case 2:
			//Sell(Player);
			break;
		case 3:
			return;
		default:
			loop = false;
		}
	}
}

void Shop::Buy(Player* Player, int _iValue)
{
	auto item = m_inventory.GetItem(m_inventory.GetKey(_iValue - 1));

	if (Player->GetGold() < item.m_sPrice)
	{
		cout << "�ݾ��� �����մϴ�." << endl;
		system("pause");
		return;
	}

	if (Player->m_inventory.AddItem(item))
	{
		Player->SetGold(-item.m_sPrice);
		cout << "���� ����" << endl;
	}
	else
		cout << "���� ����, �� ���� ������ �� �ֽ��ϴ�" << endl;

	system("pause");
}

//void Shop::Sell(Player* Player)
//{
//}

Shop::Shop()
{
	GetList();
}
