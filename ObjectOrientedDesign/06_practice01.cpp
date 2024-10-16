#include <iostream>
using namespace std;

class A {
	int value;

public:

	A() : value(5) {};		// 초기값 : 5

	// postfix unary operator ( 후위 연산 ++ )
	A operator++(int) {
		A temp = *this;		// temp ( 임시 객체 ) 에 기존 값을 저장 
		value++;			// 값 증가 
		return temp;		// temp ( 임시 객체 ) return 
	}

	// prefix unary operator ( ++ 전위 연산 ) 
	A& operator++() {
		value++;			// 값 증가 
		return *this;		// 값 증가시킨 객체 return 
	}

	// value 출력 
	void valuePrint() {
		cout << value << endl;		// 값 출력 
	}
};

int main() {

	class A a;
	a.valuePrint();		// 초기값 : 5

	a++;				// postfix unary
	a.valuePrint();		// a++ 결과 : 6

	++a;				// prefix unary 
	a.valuePrint();		// ++a 결과 : 7

	return 0;
}