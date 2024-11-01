#include <iostream> 
#include <string> 

// Employee 클래스 
class Employee {
protected:
	std::string name;
	int age;
public:
	// constructor 
	Employee(std::string name, int age) : name(name), age(age) {}

	// Employee 클래스의 showInfo 함수를 virtual 로 선언함 
	// 각 하위 클래스의 showInfo() 가 호출되도록 함
	virtual void showInfo() {
		std::cout << "Name:" << name << ", Age: " << age <<
			std::endl;
	}
};

// Manager 클래스 ( Employee 를 상속받음 ) 
class Manager : public Employee {
	int managerBonus;
public:
	// construtor 
	Manager(int managerBonus, std::string name, int age) : managerBonus(managerBonus), Employee(name, age) {}
	
	void showInfo() {
		std::cout << "Manager Name:" << name << ", Age: " << age <<
			", managerBonus:" << managerBonus << std::endl;
	}
};

// Intern 클래스 ( Employee 를 상속받음 ) 
class Intern : public Employee {
	std::string majorName;
public:
	// construtor 
	Intern(std::string major, std::string name, int age) : majorName(major), Employee(name, age) {}
	
	void showInfo() {
		std::cout << "Intern Name:" << name << ", Age: " << age << ", Major:" << majorName << std::endl; } 
	};
	
// Janitor 클래스 ( Employee 를 상속받음 ) 
class Janitor : public Employee {
		int salary;
public:
	// construtor 
	Janitor(int salary, std::string name, int age) : salary(salary), Employee(name, age) {}
		
	void showInfo() {
		std::cout << "Janitor Name:" << name << ", Age: " << age << ", Salary:" << salary << std::endl;
		}
	};

int main() {

	Employee** employeelist = new Employee * [6];

	employeelist[0] = new Manager(200, "James", 33);
	employeelist[1] = new Manager(150, "Chulsoo", 50);
	employeelist[2] = new Intern("security", "Minsu", 24);
	employeelist[3] = new Intern("HCI", "Yong", 19);
	employeelist[4] = new Janitor(100, "Black", 90);
	employeelist[5] = new Janitor(200, "White", 100);

	employeelist[0]->showInfo();
	employeelist[1]->showInfo();
	employeelist[2]->showInfo();
	employeelist[3]->showInfo();
	employeelist[4]->showInfo();
	employeelist[5]->showInfo();


	getchar();
	return 0;
}