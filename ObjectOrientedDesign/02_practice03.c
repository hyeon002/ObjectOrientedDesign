#include <stdio.h> 

void show(const char* text)
{
	printf("String: %s\n", text);
}

void show(int number)
{
	printf("Number: %d\n", number);
}

// 오버로딩 (overloading) 
// C언어에서는 동일한 이름의 함수가 정의되는 것을 허용하지 않음 
int main()
{
	const char* text = "Hello, World!";
	int number = 10;
	show(text);
	show(number);
	return 0;
}
