#include <iostream>

// Component ( interface )
// Shape 클래스
class Shape {
public:
	virtual void draw() = 0;
};

// Concrete component 
// Rectangle 클래스 
class Rectangle : public Shape {
public:
	void draw() override {
		std::cout << "Shape : Rectangle" << std::endl;
	}
};
// Circle 클래스
class Circle : public Shape {
public :
	void draw() override {
		std::cout << "Shape : Circle" << std::endl;
	}
};

// Decorator
// ShapeDecorator 추상 클래스 
class ShapeDecorator : public Shape {
protected :
	Shape* decoratedShape;
public:
	ShapeDecorator(Shape* decoratedShape) : decoratedShape(decoratedShape) {}
	void draw() {
		decoratedShape->draw();
	}
};

// Concrete Decorator 
// RedShapeDecorator 클래스 
class RedShapeDecorator : public ShapeDecorator {
private:
	void setRedBorder() {
		std::cout << "Border Color : Red" << std::endl;
	}
public:
	explicit RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {};

	void draw() {
		decoratedShape->draw();
		setRedBorder();
	}
};

int main() {
	Shape* circle = new Circle();
	Shape* redCircle = new RedShapeDecorator(new Circle());
	Shape* redRectangle = new RedShapeDecorator(new Rectangle());

	std::cout << "Circle with normal border" << std::endl;
	circle->draw();

	std::cout << "\nCircle of red border" << std::endl;
	redCircle->draw();

	std::cout << "\nRectangle of red border" << std::endl;
	redRectangle->draw();

	delete circle;
	delete redCircle;
	delete redRectangle;

	return 0;
}