#include <iostream>

// DrawAPI Ŭ���� 
class DrawAPI {
public :
	virtual void drawCircle(int radius, int x, int y) = 0;	// ���� �Լ� 
	virtual ~DrawAPI() {}									// ���� �Ҹ���
};

// RedCircle Ŭ���� ( DrawAPI �� ��ӹ��� )
class RedCircle : public DrawAPI {
public :
	void drawCircle(int radius, int x, int y) override {
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

// GreenCircle Ŭ���� ( DrawAPI �� ��ӹ��� )
class GreenCircle : public DrawAPI {
public:
	void drawCircle(int radius, int x, int y) override {
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

// Shape Ŭ���� 
class Shape {
protected:
	DrawAPI* drawAPI;

	Shape(DrawAPI* drawAPI) : drawAPI(drawAPI) {} // ������
public:
	virtual void draw() = 0;                      // ���� ���� �Լ�
	virtual ~Shape() {}                           // ���� �Ҹ���
};

// Circle Ŭ���� ( Shape �� ��ӹ��� )
class Circle : public Shape {
private:
	int x, y, radius;

public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI)
		: Shape(drawAPI), x(x), y(y), radius(radius) {}

	void draw() override {
		drawAPI->drawCircle(radius, x, y); // DrawAPI�� �޼��� ȣ��
	}
};

int main() {
	// RedCircle ��ü ����
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle());

	// GreenCircle ��ü ���� 
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

	// draw �޼��� ȣ��
	redCircle->draw();
	greenCircle->draw();

	// �޸� ���� 
	delete redCircle;
	delete greenCircle;

	return 0;
}