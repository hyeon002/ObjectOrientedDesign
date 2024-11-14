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

// compare 함수 ( 비교 함수 ) 
bool compare(Rect &a, Rect &b) {
	return a.area() < b.area();
}

int main() {
	int num;

	std::cout << "사각형의 개수 : ";
	std::cin >> num;

	// 사각형의 폭과 높이 입력 
	std::vector<Rect> rectangle;
	for (int i = 0; i < num; i++) {
		int w, h;
		std::cout << "사각형의 폭 : ";
		std::cin >> w;

		std::cout << "사각형의 높이 : ";
		std::cin >> h;

		rectangle.emplace_back(w, h);
	}

	// 면적을 기준으로 정렬 
	std::sort(rectangle.begin(), rectangle.end(), compare);


	for (auto& rect : rectangle) {
		rect.print();
	}

	return 0;
}

// 사각형의 개수 입력받고 
// 개수만큼 폭과 높이 입력받고 
// 면적의 오름차순으로 출력 