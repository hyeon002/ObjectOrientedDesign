#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Rect {
	int w, h;
public:
	Rect() : w(0), h(0) {}
	Rect(int w, int h) : w(w), h(h) {}
	int area() {
		return w * h;
	}
	void print() {
		cout << "(" << w << "," << h << "," << area() << ")" << endl;
 	}
};

// compare �Լ� ( �� �Լ� ) 
bool compare(Rect &a, Rect &b) {
	return a.area() < b.area();
}

int main() {
	int num;

	std::cout << "�簢���� ���� : ";
	std::cin >> num;

	// �簢���� ���� ���� �Է� 
	std::vector<Rect> rectangle;
	for (int i = 0; i < num; i++) {
		int w, h;
		std::cout << "�簢���� �� : ";
		std::cin >> w;

		std::cout << "�簢���� ���� : ";
		std::cin >> h;

		rectangle.emplace_back(w, h);
	}

	// ������ �������� ���� 
	std::sort(rectangle.begin(), rectangle.end(), compare);


	for (auto& rect : rectangle) {
		rect.print();
	}

	return 0;
}

// �簢���� ���� �Է¹ް� 
// ������ŭ ���� ���� �Է¹ް� 
// ������ ������������ ��� 