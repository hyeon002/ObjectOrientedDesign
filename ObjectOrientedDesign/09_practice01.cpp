#include <iostream> 

// MyData 클래스 
class MyData {
	int number;
	std::string strNumber;
public:
	// constructor
	MyData(int data, std::string str) : number(data), strNumber(str) {}

	// Operator conversion 
	operator int() { return number; }
	// MyData 객체가 int 로 변환될 때 number 값을 반환함 

	operator std::string() { return strNumber; }
	// MyData 객체가 string 으로 변환될 때 strNumber 값을 반환함 

	// Unary operator ( 증감 연산자 ) 
	int operator++(int) {	// 후위 증가 연산자 
		int temp = number;
		number++;
		return temp;
	}
	int operator++() {		// 전위 증가 연산자 
		return ++number;
	}

	friend std::ostream& operator<<(std::ostream&, MyData&);
};

// non-member operator<< function 
// << operator overloading 을 통해
// 객체를 std::cout 으로 출력할 때 형식을 지정할 수 있음 
std::ostream& operator<<(std::ostream& os, MyData& md) {
	return os << "This number is : " << md.strNumber << "\n";
	// 객체의 strNumber 값을 "This number is : " 과 함께 출력함
}

int main() {
	MyData mydata(1, "one");

	std::string strNum = mydata;		// conversion(MyData 클래스 타입 -> string)  
	int intNum = mydata;				// conversion(Mydata -> int) 

	std::cout << strNum << std::endl;	// one 
	std::cout << intNum << std::endl;	// 1 
	std::cout << mydata++ << std::endl; // 1, operator overloading(postfix) 
	std::cout << ++mydata << std::endl; // 3, operator overloading(prefix) 
	std::cout << mydata;				// operator overloading(<<) 
}