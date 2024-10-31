#include <iostream>

// Strategy interface
class Strategy {
public :
	virtual int doOperation(int num1, int num2) = 0;
};

// OperationAdd Ŭ���� 
class OperationAdd : public Strategy {
public:
	int doOperation(int num1, int num2) override {
		return num1 + num2;
	}
};

// OperationSubstract Ŭ����
class OperationSubstract : public Strategy {
public:
	int doOperation(int num1, int num2) override {
		return num1 - num2;
	}
};

// OperationMultiply Ŭ���� 
class OperationMultiply : public Strategy {
	int doOperation(int num1, int num2) override {
		return num1 * num2;
	}
};

// Context 
class Context {
private:
	Strategy* strategy;
public:
	Context(Strategy* strategy) : strategy(strategy) { }


	int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
};

int main() {

	Context* contextAdd = new Context(new OperationAdd());
	std::cout << "10 + 5 = " << contextAdd->executeStrategy(10, 5) << std::endl;

	Context* contextSub = new Context(new OperationSubstract());
	std::cout << "10 - 5 = " << contextSub->executeStrategy(10, 5) << std::endl;

	Context* contextMul = new Context(new OperationMultiply());
	std::cout << "10 * 5 = " << contextMul->executeStrategy(10, 5) << std::endl;

	return 0; 
}