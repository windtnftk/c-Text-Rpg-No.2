#include"pch.h"
// �ϴ� �� ���� ����� ������� ���ĺ���
	// ĳ���� ������ ������ class
	// ���� ������ ������ class
	// ������ ������ ������ class
	// �װ� �������ִ� iterator ����� ����
	// �װ� ��� ����ؼ� ��� ����

enum class GameMode; // �̷� enum class�� �ִٰ� �̸� ����
enum class EnemyId
{
	Enemy1,
	Enemy2,
	Enemy3,
	Enemy4,
	Enemy5,
	Enemy6,
	Enemy7,
	Enemy8,
	Enemy9,
	God
};

struct B_Status
{
	string		C_Name;// ĳ���� �̸�
	int			C_Level;// ĳ���� ����
	int			C_Power;// ĳ���� ��
	int			C_Health;// ĳ���� �����
	int			C_Exp;//óġ�� ����ġ
};
struct E_Info
{
	B_Status		E_BInfo;//���� �⺻����
	B_Status		E_CurInfo;// ���� ���簪
	int				E_Plase;//���� ������ġ
	bool			E_Life;//���� ��������
};



class EneMy
{
	SINGLE(EneMy);
public:
	map<EnemyId, E_Info> E_BasicInfo;//���� �������
	map<EnemyId, E_Info>::iterator	E_Point; //�� ����
	
public:
	// ���� �ʱ�ȭ
	void EnemyInit();
	// ��ġ ������ ������ ������ִ� �Լ�
	void printEnemyInfo( E_Info& enemy);
	// ��ġ ������ ������ ������ִ� �Լ�
	void printEnemyInfo(map<EnemyId, E_Info>::iterator& enemy);
	/*
	// id �� ���� ���� �ּҰ� ��ȯ�ϴ� �Լ�
	E_Info* IdReturn(EnemyId Id);
	*/
	// ������ ���̵��� ���� ���� ������ ���� ��Ű�� �Լ�
	B_Status StatChange(GameMode CurMode, EnemyId id);
	// ���� �� ����� ��ȯ���ִ� �Լ�
	int CurSize() { return (int)EneMy::GetInst()->E_BasicInfo.size(); };
	// ������ ���̵��� ���� ���� �����ϴ� �Լ�
	void CreateEnemy( EnemyId id);
private:
	void CreateEnemy( int	id);
};

