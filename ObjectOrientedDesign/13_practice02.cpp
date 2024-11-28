#include <iostream> 
#include <string> 
#include <algorithm> 

// ���� Ÿ�� ���ڵ��� �ּڰ��� ���ϴ� �Լ� ( min_value �Լ� )
template<typename T>
double min_value(T x) {
	return x; 
}

template<typename T, typename... Args>
double min_value(T x, Args... args) {
	auto value = min_value(args...);
	if (x < value) {		// x ���� ������ �ּڰ����� �۴ٸ� 
		return x;			// x �� return 
	}
	else {					// �׷��� ������
		return value;		// value ( ������ �ּڰ� )�� return ��
	}
}

int main() {
	auto x = min_value(42, 3.14, 11.1f, -2);

	std::cout << x;		// -2 
	
	getchar();
	return 0;
}

// min_value �Լ� 
// min_value(T x)
// -> ������ ������ ���� return �� 
// ��Ͱ� ����� 

// min_value(T x, Args... args)
// -> ���� ���ڵ� �߿��� ��������� �ּڰ��� ����� 
// if ���� ���� ���� x ���� ������ ���麸�� �۴ٸ� ���� x ���� return �ϵ��� �ϰ�
// �׷��� ������ ������ ���� �� �ּڰ��� ��ȯ�� 