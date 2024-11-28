#include <iostream> 

// ���� ������ ���ڸ� �޾� ���ϴ� �Լ� 
template <typename T>
T sum(T number) {
	return number;
}

template <typename T, typename... Args>
T sum(T first, Args... num) {
	return first + sum(num...);
}

// ���� ������ ���ڸ� �޾� ����� ���ϴ� �Լ� 
template <typename... Args>
double average(Args... num) {
	auto result = sum(num...);				// ���� : ���� ������ ���� 
	size_t num_count = sizeof...(num);		// �и� : ���� ������ ���� 
	return result / num_count;
}

int main() {

	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	// average = 5 
	
	return 0;
}