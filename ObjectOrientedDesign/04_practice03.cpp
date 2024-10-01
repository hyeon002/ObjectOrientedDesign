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

int& foo()		// 함수의 반환형을 int& 로 변환
{
	i = 3;
	{
		A a;	// nested block 내부에서 A 객체 생성 
	}			// nested block 이 끝나면서 A 객체 소멸
	B b;		// B 객체 생성 
	return i;
}

int main()
{
	cout << foo() << endl;	// reference 값을 출력 
	return 0;
}