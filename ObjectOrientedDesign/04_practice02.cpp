#include <iostream>
using namespace std;

int i;

class A
{
public:
	~A()	// destructor
	{
		i = 10;
	}
};

class B
{
public:
	~B()	// destructor 
	{
		i = 20;
	}
};

int& foo()		// �Լ��� ��ȯ Ÿ���� int& �� ����

{
	i = 3;		// i �� 3���� �ʱ�ȭ
	A a;		// A ��ü ����
	B b;		// B ��ü ���� 
	return i;	// i �� reference �� return 
}

int main()
{
	cout << foo() << endl;
	return 0;
}