#include <iostream>  
#include <vector> 

// Shape Ŭ���� 
class Shape {
public:
	virtual void Draw() {
		std::cout << "Shape Draw" << std::endl;
	}
};

// Rect Ŭ���� ( Shape �� ��ӹ��� ) 
class Rect : public Shape {
public:
	void Draw() {
		std::cout << "Rect Draw" << std::endl;
	}
};

// Circle Ŭ���� ( Shape �� ��ӹ��� ) 
class Circle : public Shape {
public:
	void Draw() {
		std::cout << "Circle Draw" << std::endl;
	}
};

// triangle Ŭ���� ( Shape �� ��ӹ��� ) 
class triangle : public Shape {
public:
	void Draw() {
		std::cout << "Triangle Draw" << std::endl;
	}
};

int main() {

	std::vector<Shape*> v1; // ���� ���� ����  
	v1.push_back(new Rect);
	v1.push_back(new Circle);
	v1.push_back(new triangle);
	for (int i = 0; i < v1.size(); i++)
		v1[i]->Draw();
}