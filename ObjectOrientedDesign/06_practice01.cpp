#include <iostream>
using namespace std;

class A {
	int value;

public:

	A() : value(5) {};		// �ʱⰪ : 5

	// postfix unary operator ( ���� ���� ++ )
	A operator++(int) {
		A temp = *this;		// temp ( �ӽ� ��ü ) �� ���� ���� ���� 
		value++;			// �� ���� 
		return temp;		// temp ( �ӽ� ��ü ) return 
	}

	// prefix unary operator ( ++ ���� ���� ) 
	A& operator++() {
		value++;			// �� ���� 
		return *this;		// �� ������Ų ��ü return 
	}

	// value ��� 
	void valuePrint() {
		cout << value << endl;		// �� ��� 
	}
};

int main() {

	class A a;
	a.valuePrint();		// �ʱⰪ : 5

	a++;				// postfix unary
	a.valuePrint();		// a++ ��� : 6

	++a;				// prefix unary 
	a.valuePrint();		// ++a ��� : 7

	return 0;
}