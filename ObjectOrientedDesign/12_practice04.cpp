#include <iostream> 

// ���� Ÿ���� �μ��� ó���ϴ� template �Լ�
template<typename T>
T min(T x, T y) {
	return x < y ? x : y;
}

// �ٸ� Ÿ���� �μ��� ó���ϴ� template �Լ� ( overloading )
template <typename T1, typename T2>
auto min(T1 x, T2 y) {
	return x < y ? x : y;
}

int main() {
	int x = 3;
	int y = 2;
	double d = 2.1;
	double e = 3.3;
	std::cout << "min(x,y): " << min(x, y) 
			  << ", min(d,e): " << min(d, e) 
			  << ", min(d, x) : " << min<double, int>(d, x) 
			  << std::endl; 
		return 0;
}

// int ���� double ������ �ٸ� Ÿ���̶� ������ �߻��� 
// �ٸ� Ÿ���� �μ��� ó���ϴ� template �� ������ 