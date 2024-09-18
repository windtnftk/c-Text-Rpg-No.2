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

	End =32,

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
	SINGLE(MainItem);
public:
	// �������� ���� �������
	vector<ItemMMOR>  ItemBag;
	//�տ� �ִ� ������
	vector<ItemMMOR>::iterator handleItem; //�ϴ� privite �� ���� ����ؾ� �ɵ�
	
public:
	
	// ������ init
	void ItemInit();
	//HandleItem �����, �ϴ� privite �� ���� ����ؾ� �ɵ�
	void HandleItemErase(vector<ItemMMOR>::iterator& ItemId);
	// ������ ã���ִ� �Լ� �׸��� ������ ���� �ϴ� �Լ�
	void OpenItemBag();
	// iterator �ּҰ��� id int�� �̾ƿ��� �Լ�
	int SelectId(const vector<ItemMMOR>::iterator& ItemId);
	// iterator �ּҰ��� id string�� �̾ƿ��� �Լ�
	string SelectName(const vector<ItemMMOR>::iterator& ItemId);
	// ������ ����ϴ� �Լ�
	void UseItemManuOpen();
	// handleItem�� ������ ������ ����ϴ� �Լ�
	void UseItem(vector<ItemMMOR>::iterator Item);
	// handleItem�� ���ϴ� ��ġ�� �����ϴ� �Լ�
	void ChangeHandleItem(int item);
	// 


};

