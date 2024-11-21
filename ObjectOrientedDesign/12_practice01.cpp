#include <iostream> 

// template swap 함수 정의 
template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;

	// template 함수 호출 
	swap(a, b);
	swap(c, d);


	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	return 0;
}