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
		// Animal ��ü�� �̸��� ���ļ� ���ο� ��ü ��ȯ 
		// ���� ��ü�� ������ ����, �ӽ� ��ü ��ȯ 
		return Animal(name + animal.name);
	}
};

int main() {

	// cat ��ü ����
	Animal cat("Nabi");
	cat.showName();

	// dog ��ü ���� 
	Animal dog("Jindo");
	dog.showName();

	// dog �� cat �� ������ catDog ��ü ���� 
	Animal catDog = dog + cat;
	catDog.showName();

	// dog ���� ��ü�� �̸� ���
	// ���� ��ü�� ������� ���� 
	dog.showName();

	getchar();
	return 0;
}