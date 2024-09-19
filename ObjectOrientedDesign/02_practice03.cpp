#include <stdio.h> 

void show(const char* text)
{
	printf("String: %s\n", text);
}

void show(int number)
{
	printf("Number: %d\n", number);
}

int main()
{
	const char* text = "Hello, World!";
	int number = 10;
	show(text);
	show(number);
	return 0;
}

// .c 확장자 컴파일 -> 실패 
// C언어에서는 오버로딩 ( overloading ) 이 지원되지 않음 

// .cpp 확장자 컴파일 -> 성공
// C++ 에서는 오버로딩 ( overloading ) 이 지원됨 