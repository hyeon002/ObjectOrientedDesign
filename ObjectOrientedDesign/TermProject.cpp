// Decorator Pattern 
#include <iostream>
#include <string>

// Component ( interface )  
// Computer ��� interface �� ���� 
class Computer {
public:
	// ����
	virtual int getPrice() = 0;

	// �ɼ� ��� 
	virtual std::string getOptionPrint() = 0;

	virtual ~Computer() {}
};

// Concrete Component 
// ���� Ŭ������ BasicComputer �� ���� 
// Computer interface �� ��ӹ��� 
class BasicComputer : public Computer {
public:
	int getPrice() override {
		return 500000;
	}
	std::string getOptionPrint() override {
		return "Computer";
	}
};

// Decorator ( �߻� Ŭ���� )
class ComputerDecorator : public Computer {
protected:
	Computer* computer;
public :
	// constructor 
	ComputerDecorator(Computer* computer) : computer(computer) {}
	
	virtual ~ComputerDecorator() { delete computer; }
};

// Concrete Decorator 
// RAMComputer Ŭ������ ���� ( ComputerDecorator �� ��ӹ��� )
class RAMComputer : public ComputerDecorator {
public:
	RAMComputer(Computer* computer) : ComputerDecorator(computer) {}
	int getPrice() override {
		return computer->getPrice() + 50000;
	}
	std::string getOptionPrint() override {
		return "RAM" + computer->getOptionPrint();
	}
};

// SSDComputer Ŭ������ ���� ( COmputerDecorator �� ��ӹ��� )
class SSDComputer : public ComputerDecorator {
public:
	SSDComputer(Computer* computer) : ComputerDecorator(computer) {}
	int getPrice() override {
		return computer->getPrice() + 80000;
	}
	std::string getOptionPrint() override {
		return "SSD" + computer->getOptionPrint();
	}
};

// GPUComputer Ŭ������ ���� ( ComputerDecorator �� ��ӹ��� )
class GPUComputer : public ComputerDecorator {
public:
	GPUComputer(Computer* computer) : ComputerDecorator(computer) {}
	int getPrice() override {
		return computer->getPrice() + 200000;
	}
	std::string getOptionPrint() override {
		return "GPU" + computer->getOptionPrint();
	}
};

int main() {
	Computer* userComputer = new BasicComputer();
	char select;

	std::cout << "Add RAM? (y/n) ";
	std::cin >> select;
	if (select == 'y') {
		userComputer = new RAMComputer(userComputer);
	}

	std::cout << "Add SSD? (y/n) ";
	std::cin >> select;
	if (select == 'y') {
		userComputer = new SSDComputer(userComputer);
	}

	std::cout << "Add GPU? (y/n) ";
	std::cin >> select;
	if (select == 'y') {
		userComputer = new GPUComputer(userComputer);
	}

	std::cout << userComputer->getOptionPrint() << ", " << userComputer->getPrice() << std::endl;

	delete userComputer;
	return 0;
}