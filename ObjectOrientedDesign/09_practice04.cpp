#include <iostream> 
#include <string> 

// Employee 클래스 
class Employee {
protected:
	std::string name;
	int age;
public:
	Employee(std::string name, int age) : name(name), age(age) {}
	void showInfo() {
		std::cout << "Name:" << name << ", Age: " << age <<
			std::endl;
	}
};

// Manager 클래스 ( Employee을 상속받음 ) 
class Manager : public Employee {
	int managerBonus;
public:
	Manager(int managerBonus, std::string name, int age) :
		managerBonus(managerBonus), Employee(name, age) {}
	void showInfo() {
		std::cout << "Manager Name:" << name << ", Age: " << age << ", managerBonus: " << managerBonus << std::endl;
	}
};

// Intern 클래스 ( Employee 를 상속받음 ) 
class Intern : public Employee {
	std::string majorName;
public:
	Intern(std::string major, std::string name, int age) : majorName(major),
		Employee(name, age) {}
	void showInfo() {
		std::cout << "Intern Name:" << name << ", Age: " << age << ", Major: " << majorName << std::endl; } 
	};

// Janitor 클래스 ( Employee 를 상속받음 ) 
class Janitor : public Employee {
	int salary;
public:
	Janitor(int salary, std::string name, int age) : salary(salary), Employee(name, age) {}
	void showInfo() {
		std::cout << "Janitor Name:" << name << ", Age: " << age << ", Salary: " << salary << std::endl;
	}
};


int main() {

	// Manager, Intern, Janitor 의 객체 배열 생성 
	Manager** managerlist = new Manager * [2];
	Intern** internlist = new Intern * [2];
	Janitor** janitorlist = new Janitor * [2];

	// 각 배열의 객체 정보 초기화 
	managerlist[0] = new Manager(200, "James", 33);
	managerlist[1] = new Manager(150, "Chulsoo", 50);
	internlist[0] = new Intern("security", "Minsu", 24);
	internlist[1] = new Intern("HCI", "Yong", 19);
	janitorlist[0] = new Janitor(100, "Black", 90);
	janitorlist[1] = new Janitor(200, "White", 100);

	// 각 객체 배열의 출력 
	managerlist[0]->showInfo();
	managerlist[1]->showInfo();
	internlist[0]->showInfo();
	internlist[1]->showInfo();
	janitorlist[0]->showInfo();
	janitorlist[1]->showInfo();

	getchar();
	return 0;
}