#include <iostream>
#include <string>
using namespace std;

class Circle {
	const double PI = 3.14;
	double radius;		// 반지름
	double cir, area;	// 둘레, 면적
	static int count;	// 정적 변수

public:

	// default constructor 
	Circle() : radius{ 0.0 }, cir{ 0.0 }, area{ 0.0 } {
		count++;
	}

	// 매개변수 r 을 받는 constructor 
	Circle(double r) {
		radius = r;
		cir = PI * 2 * r;
		area = r * r * PI;
		count++;
	}

	void printCircle() {
		cout << "원의 반지름 : " << radius << endl;
		cout << "원의 둘레 : " << cir << endl;
		cout << "원의 면적 : " << area << endl;
		cout << "지금까지 생성된 원의 개수 = " << Circle::count << endl << endl;
	}
};

// 정적 변수 초기화 
int Circle::count = 0;

int main() 
{
	Circle c1;			// radius 가 0.0 인 원 생성
	c1.printCircle();
		
	Circle c2(3);		// radius 가 3 인 원 생성 
	c2.printCircle();

	Circle c3(5.5);		// radius 가 5.5 인 원 생성 
	c3.printCircle();

	return 0;
}