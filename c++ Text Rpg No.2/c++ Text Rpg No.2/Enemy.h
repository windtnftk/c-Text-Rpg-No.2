#include"pch.h"
// 일단 다 따로 만들고 상속으로 합쳐보자
	// 캐릭터 정보를 저장할 class
	// 몬스터 정보를 저장할 class
	// 아이템 정보를 저장할 class
	// 그걸 관리해주는 iterator 만들고 진행
	// 그걸 모두 상속해서 사용 하자


struct BasicStatus
{
	wstring		CName;// 캐릭터 이름
	short		CLevel;// 캐릭터 래벨
	int			CPower;// 캐릭터 힘
	int			CHealth;// 캐릭터 생명력
	int			CExp;//처치시 경험치
};
struct Enemy
{
	BasicStatus		EnemyInfo;//몬스터 기본정보
	int				EnemyPlase;//몬스터 생존위치
	bool			EnemyLife;//몬스터 생존여부
};





class Character
{
public:
	vector<Enemy> CharacterInfo;//적의 모든정보

	
};

