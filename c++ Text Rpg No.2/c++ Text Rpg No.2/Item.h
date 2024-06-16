#pragma once

enum class ItemId
{
	HealthPortion,
	BigHealthPortion,
	PowerPortion,
	BigPowerPortion,
	weapon1,
	weapon2,
	weapon3,
	FirePortion,
	BigFirePortion,

	End = 32,

};
// 그러니까 아이템을 사용할때 이름값만 가져오면 어떤아이템을 사용되는지 
// 확인되고 사용하는 함수? 를 만들고 싶은거자나
// enum class 는 그렇게 사용하고 여기에는 결국 뭐를 만들고 싶은거냐 
// 일단 매니저로 사용하는거는 나중에 분리하고 모든기능을 
// 이 클래스에 때려놓고
// 모듈화를 천천히 진행하자


class MainItem
{
public:
	vector<string> ItemName;//아이템 이름 저장
	string*		   HandleItem;
	vector<string>::iterator Nooo;
public:
	// 아이템 init
	void ItemInit();
	//item id입력하면 item 이름 출력
	const string HandleItemGet(ItemId ItemId);
	void HandleItemErase(ItemId ItemId);

public:
	MainItem();
	~MainItem();
		
};

