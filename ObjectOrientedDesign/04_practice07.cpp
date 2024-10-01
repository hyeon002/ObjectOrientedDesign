#include <iostream>

class Test {
public:
	int num1;
	int num2;

	Test(int num1_, int num2_) {	// constructor Ãß°¡ 
		num1 = num1_;
		num2 = num2_;
	}

	void print() {
		std::cout << "num1 : " << num1 << std::endl;
		std::cout << "num2 : " << num2 << std::endl;
	}
};

int main() {
	Test a = Test(1, 3);
	a.print();
}