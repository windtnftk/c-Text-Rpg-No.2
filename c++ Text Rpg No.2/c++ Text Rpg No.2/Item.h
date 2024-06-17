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
// �׷��ϱ� �������� ����Ҷ� �̸����� �������� ��������� ���Ǵ��� 
// Ȯ�εǰ� ����ϴ� �Լ�? �� ����� �������ڳ�
// enum class �� �׷��� ����ϰ� ���⿡�� �ᱹ ���� ����� �����ų� 
// �ϴ� �Ŵ����� ����ϴ°Ŵ� ���߿� �и��ϰ� ������� 
// �� Ŭ������ ��������
// ���ȭ�� õõ�� ��������
struct ItemMMOR
{
	ItemId		CurItemId;
	string		ItemName; //������ �̸� ����
};


class MainItem
{
public:
	// �������� ���� �������
	vector<ItemMMOR>  ItemBag;
	//�տ� �ִ� ������
	vector<ItemMMOR>::iterator handleItem;
public:
	
	// ������ init
	void ItemInit();
	//HandleItem �����
	void HandleItemErase(vector<ItemMMOR>::iterator& ItemId);
	

	

public:
	MainItem();
	~MainItem();
		
};

