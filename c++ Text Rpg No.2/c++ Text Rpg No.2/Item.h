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


class MainItem
{
public:
	vector<string> ItemName;//������ �̸� ����
	string*		   HandleItem;
	vector<string>::iterator Nooo;
public:
	// ������ init
	void ItemInit();
	//item id�Է��ϸ� item �̸� ���
	const string HandleItemGet(ItemId ItemId);
	void HandleItemErase(ItemId ItemId);

public:
	MainItem();
	~MainItem();
		
};

