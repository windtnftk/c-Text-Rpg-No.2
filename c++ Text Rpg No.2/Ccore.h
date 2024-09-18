#pragma once

enum class GameMode
{
	GameEnd,
	Easy,
	Normal,
	Hard,



	End = 10
};
struct PlayerData
{
	string	PlayerName;	//�÷��̾� �̸�
	int		Level;		//�÷��̾� ����
	int		CurStage;	//�÷��̾ ������ �������� ��ġ
};



// Main ���� ���� ��� 
class Ccore
{
	SINGLE(Ccore);
	PlayerData	PlayerInfo; // �÷��̾� ����
	GameMode	ModeCur; // ���� ������ ���� ����
	

public:
	// Main ���α׷��� �����ϱ��� �ʱⰪ ����
	void	Init();
	// Player �⺻���� Initial ���� 
	void	P_DataInit();
	// Main ���α׷��� ���ư��� �Լ�, �ϴ� ���⼭ ��� ���� �����ϵ��� ����
	void	Progress();
	// main ���ۺ� -> �÷��̾� �̸� ���ϱ� �� �⺻ ����â ����
	void	GameStartSet();
	// Game Over �Ǵ� �Լ�
	void	GameOver() { GameOff = false; };
	// Game StartSet �� �޴� ���
	void	GameStartSetOutPut();
	// GameMode ����
	void	G_M_Set();
	// Game ���̵� �����ϴ� �Լ�
	void	G_DifficultySeting();
	// Player Name �����Լ�
	void	PlayerNameSeting();
	// Player ������ �����ϴ� �Լ�
	void	SaveGame();
	// Player ������ �д� �Լ�
	void	LoadGame();
	// ����ȭ������ �����ϴ� �Լ�
	void	BattleStartInit();
	
	friend class EneMy;
};

