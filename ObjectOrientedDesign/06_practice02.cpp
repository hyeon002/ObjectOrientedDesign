#include <iostream>
#include <exception>
using namespace std;

// Custom Exception 
// std::exception 을 상속받아 정의한 클래스 
class MyCustomException : public std::exception
{
public :
	// what 함수 overriding
	const char* what() const noexcept override {
		return "NewException";	// 예외 메세지
	}
};

int main() {

	try {
		// 예외 발생 ( 의도적으로 예외를 발생시킴 )
		throw MyCustomException();
	}
	catch (exception& e) {			// 객체를 잡아 예외 처리 
		cout << "My exception is ";
		cout << e.what() << endl;	// 예외 메세지 출력 
	}
	return 0;
}