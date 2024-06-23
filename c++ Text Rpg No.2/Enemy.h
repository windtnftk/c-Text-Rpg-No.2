#include"pch.h"
// 일단 다 따로 만들고 상속으로 합쳐보자
	// 캐릭터 정보를 저장할 class
	// 몬스터 정보를 저장할 class
	// 아이템 정보를 저장할 class
	// 그걸 관리해주는 iterator 만들고 진행
	// 그걸 모두 상속해서 사용 하자
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
	wstring		C_Name;// 캐릭터 이름
	short		C_Level;// 캐릭터 래벨
	int			C_Power;// 캐릭터 힘
	int			C_Health;// 캐릭터 생명력
	int			C_Exp;//처치시 경험치
};
struct E_Info
{
	B_Status		E_Info;//몬스터 기본정보
	int				E_Plase;//몬스터 생존위치
	bool			E_Life;//몬스터 생존여부
};



class EneMy
{
	SINGLE(EneMy);
public:
	map<EnemyId, E_Info> E_BasicInfo;//적의 모든정보
	map<EnemyId, E_Info>::iterator	E_Point;
	// 정보 초기화
	void EnemyInit();
	// 위치 정보값 보내면 출력해주는 함수
	void printEnemyInfo(const E_Info* enemy);
	// id 값 쓰면 정보 주소값 변환하는 함수
	E_Info* IdReturn(EnemyId Id);
	
	
};

