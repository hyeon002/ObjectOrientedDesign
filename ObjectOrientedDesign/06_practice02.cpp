#include <iostream>
#include <exception>
using namespace std;

// Custom Exception 
// std::exception �� ��ӹ޾� ������ Ŭ���� 
class MyCustomException : public std::exception
{
public :
	// what �Լ� overriding
	const char* what() const noexcept override {
		return "NewException";	// ���� �޼���
	}
};

int main() {

	try {
		// ���� �߻� ( �ǵ������� ���ܸ� �߻���Ŵ )
		throw MyCustomException();
	}
	catch (exception& e) {			// ��ü�� ��� ���� ó�� 
		cout << "My exception is ";
		cout << e.what() << endl;	// ���� �޼��� ��� 
	}
	return 0;
}