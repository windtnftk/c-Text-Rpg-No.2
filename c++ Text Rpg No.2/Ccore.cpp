#include "pch.h"
#include "Ccore.h"
#include "Item.h"
#include "Enemy.h"

void Ccore::Init()
{
	MainItem::GetInst()->ItemInit();
	EneMy::GetInst()->EnemyInit();
}

void Ccore::Progress()
{
	EneMy::GetInst()->printEnemyInfo(EneMy::GetInst()->IdReturn(EnemyId::Enemy1));
	MainItem::GetInst()->OpenItemBag();
}
Ccore::Ccore()
{

}
Ccore::~Ccore()
{

}