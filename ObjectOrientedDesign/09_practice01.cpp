#include <iostream> 

// MyData Ŭ���� 
class MyData {
	int number;
	std::string strNumber;
public:
	// constructor
	MyData(int data, std::string str) : number(data), strNumber(str) {}

	// Operator conversion 
	operator int() { return number; }
	// MyData ��ü�� int �� ��ȯ�� �� number ���� ��ȯ�� 

	operator std::string() { return strNumber; }
	// MyData ��ü�� string ���� ��ȯ�� �� strNumber ���� ��ȯ�� 

	// Unary operator ( ���� ������ ) 
	int operator++(int) {	// ���� ���� ������ 
		int temp = number;
		number++;
		return temp;
	}
	int operator++() {		// ���� ���� ������ 
		return ++number;
	}

	friend std::ostream& operator<<(std::ostream&, MyData&);
};

// non-member operator<< function 
// << operator overloading �� ����
// ��ü�� std::cout ���� ����� �� ������ ������ �� ���� 
std::ostream& operator<<(std::ostream& os, MyData& md) {
	return os << "This number is : " << md.strNumber << "\n";
	// ��ü�� strNumber ���� "This number is : " �� �Բ� �����
}

int main() {
	MyData mydata(1, "one");

	std::string strNum = mydata;		// conversion(MyData Ŭ���� Ÿ�� -> string)  
	int intNum = mydata;				// conversion(Mydata -> int) 

	std::cout << strNum << std::endl;	// one 
	std::cout << intNum << std::endl;	// 1 
	std::cout << mydata++ << std::endl; // 1, operator overloading(postfix) 
	std::cout << ++mydata << std::endl; // 3, operator overloading(prefix) 
	std::cout << mydata;				// operator overloading(<<) 
}