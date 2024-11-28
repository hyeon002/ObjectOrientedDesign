#include <iostream> 
#include <string> 
#include <algorithm> 

// 다중 타입 인자들의 최솟값을 구하는 함수 ( min_value 함수 )
template<typename T>
double min_value(T x) {
	return x; 
}

template<typename T, typename... Args>
double min_value(T x, Args... args) {
	auto value = min_value(args...);
	if (x < value) {		// x 값이 나머지 최솟값보다 작다면 
		return x;			// x 를 return 
	}
	else {					// 그렇지 않으면
		return value;		// value ( 나머지 최솟값 )를 return 함
	}
}

int main() {
	auto x = min_value(42, 3.14, 11.1f, -2);

	std::cout << x;		// -2 
	
	getchar();
	return 0;
}

// min_value 함수 
// min_value(T x)
// -> 마지막 인자의 값을 return 함 
// 재귀가 종료됨 

// min_value(T x, Args... args)
// -> 다중 인자들 중에서 재귀적으로 최솟값을 계산함 
// if 문을 통해 현재 x 값이 나머지 값들보다 작다면 현재 x 값을 return 하도록 하고
// 그렇지 않으면 나머지 값들 중 최솟값을 반환함 