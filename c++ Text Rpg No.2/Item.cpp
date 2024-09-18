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
	
	for (int i = 0; i < 9; ++i)
	{
		int rendom = distribution(gen) % 10;
		if (9 == rendom)
		{
			--rendom;
		}
		ItemMMOR NewItem = { static_cast<ItemId>(rendom),ItemArr[rendom] };
		ItemBag.push_back(NewItem);
		
	}
	handleItem = ItemBag.begin();
	OpenItemBag();
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
	if (ItemId == ItemBag.end())
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

void MainItem::UseItemManuOpen()
{
	OpenItemBag();
	// ������ �� ���� ����� ���� ������
	int choice = 0;
	std::cout << std::endl << "����Ͻ� �������� ������" << std::endl;
	std::cin >> choice;
	if (0 == choice || choice > ItemBag.size())
	{
		ErrorCode();
	}
	else
	{
		handleItem = ItemBag.begin();
		for (int i = 0, item = -1; i < item; ++i)
		{
			++handleItem;
		}
	}
	UseItem(handleItem);
	
}

void MainItem::UseItem(vector<ItemMMOR>::iterator Item)
{
	
}
void MainItem::ChangeHandleItem(int item)
{
	
}

void MainItem::OpenItemBag()
{
	vector<ItemMMOR>::iterator BeginhandleItem = ItemBag.begin();

	for (int i = 0; i < ItemBag.size(); ++BeginhandleItem,++i)
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
