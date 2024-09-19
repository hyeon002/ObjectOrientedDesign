#include <iostream>

class SetValue
{
private:
	int x, y;

public :
	void setXY(int X, int Y)
	{
		x = X;
		y = Y;
	}

	void show()
	{
		std::cout << "X = " << x << ", Y = " << y << std::endl;
	}
};

int main()
{
	SetValue obj;

	obj.setXY(33, 44);
	obj.show();

	system("pause");
	return 0;
}