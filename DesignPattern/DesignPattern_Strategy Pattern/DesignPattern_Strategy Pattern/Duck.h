#pragma once
#include "FlyBehavior.h"
//��� ������ �������� �θ�Ŭ����

class Duck
{
	//�������̽� �� ���� ������ ����
	FlyBehavior* flyBehavior;

	//������
	Duck(){}
	//���������Լ�
	virtual void display() = 0;

public:
	void performFly()
	{
		flyBehavior->Fly();
	}

};

