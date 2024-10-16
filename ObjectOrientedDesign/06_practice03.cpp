#include <iostream>
using namespace std;

class A {
public :	
	// Constructor ( 생성자 )
	A() {	
		// constructor 호출 시 출력 
		cout << "Constructor()" << endl;
	}

	// Destructor ( 소멸자 )
	~A() {
		// destructor 호출 시 출력 
		cout << "Destructor()" << endl;
	}
};

int main() {
	try {
		A object;	// A class 의 객체 생성 ( constructor 호출됨 ) 
		throw 10;	// 예외 발생 ( 10 을 던짐 ) 
	}
	catch (int e) {
		cout << "Catch " << e << endl;	// 예외를 받아서 출력함 
	}

	return 0;
}