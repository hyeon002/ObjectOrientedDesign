#include <iostream>
#include <string>
using namespace std;

class Circle {
	const double PI = 3.14;
	double radius;		// ������
	double cir, area;	// �ѷ�, ����
	static int count;	// ���� ����

public:

	// default constructor 
	Circle() : radius{ 0.0 }, cir{ 0.0 }, area{ 0.0 } {
		count++;
	}

	// �Ű����� r �� �޴� constructor 
	Circle(double r) {
		radius = r;
		cir = PI * 2 * r;
		area = r * r * PI;
		count++;
	}

	void printCircle() {
		cout << "���� ������ : " << radius << endl;
		cout << "���� �ѷ� : " << cir << endl;
		cout << "���� ���� : " << area << endl;
		cout << "���ݱ��� ������ ���� ���� = " << Circle::count << endl << endl;
	}
};

// ���� ���� �ʱ�ȭ 
int Circle::count = 0;

int main() 
{
	Circle c1;			// radius �� 0.0 �� �� ����
	c1.printCircle();
		
	Circle c2(3);		// radius �� 3 �� �� ���� 
	c2.printCircle();

	Circle c3(5.5);		// radius �� 5.5 �� �� ���� 
	c3.printCircle();

	return 0;
}