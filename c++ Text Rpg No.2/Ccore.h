#pragma once





// Main 설정 진행 장소 
class Ccore
{
	SINGLE(Ccore);

public:
	// Main 프로그램이 시작하기전 초기값 설정
	void	Init();
	// Main 프로그램이 돌아가는 함수, 일단 여기서 모든 동작 진행하도록 하자
	void	Progress();
	// 
};

