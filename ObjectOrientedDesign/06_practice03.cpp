#include <iostream>
using namespace std;

class A {
public :	
	// Constructor ( ������ )
	A() {	
		// constructor ȣ�� �� ��� 
		cout << "Constructor()" << endl;
	}

	// Destructor ( �Ҹ��� )
	~A() {
		// destructor ȣ�� �� ��� 
		cout << "Destructor()" << endl;
	}
};

int main() {
	try {
		A object;	// A class �� ��ü ���� ( constructor ȣ��� ) 
		throw 10;	// ���� �߻� ( 10 �� ���� ) 
	}
	catch (int e) {
		cout << "Catch " << e << endl;	// ���ܸ� �޾Ƽ� ����� 
	}

	return 0;
}