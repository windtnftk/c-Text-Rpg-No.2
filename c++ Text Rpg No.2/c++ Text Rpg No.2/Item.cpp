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
	//item을 랜덤으로 3개만 추가 하고 싶은데
	// 일단 5,2,6 이런식으로 고정된 시드값 넣어보자
	/*
	for (int i = 0; i < (int)ItemId::End; ++i)
	{
		ItemMMOR NewItem = { static_cast<ItemId>(i),ItemArr[i]};
		ItemBag.push_back(NewItem);
	}
	*/
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister 알고리즘을 사용하는 엔진 생성

	// 균일 분포에서 랜덤한 정수 생성 (0 이상 99 이하)
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
