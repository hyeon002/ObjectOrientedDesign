#include <iostream>

// BaseClass 클래스 
class BaseClass {
public :
	virtual ~BaseClass() {}		// 소멸자 ( destractor ) 
};

// DerivedClass 클래스 ( BaseClass 를 상속받음 ) 
class DerivedClass : public BaseClass {
public :
	void print() {
		std::cout << "Everything is OKAY" << std::endl;
	}
};

int main() {
	// BaseClass 타입의 포인터 base 를 선언하고 DerivedClass 할당 
	BaseClass* base = new DerivedClass;

	// DerivedClass* 선언 및 dynamic_cast 
	// BaseClass 포인터 base 를 DerivedClass 포인터로 downcasting 
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);

	// 객체 생성 유무를 확인하는 if 문 
	if (derived) {
		derived->print();
	}

	// 메모리 해제 
	delete base;

	return 0;
}