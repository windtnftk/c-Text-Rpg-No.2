#include "pch.h"
#include "Enemy.h"

void EneMy::EnemyInit()
{

	EneMy::GetInst()->E_BasicInfo.emplace
	(EnemyId::Enemy1, E_Info{ {L"Enemy1",10,5,10,10},0,true });
	EneMy::GetInst()->E_BasicInfo.emplace
	(EnemyId::Enemy2, E_Info{ {L"Enemy2",15,10,15,20},1,true });
	EneMy::GetInst()->E_BasicInfo.emplace
	(EnemyId::Enemy3, E_Info{ {L"Enemy3",20,15,20,30},2,true });
	EneMy::GetInst()->E_BasicInfo.emplace
	(EnemyId::Enemy4, E_Info{ {L"Enemy4",25,25,25,40},3,true });
	EneMy::GetInst()->E_BasicInfo.emplace
	(EnemyId::God,	  E_Info{ {L"God",30,30,30,50},4,true });
}
void EneMy::printEnemyInfo(const E_Info* enemy)
{

	std::wcout << L"Name: " << enemy->E_Info.C_Name << std::endl;
	std::wcout << L"Level: " << enemy->E_Info.C_Level << std::endl;
	std::wcout << L"Power: " << enemy->E_Info.C_Power << std::endl;
	std::wcout << L"Health: " << enemy->E_Info.C_Health << std::endl;
	std::wcout << L"Exp: " << enemy->E_Info.C_Exp << std::endl;
	std::wcout << L"Place: " << enemy->E_Plase << std::endl;
	std::wcout << L"Life: " << (enemy->E_Life ? L"Alive" : L"Dead") << std::endl;
}
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
EneMy::EneMy()
	:E_BasicInfo{}
{
	
}
EneMy::~EneMy()
{
	
}