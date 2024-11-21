#include <iostream> 
using namespace std;

template <typename T>
void fun(const T& x)
{	
	// static 변수 
	// 함수가 여러 번 호출되어도 값이 유지됨 
	static int count = 0;
	cout << "x = " << x << " count = " << count << endl;
	++count;
	return;
}

int main()
{
	// template 함수 fun<int> 가 처음 호출됨
	fun<int>(1);
	cout << endl;	// x = 1, count = 0 

	// 이전에 생성된 fun<int> 가 다시 호출됨 
	fun<int>(1);
	cout << endl;	// x = 1, count = 1

	// template 함수 fun<double> 이 처음 호출됨 
	fun<double>(1.1);
	cout << endl;	// x = 1.1, count = 0

	return 0;
}