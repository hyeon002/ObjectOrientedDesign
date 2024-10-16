#include <iostream>
#include <string>
using namespace std;

// Employee class ���� 
class Employee {
private:
	string emp_id;		// ���
	string name;		// �̸�
	int age;			// ����
	string address;		// �ּ�
	float salary;		// �޿� 

public:
	// constructor ( ������ ) 
	Employee(string emp_id, string name, int age, string address, float salary)
		: emp_id(emp_id), name(name), age(age), address(address), salary(salary) {}

	// getter �� ( emp_id, name, age, address, salary )
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

// Manager class ���� ( Employee class ��ӹ��� ) 
class Manager : public Employee {
private:
	int team_size;		// �������� �� 

public:
	// constructor ( ������ )
	Manager(string emp_id, string name, int age, string address, float salary, int team_size)
		: Employee(emp_id, name, age, address, salary), team_size(team_size) {}

	// getter ( team_size )
	int get_team_size() {
		return team_size;
	}
};

int main() {
	// Manager ��ü m ���� ( ���� �ʱ�ȭ�� ���� ���� ���� �ۼ� ) 
	Manager m("EMP001", "Manager �̸�", 35, "seoul", 5000.00, 10);

	// ���� ��� 
	cout << "Manager Information" << endl;
	cout << "Employee ID : " << m.get_emp_id() << endl;
	cout << "Name : " << m.get_name() << endl;
	cout << "Age : " << m.get_age() << endl;
	cout << "Address : " << m.get_address() << endl;
	cout << "Salary : $" << m.get_salary() << endl;
	cout << "Team Size : " << m.get_team_size() << endl;


	return 0;
}
