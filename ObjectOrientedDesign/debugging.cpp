#include <iostream>

class LetDebug
{
	public:
	void printNum()
	{
		//short s1 = 32767;
		//short s2 = 1;
		//short s3 = s1 + s2;
		// short : -32768 ~ 32767

		int s1 = 32767;
		int s2 = 1;
		int s3 = s1 + s2;

		std::cout << s3 << std::endl;
	}
};

int main()
{
	LetDebug* Id = new LetDebug;

	Id->printNum();

	return 0;
}