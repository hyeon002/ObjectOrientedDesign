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
	Animal(const Animal& a) {	// 복사 생성자 
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
	Animal A(10, "Jenny");		// 10 살 Jenny 생성
	Animal B = A;				// 10 살 Jenny 인 A 를 B 에게 복사
	A.age = 22;					// A 의 나이를 22 살로 변경 
	A.changeName("Brown");		// A 의 이름을 Brown 으로 변경

	A.printAnimal();
	B.printAnimal();

	return 0;
}