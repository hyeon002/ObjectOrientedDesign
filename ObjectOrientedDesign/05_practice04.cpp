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

	// Animal ��ü�� reference �� ��ȯ 
	// const ��� �Լ� ���� X
	Animal& operator+(const Animal& animal) {
		// ���� ��ü�� name �� animal ��ü�� name �� ���� 
		name += animal.name;
		return *this;
	}
};

int main() {

	// cat ��ü ����
	Animal cat("Nabi");
	cat.showName();

	// dog ��ü ���� 
	Animal dog("Jindo");
	dog.showName();

	// dog �� cat ��ü�� ������ catDog ��ü ����
	Animal catDog = dog + cat;
	catDog.showName();

	// dog ��ü�� �̸� ��� 
	// ���� ��ü�� �����
	dog.showName();

	getchar();
	return 0;
}