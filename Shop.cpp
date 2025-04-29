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

		cout << endl << "1. 구매 2. 판매 3. 나가기 : ";
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "구매 품목의 번호를 입력하세요 : ";
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
		cout << "금액이 부족합니다." << endl;
		system("pause");
		return;
	}

	if (Player->m_inventory.AddItem(item))
	{
		Player->SetGold(-item.m_sPrice);
		cout << "구매 성공" << endl;
	}
	else
		cout << "구매 실패, 한 개만 보유할 수 있습니다" << endl;

	system("pause");
}

//void Shop::Sell(Player* Player)
//{
//}

Shop::Shop()
{
	GetList();
}
