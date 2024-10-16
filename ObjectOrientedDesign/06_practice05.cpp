#include <iostream>
#include <string>
using namespace std;

// Employee class 정의 
class Employee {
private:
	string emp_id;		// 사번
	string name;		// 이름
	int age;			// 나이
	string address;		// 주소
	float salary;		// 급여 

public:
	// constructor ( 생성자 ) 
	Employee(string emp_id, string name, int age, string address, float salary)
		: emp_id(emp_id), name(name), age(age), address(address), salary(salary) {}

	// getter 들 ( emp_id, name, age, address, salary )
	string get_emp_id() {
		return emp_id;
	}
	string get_name() {
		return name;
	}
	int get_age() {
		return age;
	}
	string get_address() {
		return address;
	}
	float get_salary() {
		return salary;
	}
};

// Manager class 정의 ( Employee class 상속받음 ) 
class Manager : public Employee {
private:
	int team_size;		// 팀원들의 수 

public:
	// constructor ( 생성자 )
	Manager(string emp_id, string name, int age, string address, float salary, int team_size)
		: Employee(emp_id, name, age, address, salary), team_size(team_size) {}

	// getter ( team_size )
	int get_team_size() {
		return team_size;
	}
};

int main() {
	// Manager 객체 m 생성 ( 변수 초기화를 위해 변수 값들 작성 ) 
	Manager m("EMP001", "Manager 이름", 35, "seoul", 5000.00, 10);

	// 정보 출력 
	cout << "Manager Information" << endl;
	cout << "Employee ID : " << m.get_emp_id() << endl;
	cout << "Name : " << m.get_name() << endl;
	cout << "Age : " << m.get_age() << endl;
	cout << "Address : " << m.get_address() << endl;
	cout << "Salary : $" << m.get_salary() << endl;
	cout << "Team Size : " << m.get_team_size() << endl;


	return 0;
}
