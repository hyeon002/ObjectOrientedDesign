#include <iostream>

// Animal 클래스 
class Animal {
public :
	virtual void speak() {
		std::cout << "동물소리" << std::endl;
	}
};

// Cat 클래스 ( Animal 을 상속받음 ) 
class Cat : public Animal {
public:
	void speak() {
		std::cout << "야옹" << std::endl;
	}
};

// Dog 클래스 ( Animal 을 상속받음 ) 
class Dog : public Animal {
public:
	void speak() {
		std::cout << "멍멍" << std::endl;
	}
};

int main() {

	// 객체를 생성 후 speak 함수 호출 
	Animal animal; 
	Cat cat;
	Dog dog;
	animal.speak();
	cat.speak();
	dog.speak();

	std::cout << std::endl;

	// Animal 포인터 배열 생성 후, 각 객체들을 저장하고 
	// for 문을 통해 speak 함수를 호출함 
	Animal** animallist = new Animal * [3];
	animallist[0] = new Animal();
	animallist[1] = new Cat();
	animallist[2] = new Dog();

	for (int i = 0; i < 3; i++) {
		animallist[i]->speak();
	}

	return 0;
}