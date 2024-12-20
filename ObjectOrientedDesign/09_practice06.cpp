#include <iostream>  
#include <vector> 

// Shape 클래스 
class Shape {
public:
	virtual void Draw() {
		std::cout << "Shape Draw" << std::endl;
	}
};

// Rect 클래스 ( Shape 를 상속받음 ) 
class Rect : public Shape {
public:
	void Draw() {
		std::cout << "Rect Draw" << std::endl;
	}
};

// Circle 클래스 ( Shape 를 상속받음 ) 
class Circle : public Shape {
public:
	void Draw() {
		std::cout << "Circle Draw" << std::endl;
	}
};

// triangle 클래스 ( Shape 를 상속받음 ) 
class triangle : public Shape {
public:
	void Draw() {
		std::cout << "Triangle Draw" << std::endl;
	}
};

int main() {

	std::vector<Shape*> v1; // 도형 저장 버퍼  
	v1.push_back(new Rect);
	v1.push_back(new Circle);
	v1.push_back(new triangle);
	for (int i = 0; i < v1.size(); i++)
		v1[i]->Draw();
}