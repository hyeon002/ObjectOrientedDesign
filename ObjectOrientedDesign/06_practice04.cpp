#include <iostream>
#include <string>
using namespace std;

// Person class 정의 
class Person {
private :
	string name;		// 이름 변수
	int age;			// 나이 변수 
	string address;		// 주소 변수 

public :
	// default constructor ( 기본 생성자 )
	Person() : name("본인 이름"), age(10), address("daejeon") {}

	// getter 들 ( name, age, address )
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

// Student class 정의 ( Person class 상속받음 )
class Student : public Person {
private:
	string studentId;		// 학번 변수 

public:
	// default constructor ( 기본 생성자 ) 
	Student() : Person(), studentId("본인 학번") {}

	// 학번을 받는 method 
	void setStudentId(string studentid) {
		studentId = studentid;
	}

	// getter ( studentId )
	string getStudentId() {
		return studentId;
	}
};

int main() {
	Student s;		// Student 객체 s 생성

	// 정보 출력 
	// getter 를 통해 정보를 받아와서 정보 출력
	cout << "Student Information" << endl;
	cout << "Name : " << s.getName() << endl;
	cout << "Age : " << s.getAge() << endl;
	cout << "Address : " << s.getAddress() << endl;
	cout << "Student ID : " << s.getStudentId() << endl;

	return 0;
}