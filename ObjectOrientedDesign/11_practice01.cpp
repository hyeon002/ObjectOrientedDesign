#include <iostream>
#include <vector>		// vector �� ����ϱ� ���� ( STL container )
#include <algorithm>	// min, max_element �Լ��� ����ϱ� ���� ( STL algorithm )

int main() {
	std::vector<int> number;
	int num, min, max;

	// 10 ���� ���� �Է� 
	std::cout << "10 ���� ���� �Է� : ";
	for (int i = 0; i < 10; i++) {
		std::cin >> num;
		number.push_back(num);
	}

	// �ּڰ� ã�� 
	min = *std::min_element(number.begin(), number.end());

	// �ִ� ã�� 
	max = *std::max_element(number.begin(), number.end());

	std::cout << "�ּڰ� : " << min << std::endl;
	std::cout << "�ִ� : " << max << std::endl;

	return 0;
}