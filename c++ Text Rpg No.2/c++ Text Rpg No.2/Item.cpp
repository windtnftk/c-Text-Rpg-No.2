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
	for (int i = 0; i < (int)ItemId::End; ++i)
	{
		ItemName.push_back(ItemArr[i]);
	}
	
	
}

const string MainItem::HandleItemGet(ItemId ItemId)
{
	int RealId = (int)ItemId;
	vector<string>::iterator it = ItemName.begin()+ RealId;
	if (it != ItemName.end())
	{
		*HandleItem = *it;
	}
	return *HandleItem;
}

void MainItem::HandleItemErase(ItemId ItemId)
{
	int RealId = (int)ItemId;
	vector<string>::iterator it = ItemName.begin() + RealId;
	if (it != ItemName.end())
	{
		ItemName.erase(it);
	}
	HandleItem = nullptr;
}

MainItem::MainItem()
	:ItemName{}
	,HandleItem(nullptr)
	,Nooo()
{
}

MainItem::~MainItem()
{
	
}
