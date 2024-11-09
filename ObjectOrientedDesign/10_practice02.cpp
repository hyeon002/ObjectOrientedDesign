#include <iostream>

// DrawAPI 클래스 
class DrawAPI {
public :
	virtual void drawCircle(int radius, int x, int y) = 0;	// 가상 함수 
	virtual ~DrawAPI() {}									// 가상 소멸자
};

// RedCircle 클래스 ( DrawAPI 를 상속받음 )
class RedCircle : public DrawAPI {
public :
	void drawCircle(int radius, int x, int y) override {
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

// GreenCircle 클래스 ( DrawAPI 를 상속받음 )
class GreenCircle : public DrawAPI {
public:
	void drawCircle(int radius, int x, int y) override {
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

// Shape 클래스 
class Shape {
protected:
	DrawAPI* drawAPI;

	Shape(DrawAPI* drawAPI) : drawAPI(drawAPI) {} // 생성자
public:
	virtual void draw() = 0;                      // 순수 가상 함수
	virtual ~Shape() {}                           // 가상 소멸자
};

// Circle 클래스 ( Shape 를 상속받음 )
class Circle : public Shape {
private:
	int x, y, radius;

public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI)
		: Shape(drawAPI), x(x), y(y), radius(radius) {}

	void draw() override {
		drawAPI->drawCircle(radius, x, y); // DrawAPI의 메서드 호출
	}
};

int main() {
	// RedCircle 객체 생성
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle());

	// GreenCircle 객체 생성 
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

	// draw 메서드 호출
	redCircle->draw();
	greenCircle->draw();

	// 메모리 해제 
	delete redCircle;
	delete greenCircle;

	return 0;
}