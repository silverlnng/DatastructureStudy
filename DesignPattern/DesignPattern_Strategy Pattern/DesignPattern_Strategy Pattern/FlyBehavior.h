#include <iostream>
#define interface class
using namespace std;

//인터페이스 

interface FlyBehavior
{
 public:

	 virtual void Fly() = 0; //순수가상함수
};

class FlywithWings : public FlyBehavior
{
public:
	void Fly() override
	{
		cout << "날고있어요" << endl;
	}
};

class FlyNoWay : public FlyBehavior
{

public:
	void Fly() override
	{
		cout << "날지못해요" << endl;
	}
};