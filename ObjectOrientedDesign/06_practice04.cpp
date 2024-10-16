#include <iostream>
#include <string>
using namespace std;

// Person class ���� 
class Person {
private :
	string name;		// �̸� ����
	int age;			// ���� ���� 
	string address;		// �ּ� ���� 

public :
	// default constructor ( �⺻ ������ )
	Person() : name("���� �̸�"), age(10), address("daejeon") {}

	// getter �� ( name, age, address )
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	string getAddress() {
		return address;
	}
};

// Student class ���� ( Person class ��ӹ��� )
class Student : public Person {
private:
	string studentId;		// �й� ���� 

public:
	// default constructor ( �⺻ ������ ) 
	Student() : Person(), studentId("���� �й�") {}

	// �й��� �޴� method 
	void setStudentId(string studentid) {
		studentId = studentid;
	}

	// getter ( studentId )
	string getStudentId() {
		return studentId;
	}
};

int main() {
	Student s;		// Student ��ü s ����

	// ���� ��� 
	// getter �� ���� ������ �޾ƿͼ� ���� ���
	cout << "Student Information" << endl;
	cout << "Name : " << s.getName() << endl;
	cout << "Age : " << s.getAge() << endl;
	cout << "Address : " << s.getAddress() << endl;
	cout << "Student ID : " << s.getStudentId() << endl;

	return 0;
}