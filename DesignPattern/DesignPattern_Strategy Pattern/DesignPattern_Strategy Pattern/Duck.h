#pragma once
#include "FlyBehavior.h"
//모든 종류의 오리들의 부모클래스

class Duck
{
	//인터페이스 를 담을 변수를 설정
	FlyBehavior* flyBehavior;

	//생성자
	Duck(){}
	//순수가상함수
	virtual void display() = 0;

public:
	void performFly()
	{
		flyBehavior->Fly();
	}

};

