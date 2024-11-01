#include <iostream>

// Animal Ŭ���� 
class Animal {
public :
	virtual void speak() {
		std::cout << "�����Ҹ�" << std::endl;
	}
};

// Cat Ŭ���� ( Animal �� ��ӹ��� ) 
class Cat : public Animal {
public:
	void speak() {
		std::cout << "�߿�" << std::endl;
	}
};

// Dog Ŭ���� ( Animal �� ��ӹ��� ) 
class Dog : public Animal {
public:
	void speak() {
		std::cout << "�۸�" << std::endl;
	}
};

int main() {

	// ��ü�� ���� �� speak �Լ� ȣ�� 
	Animal animal; 
	Cat cat;
	Dog dog;
	animal.speak();
	cat.speak();
	dog.speak();

	std::cout << std::endl;

	// Animal ������ �迭 ���� ��, �� ��ü���� �����ϰ� 
	// for ���� ���� speak �Լ��� ȣ���� 
	Animal** animallist = new Animal * [3];
	animallist[0] = new Animal();
	animallist[1] = new Cat();
	animallist[2] = new Dog();

	for (int i = 0; i < 3; i++) {
		animallist[i]->speak();
	}

	return 0;
}