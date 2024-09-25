#include <iostream>

void increment(int& x)
{
	++x;
}

int main()
{
	int x = 55;
	int& rx = x;
	std::cout << " Before increment : " << x << std::endl;
	increment(rx);
	std::cout << " After increment : " << x << std::endl;

	system("pause");
	return 0;
}