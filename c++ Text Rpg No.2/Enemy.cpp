
#include "pch.h"
#include "Enemy.h"
#include "Ccore.h"
#include <random>

void EneMy::EnemyInit()
{	
	/*
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister 알고리즘을 사용하는 엔진 생성

	// 균일 분포에서 랜덤한 정수 생성 (0 이상 99 이하)
	std::uniform_int_distribution<int> distribution(0, 99);
	int rendom = distribution(gen) % 10;
	*/
	for (int i =0; i <= (int)EnemyId::God;++i)
	{
		EneMy::GetInst()->CreateEnemy(i);
	}
	EneMy::GetInst()->E_Point = EneMy::GetInst()->E_BasicInfo.begin();
}
void EneMy::printEnemyInfo( E_Info& enemy)
{

	std::cout << "Name: " << enemy.E_BInfo.C_Name << std::endl;
	std::cout << "Level: " << enemy.E_BInfo.C_Level << std::endl;
	std::cout << "Power: " << enemy.E_BInfo.C_Power << std::endl;
	std::cout << "Health: " << enemy.E_BInfo.C_Health << std::endl;
	std::cout << "Exp: " << enemy.E_BInfo.C_Exp << std::endl;
	std::cout << "Place: " << enemy.E_Plase << std::endl;
	std::cout << "Life: " << (enemy.E_Life ? "Alive" : "Dead") << std::endl;
}
void EneMy::printEnemyInfo(map<EnemyId, E_Info>::iterator& enemy)
{
	std::cout << "Name: " << enemy->second.E_BInfo.C_Name << std::endl;
	std::cout << "Level: " << enemy->second.E_BInfo.C_Level << std::endl;
	std::cout << "Power: " << enemy->second.E_BInfo.C_Power << std::endl;
	std::cout << "Health: " << enemy->second.E_BInfo.C_Health << std::endl;
	std::cout << "Exp: "	 << enemy->second.E_BInfo.C_Exp<< std::endl;
	std::cout << "Place: " << enemy->second.E_Plase << std::endl;
	std::cout << "Life: " << (enemy->second.E_Life ? L"Alive" : L"Dead") << std::endl;
}
/*
E_Info* EneMy::IdReturn(EnemyId Id)
{
	map<EnemyId, E_Info>::iterator It = E_BasicInfo.find(Id);
	if (It != E_BasicInfo.end())
	{
		return &It->second;
	}
	else
	{
		return nullptr;
	}
	
}
*/
	void EneMy::CreateEnemy(EnemyId id)
	{
		if (GameMode::GameEnd == Ccore::GetInst()->ModeCur)
		{
			std::wcout << L"게임 종료중에는 적을 소환 할 수 없습니다. " << std::endl;
		}
		else
		{
			switch ((int)id)
			{
			case 0:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy1, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy1),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy1),CurSize(),true });
				break;
			case 1:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy2, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy2),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy2),CurSize(),true });
				break;
			case 2:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy3, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy3),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy3),CurSize(),true });
				break;
			case 3:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy4, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy4),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy4),CurSize(),true });
				break;
			case 4:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy5, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy5),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy5),CurSize(),true });
				break;
			case 5:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy6, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy6),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy6),CurSize(),true });
				break;
			case 6:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy7, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy7),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy7),CurSize(),true });
				break;
			case 7:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy8, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy8),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy8),CurSize(),true });
				break;
			case 8:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::Enemy9, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy9),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::Enemy9),CurSize(),true });
				break;
			case 9:

				EneMy::GetInst()->E_BasicInfo.emplace
				(EnemyId::God, E_Info
					{ StatChange(Ccore::GetInst()->ModeCur, EnemyId::God),
					 StatChange(Ccore::GetInst()->ModeCur, EnemyId::God),CurSize(),true });
				break;
			}
		}

	}
	void EneMy::CreateEnemy(int	id)
{
	EneMy::GetInst()->CreateEnemy(static_cast<EnemyId>(id));
}
B_Status EneMy::StatChange(GameMode CurMode, EnemyId id)
{
	string IdName;
	int	IdLevel =0;
	int	IdPower = 0;
	int	IdHealth = 0;
	int	IdExp = 0;
	if ((int)id == 0)
	{
		IdLevel =   (int)CurMode ;
		IdPower =   (int)CurMode ;
		IdHealth =  (int)CurMode ;
		IdExp =		(int)CurMode ;
	}
	else
	{		
		IdLevel = (int)CurMode * (int)id * 1;
		IdPower = (int)CurMode * (int)id * 5;
		IdHealth = (int)CurMode * (int)id * 10;
		IdExp = (int)CurMode * (int)id * 10;
	}

	switch (id)
	{
	case EnemyId::Enemy1:
		IdName = "Enemy1";
		break;
	case EnemyId::Enemy2:
		IdName = "Enemy2";
		break;
	case EnemyId::Enemy3:
		IdName = "Enemy3";
		break;
	case EnemyId::Enemy4:
		IdName = "Enemy4";
		break;
	case EnemyId::Enemy5:
		IdName = "Enemy5";
		break;
	case EnemyId::Enemy6:
		IdName = "Enemy6";
		break;
	case EnemyId::Enemy7:
		IdName = "Enemy7";
		break;
	case EnemyId::Enemy8:
		IdName = "Enemy8";
		break;
	case EnemyId::Enemy9:
		IdName = "Enemy9";
		break;
	case EnemyId::God:
		IdName = "God";
		IdLevel = 15 * (int)CurMode;
		IdPower = 60 * (int)CurMode;
		IdHealth = 100 * (int)CurMode;
		IdExp = 500 * (int)CurMode;
		break;
	default:
		break;
	}
	
	
	return B_Status{ IdName, IdLevel, IdPower, IdHealth,IdExp };
	
}
EneMy::EneMy()
	:E_BasicInfo{}
	, E_Point{}
{
	
}
EneMy::~EneMy()
{
	
}