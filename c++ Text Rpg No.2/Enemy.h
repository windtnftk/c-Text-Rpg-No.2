#include"pch.h"
// �ϴ� �� ���� ����� ������� ���ĺ���
	// ĳ���� ������ ������ class
	// ���� ������ ������ class
	// ������ ������ ������ class
	// �װ� �������ִ� iterator ����� ����
	// �װ� ��� ����ؼ� ��� ����


struct BasicStatus
{
	wstring		CName;// ĳ���� �̸�
	short		CLevel;// ĳ���� ����
	int			CPower;// ĳ���� ��
	int			CHealth;// ĳ���� �����
	int			CExp;//óġ�� ����ġ
};
struct Enemy
{
	BasicStatus		EnemyInfo;//���� �⺻����
	int				EnemyPlase;//���� ������ġ
	bool			EnemyLife;//���� ��������
};





class Character
{
public:
	vector<Enemy> CharacterInfo;//���� �������

	
};

