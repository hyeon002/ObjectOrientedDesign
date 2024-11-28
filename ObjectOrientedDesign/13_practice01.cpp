#include <iostream> 

// 가변 개수의 인자를 받아 더하는 함수 
template <typename T>
T sum(T number) {
	return number;
}

template <typename T, typename... Args>
T sum(T first, Args... num) {
	return first + sum(num...);
}

// 가변 개수의 인자를 받아 평균을 구하는 함수 
template <typename... Args>
double average(Args... num) {
	auto result = sum(num...);				// 분자 : 가변 인자의 총합 
	size_t num_count = sizeof...(num);		// 분모 : 가변 인자의 개수 
	return result / num_count;
}

int main() {

	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	// average = 5 
	
	return 0;
}