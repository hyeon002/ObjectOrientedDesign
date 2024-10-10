#include <iostream>
#include <string>

class Animal {

private:
	std::string name;

public:
	Animal() {};
	Animal(std::string name) : name(name) {};

	void showName() {
		std::cout << "Name is " << name << std::endl;
	}
	
	// operator+ 
	Animal operator+(const Animal& animal) const {
		// Animal 객체의 이름을 합쳐서 새로운 객체 반환 
		// 기존 객체는 변하지 않음, 임시 객체 반환 
		return Animal(name + animal.name);
	}
};

int main() {

	// cat 객체 생성
	Animal cat("Nabi");
	cat.showName();

	// dog 객체 생성 
	Animal dog("Jindo");
	dog.showName();

	// dog 와 cat 을 결합한 catDog 객체 생성 
	Animal catDog = dog + cat;
	catDog.showName();

	// dog 기존 객체의 이름 출력
	// 기존 객체는 변경되지 않음 
	dog.showName();

	getchar();
	return 0;
}