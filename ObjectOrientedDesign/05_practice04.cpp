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

	// Animal °´Ã¼ÀÇ reference ¸¦ ¹ÝÈ¯ 
	// const ¸â¹ö ÇÔ¼ö ¼±¾ð X
	Animal& operator+(const Animal& animal) {
		// ÇöÀç °´Ã¼ÀÇ name ¿¡ animal °´Ã¼ÀÇ name À» ´õÇÔ 
		name += animal.name;
		return *this;
	}
};

int main() {

	// cat °´Ã¼ »ý¼º
	Animal cat("Nabi");
	cat.showName();

	// dog °´Ã¼ »ý¼º 
	Animal dog("Jindo");
	dog.showName();

	// dog ¿Í cat °´Ã¼¸¦ °áÇÕÇÑ catDog °´Ã¼ »ý¼º
	Animal catDog = dog + cat;
	catDog.showName();

	// dog °´Ã¼ÀÇ ÀÌ¸§ Ãâ·Â 
	// ±âÁ¸ °´Ã¼°¡ º¯°æµÊ
	dog.showName();

	getchar();
	return 0;
}