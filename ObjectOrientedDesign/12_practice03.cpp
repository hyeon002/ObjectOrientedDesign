#include <iostream> 

template <typename T, int num = 5>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;

	// add_num 함수 호출 부분을 수정함 ( <int, 2> 로 ) 
	std::cout << "x : " << add_num<int, 2>(x) << std::endl;
}


// 원래 실행 값 
// x : 8

// x : 5