#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class Animal {
public:
	char* name;
	int age;

	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy(name, name_);
	}
	Animal(const Animal& a) {	// ���� ������ 
		age = a.age;
		name = a.name;
	}

	void changeName(const char* newName) {
		strcpy(name, newName);
	}
	void printAnimal() {
		std::cout << "Name : " << name << "  Age : " << age << std::endl;
	}
};

int main() {
	Animal A(10, "Jenny");		// 10 �� Jenny ����
	Animal B = A;				// 10 �� Jenny �� A �� B ���� ����
	A.age = 22;					// A �� ���̸� 22 ��� ���� 
	A.changeName("Brown");		// A �� �̸��� Brown ���� ����

	A.printAnimal();
	B.printAnimal();

	return 0;
}