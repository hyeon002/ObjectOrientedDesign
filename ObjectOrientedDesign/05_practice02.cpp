#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class My_cat {
	char* name;
	int weight;

public:
	My_cat();
	My_cat(const char* name);
	My_cat(const My_cat& cat);	// copy constructor 
	~My_cat();					// destuctor

	// eat �Լ� ����
	My_cat& eat(int food);

	// drink �Լ� ����
	My_cat& drink(int drink);

	void show_status() const;
};

// default constructor 
My_cat::My_cat() :name(NULL), weight(10) { }

My_cat::My_cat(const char* cat_name) : weight(10) {
	name = new char[strlen(cat_name) + 1];
	strcpy(name, cat_name);
}

// Copy Constructor
My_cat::My_cat(const My_cat& cat) : weight(10) { 
	std::cout << "Copy Constructor invocation !" << std::endl;
	name = new char[strlen(cat.name) + 1];
	strcpy(name, cat.name);
}

// Destructor
My_cat::~My_cat() {
	if (name) delete[] name;
}

// eat function  
My_cat & My_cat::eat(int food) {
	weight += food;		// food ��ŭ weight ����
	return *this;		// return this ������
}

// drink function 
My_cat & My_cat::drink(int drink) {
	weight += drink;	// drink ��ŭ weight ���� 
	return *this;		// return this ������
}

void My_cat::show_status() const {
	std::cout << " Weight : " << weight << std::endl;
}
int main() {
	// cat1 ��ü ����
	My_cat cat1("Nabi");
	cat1.show_status();

	cat1.eat(4);		// food (4) ����
	cat1.show_status();

	cat1.drink(1);		// drink (1) ����
	std::cout << " and drinking water -> ";
	cat1.show_status();

	cat1.eat(4);		// food (4) ����
	cat1.show_status();

	cat1.drink(1);		// drink (1) ����
	std::cout << " and drinking water -> ";
	cat1.show_status();
	
	cat1.eat(4).eat(5).eat(6);	// �Լ� ü�̴� ( 4, 5, 6 food ���� )
	cat1.show_status();

	cat1.drink(1).drink(2);		// ( 1, 2 drink ���� )
	std::cout << " and drinking water -> ";
	cat1.show_status();

	getchar();
	return 0;
}