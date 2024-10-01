#include <iostream>
using namespace std;

int i;

class A
{
public:
	~A()
	{
		i = 10;
	}
};

class B
{
public:
	~B()
	{
		i = 20;
	}
};

int& foo()		// �Լ��� ��ȯ���� int& �� ��ȯ
{
	i = 3;
	{
		A a;	// nested block ���ο��� A ��ü ���� 
	}			// nested block �� �����鼭 A ��ü �Ҹ�
	B b;		// B ��ü ���� 
	return i;
}

int main()
{
	cout << foo() << endl;	// reference ���� ��� 
	return 0;
}