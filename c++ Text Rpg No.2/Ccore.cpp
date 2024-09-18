#include "pch.h"
#include "Ccore.h"
#include "Item.h"
#include "Enemy.h"

void Ccore::Init()
{
	if (Ccore::GetInst()->ModeCur != GameMode::GameEnd)
	{
		MainItem::GetInst()->ItemInit();
		EneMy::GetInst()->EnemyInit();
		EneMy::GetInst()->printEnemyInfo(EneMy::GetInst()->E_Point->second);
	}
	
}

void Ccore::P_DataInit()
{
	Ccore::GetInst()->PlayerInfo = { "Player 1", 1,0 };
}
void Ccore::BattleStartInit()
{
	
	while (true)
	{
		bool End = true;
		while (End)
		{
			EneMy::GetInst()->printEnemyInfo(EneMy::GetInst()->E_Point);
			std::cout << "[1.�Ϲݰ���] " << " [2.�����ۻ��] " << "[3.����â]" << std::endl << std::endl;
			int input = 0;
			std::cin >> input;
			// �̸� �������°� ���� ��~~~
			switch (input)
			{
			case 1:
				
				End = false;
				break;
			case 2:
				
				
				break;
			case 3:


				break;
			default:
				ErrorCode();
				break;
			}
		}
	}
}

void Ccore::Progress()
{
	//EneMy::GetInst()->printEnemyInfo(EneMy::GetInst()->IdReturn(EnemyId::Enemy1));
	MainItem::GetInst()->OpenItemBag();
}
void Ccore::GameStartSetOutPut()
{
	std::cout << "<���� ���� ȭ��>" << std::endl << std::endl;
	std::cout << "1. ���� ����" << std::endl;
	std::cout << "2. ���� �̾��ϱ�" << std::endl;
	std::cout << "3. ����" << std::endl;
	std::cout << "4. ����" << std::endl;
}
void Ccore::G_M_Set()
{
	bool End = true;
	while (End)
	{
		std::cout << "1. ���� ���̵� ����" << std::endl;
		std::cout << "2. �÷��̾� �̸� ����" << std::endl;
		int input = 0;
		std::cin >> input;
		// �̸� �������°� ���� ��~~~
		switch (input)
		{
		case 1:
			std::cout << "1. ���� ���̵� �����մϴ�." << std::endl << std::endl;
			G_DifficultySeting();
			End = false;
			break;
		case 2:
			std::cout << "2. �÷��̾� �̸� �����մϴ�." << std::endl << std::endl;
			PlayerNameSeting();
			End = false;
			break;
		default:
			ErrorCode();
			break;
		}
	}
}
void Ccore::G_DifficultySeting()
{
	int input = 0;
	bool End = true;
	while (End)
	{
		std::wcout << L"\n���̵��� ���Ͻʽÿ�\n" << std::endl;
		std::cout << "1. Easy" << std::endl;
		std::cout << "2. Normal" << std::endl;
		std::cout << "3. Hard" << std::endl;
		
		std::wcin >> input;
		switch (input)
		{
		case 1:
			std::cout << "���� ���̵��� Easy �� �����մϴ�." << std::endl;
			End = false;
			ModeCur = GameMode::Easy;
			break;
		case 2:
			std::cout << "���� ���̵��� Normal �� �����մϴ�." << std::endl;
			End = false;
			ModeCur = GameMode::Normal;
			break;
		case 3:
			std::cout << "���� ���̵��� Hard �� �����մϴ�." << std::endl;
			End = false;
			ModeCur = GameMode::Hard;
			break;
		default:
			ErrorCode();
			break;
		}

	}
}
void Ccore::PlayerNameSeting()
{

	string NewName = {};
	string input;
	string boolinput;


	bool YesName = true;
	while (YesName) // ĳ���� �̸� ���� �Լ�
	{
		NewName = Ccore::GetInst()->PlayerInfo.PlayerName;
		std::wcout << L"\n���ο� �̸��� �Է��ϼ���\n";
		std::wcin.ignore(); //�Է� â �ʱ�ȭ(get line �۵��� ���� �ѹ� �����)
		std::getline(std::cin, input);

		if (!input.empty())  // �Է��� ������� ���� ���
		{
			NewName = input; // �Էµ� �̸� ���
		}

		// �ٽ�Ȯ�� â, yes �Է� �� �̸� ���� �ݺ��� ����
		// no �Է� �� �̸� �ٽ� ���� �ٽ� Ȯ��â �ݺ�
		// �ٸ��� �۵��� �ٽ� Ȯ��â ����
		while (true)
		{
			std::cout << std::endl << "������ " << NewName << "��(��) �½��ϱ�?" << std::endl;// �ٽ�Ȯ�� â
			std::cout << "yes �Ǵ� no�� �Է����ֽʽÿ�" << std::endl;
			std::cin >> boolinput;
			for (char& c : boolinput)
			{
				c = std::tolower(c);
			}
			if ("yes" == boolinput)
			{
				YesName = false;
				break;
			}
			else if ("no" == boolinput)
			{
				break;
			}
			else
			{
				ErrorCode();
			}
		}
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	Ccore::GetInst()->PlayerInfo.PlayerName = NewName;
}
void Ccore::SaveGame()
{	
	std::ofstream outFile("savegame.txt"); // ��� ��Ʈ�� ����

	if (outFile.is_open()) { // ������ ���������� ���ȴ��� Ȯ��
		outFile << Ccore::GetInst()->PlayerInfo.PlayerName << std::endl; // �÷��̾� �̸� ����
		outFile << Ccore::GetInst()->PlayerInfo.Level << std::endl;      // ���� ����
		outFile << Ccore::GetInst()->PlayerInfo.CurStage << std::endl;   // �������� ����
		outFile.close(); // ���� �ݱ�
		std::cout << "Game saved successfully." << std::endl;
	}
	else 
	{
		std::cerr << "Unable to open file for writing" << std::endl; // ���� ���� ���� �� ���� �޽��� ���
	}	
}
void Ccore::LoadGame()
{
	std::ifstream inFile("savegame.txt");
	if (inFile.is_open())
	{
		std::getline(inFile, Ccore::GetInst()->PlayerInfo.PlayerName);
		inFile >> Ccore::GetInst()->PlayerInfo.Level;
		inFile >> Ccore::GetInst()->PlayerInfo.CurStage;
		inFile.close();
	}
	else
	{
		std::cerr << "Unable to open file for reading" << std::endl;
	}
}
void Ccore::GameStartSet()
{
	bool End = true;
	while (End)
	{
		std::cout << "1. ���� ����" << std::endl;
		std::cout << "2. ���� �̾��ϱ�" << std::endl;
		std::cout << "3. ���� �����ϱ�" << std::endl;
		std::cout << "4. ���� �����ϱ�" << std::endl;
		int input = 0;
		std::cin >> input;
		// �̸� �������°� ���� ��~~~
		switch (input)
		{
		case 1:
			std::cout << "������ �����մϴ�." << std::endl;
			End = false;
			
			break;
		case 2:
			std::cout << "������ �̾��մϴ�." << std::endl;
			End = false;
			// ���� ���� X
			break;
		case 3:
			std::cout << "������ �����մϴ�." << std::endl;
			// ����â ���� ���� ����
			G_M_Set();
			break;
		case 4:
			GameOver();
			ModeCur = GameMode::GameEnd;
			End = false;
			break;
		default:
			ErrorCode();
			break;
		}
	}
}
Ccore::Ccore()
	:PlayerInfo{}
	, ModeCur(GameMode::Normal)
{
}
Ccore::~Ccore()
{

}