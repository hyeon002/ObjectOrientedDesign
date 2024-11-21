#include <iostream> 

// 같은 타입의 인수를 처리하는 template 함수
template<typename T>
T min(T x, T y) {
	return x < y ? x : y;
}

// 다른 타입의 인수를 처리하는 template 함수 ( overloading )
template <typename T1, typename T2>
auto min(T1 x, T2 y) {
	return x < y ? x : y;
}

int main() {
	int x = 3;
	int y = 2;
	double d = 2.1;
	double e = 3.3;
	std::cout << "min(x,y): " << min(x, y) 
			  << ", min(d,e): " << min(d, e) 
			  << ", min(d, x) : " << min<double, int>(d, x) 
			  << std::endl; 
		return 0;
}

// int 형과 double 형으로 다른 타입이라서 에러가 발생함 
// 다른 타입의 인수를 처리하는 template 를 정의함 