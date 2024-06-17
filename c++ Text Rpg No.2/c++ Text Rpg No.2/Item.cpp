#include "pch.h"
#include "Item.h"

string ItemArr[(int)ItemId::End] =
{
	"HealthPortion",
	"BigHealthPortion",
	"PowerPortion",
	"BigPowerPortion",
	"weapon1",
	"weapon2",
	"weapon3",
	"FirePortion",
	"BigFirePortion",
	
	"End"
};




void MainItem::ItemInit()
{
	//item�� �������� 3���� �߰� �ϰ� ������
	// �ϴ� 5,2,6 �̷������� ������ �õ尪 �־��
	/*
	for (int i = 0; i < (int)ItemId::End; ++i)
	{
		ItemMMOR NewItem = { static_cast<ItemId>(i),ItemArr[i]};
		ItemBag.push_back(NewItem);
	}
	*/
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister �˰����� ����ϴ� ���� ����

	// ���� �������� ������ ���� ���� (0 �̻� 99 ����)
	std::uniform_int_distribution<int> distribution(0, 99);

	
	for (int i = 0; i < 3; ++i)
	{
		int rendom = distribution(gen) % 10;
		ItemMMOR NewItem = { static_cast<ItemId>(rendom),ItemArr[rendom] };
		ItemBag.push_back(NewItem);
	}
	
	
}

void MainItem::HandleItemErase(vector<ItemMMOR>::iterator& ItemId)
{
	
	vector<ItemMMOR>::iterator it = ItemId;
	if (it != ItemBag.end())
	{
		
		ItemBag.erase(it);
	}
}

MainItem::MainItem()
	:ItemBag()
	, handleItem2{}
{
}

MainItem::~MainItem()
{
	
}
