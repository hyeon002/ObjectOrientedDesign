#include <iostream>

// BaseClass Ŭ���� 
class BaseClass {
public :
	virtual ~BaseClass() {}		// �Ҹ��� ( destractor ) 
};

// DerivedClass Ŭ���� ( BaseClass �� ��ӹ��� ) 
class DerivedClass : public BaseClass {
public :
	void print() {
		std::cout << "Everything is OKAY" << std::endl;
	}
};

int main() {
	// BaseClass Ÿ���� ������ base �� �����ϰ� DerivedClass �Ҵ� 
	BaseClass* base = new DerivedClass;

	// DerivedClass* ���� �� dynamic_cast 
	// BaseClass ������ base �� DerivedClass �����ͷ� downcasting 
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);

	// ��ü ���� ������ Ȯ���ϴ� if �� 
	if (derived) {
		derived->print();
	}

	// �޸� ���� 
	delete base;

	return 0;
}