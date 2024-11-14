#include <iostream>
#include <vector>		// vector 를 사용하기 위함 ( STL container )
#include <algorithm>	// min, max_element 함수를 사용하기 위함 ( STL algorithm )

int main() {
	std::vector<int> number;
	int num, min, max;

	// 10 개의 정수 입력 
	std::cout << "10 개의 정수 입력 : ";
	for (int i = 0; i < 10; i++) {
		std::cin >> num;
		number.push_back(num);
	}

	// 최솟값 찾기 
	min = *std::min_element(number.begin(), number.end());

	// 최댓값 찾기 
	max = *std::max_element(number.begin(), number.end());

	std::cout << "최솟값 : " << min << std::endl;
	std::cout << "최댓값 : " << max << std::endl;

	return 0;
}