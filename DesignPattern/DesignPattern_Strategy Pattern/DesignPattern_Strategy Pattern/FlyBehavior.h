#include <iostream>
#define interface class
using namespace std;

//�������̽� 

interface FlyBehavior
{
 public:

	 virtual void Fly() = 0; //���������Լ�
};

class FlywithWings : public FlyBehavior
{
public:
	void Fly() override
	{
		cout << "�����־��" << endl;
	}
};

class FlyNoWay : public FlyBehavior
{

public:
	void Fly() override
	{
		cout << "�������ؿ�" << endl;
	}
};