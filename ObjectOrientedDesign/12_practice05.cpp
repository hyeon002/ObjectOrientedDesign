#include <iostream> 
using namespace std;

template <typename T>
void fun(const T& x)
{	
	// static ���� 
	// �Լ��� ���� �� ȣ��Ǿ ���� ������ 
	static int count = 0;
	cout << "x = " << x << " count = " << count << endl;
	++count;
	return;
}

int main()
{
	// template �Լ� fun<int> �� ó�� ȣ���
	fun<int>(1);
	cout << endl;	// x = 1, count = 0 

	// ������ ������ fun<int> �� �ٽ� ȣ��� 
	fun<int>(1);
	cout << endl;	// x = 1, count = 1

	// template �Լ� fun<double> �� ó�� ȣ��� 
	fun<double>(1.1);
	cout << endl;	// x = 1.1, count = 0

	return 0;
}