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
		MainItem::GetInst()->ItemBag.push_back(NewItem);
	}
	
	vector<ItemMMOR>::iterator RealhandleItem = MainItem::GetInst()->ItemBag.begin();
	handleItem = RealhandleItem;
}

void MainItem::HandleItemErase(vector<ItemMMOR>::iterator& ItemId)
{
	
	vector<ItemMMOR>::iterator it = ItemId;
	if (it != ItemBag.end())
	{
		
		ItemBag.erase(it);
	}
}
int MainItem::SelectId(const vector<ItemMMOR>::iterator& ItemId)
{
	if (ItemId == MainItem::GetInst()->ItemBag.end())
	{
		std::cout << "Get Id fale" << std::endl;
		return 0;
	}
	else
	{
		ItemMMOR Hi = *ItemId;
		return (int)Hi.CurItemId;
	}
	
}
string MainItem::SelectName(const vector<ItemMMOR>::iterator& ItemId)
{
	ItemMMOR Hi = *ItemId;
	return (string)Hi.ItemName;
}

void MainItem::OpenItemBag()
{
	vector<ItemMMOR>::iterator BeginhandleItem = MainItem::GetInst()->ItemBag.begin();

	for (int i = 0; i < MainItem::GetInst()->ItemBag.size(); ++BeginhandleItem,++i)
	{
		//int GetId = GetInst()->SelectId(BeginhandleItem);
		string GetName =GetInst()->SelectName(BeginhandleItem);
		std::cout << i+1 << ". " << GetName << std::endl;
	}


}



MainItem::MainItem()
	:ItemBag()
	, handleItem{}
{
}

MainItem::~MainItem()
{
	
}
