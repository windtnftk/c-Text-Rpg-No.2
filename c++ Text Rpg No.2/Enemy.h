#include"pch.h"
// �ϴ� �� ���� ����� ������� ���ĺ���
	// ĳ���� ������ ������ class
	// ���� ������ ������ class
	// ������ ������ ������ class
	// �װ� �������ִ� iterator ����� ����
	// �װ� ��� ����ؼ� ��� ����
enum class EnemyId
{
	Enemy1,
	Enemy2,
	Enemy3,
	Enemy4,
	God
};






struct B_Status
{
	wstring		C_Name;// ĳ���� �̸�
	short		C_Level;// ĳ���� ����
	int			C_Power;// ĳ���� ��
	int			C_Health;// ĳ���� �����
	int			C_Exp;//óġ�� ����ġ
};
struct E_Info
{
	B_Status		E_Info;//���� �⺻����
	int				E_Plase;//���� ������ġ
	bool			E_Life;//���� ��������
};



class EneMy
{
	SINGLE(EneMy);
public:
	map<EnemyId, E_Info> E_BasicInfo;//���� �������
	map<EnemyId, E_Info>::iterator	E_Point;
	// ���� �ʱ�ȭ
	void EnemyInit();
	// ��ġ ������ ������ ������ִ� �Լ�
	void printEnemyInfo(const E_Info* enemy);
	// id �� ���� ���� �ּҰ� ��ȯ�ϴ� �Լ�
	E_Info* IdReturn(EnemyId Id);
	
	
};

