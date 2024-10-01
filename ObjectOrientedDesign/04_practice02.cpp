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

int& foo()		// 함수의 반환 타입을 int& 로 변경

{
	i = 3;		// i 를 3으로 초기화
	A a;		// A 객체 생성
	B b;		// B 객체 생성 
	return i;	// i 의 reference 를 return 
}

int main()
{
	cout << foo() << endl;
	return 0;
}