// Decorator Pattern 
#include <iostream>
#include <string>

// Component ( interface )  
// Computer 라는 interface 를 정의 
class Computer {
public:
	// 가격
	virtual int getPrice() = 0;

	// 옵션 출력 
	virtual std::string getOptionPrint() = 0;

	virtual ~Computer() {}
};

// Concrete Component 
// 원본 클래스인 BasicComputer 를 정의 
// Computer interface 를 상속받음 
class BasicComputer : public Computer {
public:
	int getPrice() override {
		return 500000;
	}
	std::string getOptionPrint() override {
		return "Computer";
	}
};

// Decorator ( 추상 클래스 )
class ComputerDecorator : public Computer {
protected:
	Computer* computer;
public :
	// constructor 
	ComputerDecorator(Computer* computer) : computer(computer) {}
	
	virtual ~ComputerDecorator() { delete computer; }
};

// Concrete Decorator 
// RAMComputer 클래스를 정의 ( ComputerDecorator 를 상속받음 )
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

// SSDComputer 클래스를 정의 ( COmputerDecorator 를 상속받음 )
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

// GPUComputer 클래스를 정의 ( ComputerDecorator 를 상속받음 )
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