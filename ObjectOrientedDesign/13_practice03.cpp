#include <iostream> 
#include <algorithm> 
#include <forward_list> 

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	// bubble sort 
	// first : 정렬할 범위의 시작 반복자 
	// last : 정렬할 범위의 끝 반복자 
	// comp : 비교를 수행할 함수 객체 ( Functor )
	if (first == last) return;

	// 전체 값들을 순회하여 정렬을 반복함  
	for (auto i1 = first; i1 != last; i1++) {
		// 인접한 두 값들을 비교하며 정렬함 
		for (auto i2 = first; i2 != last; i2++) {
			auto next = i2;
			++next;								
			if (next == last) break;
			if (comp(*next, *i2)) {				// comp 로 두 요소를 비교 
				std::iter_swap(i2, next);		// 두 값을 교환
			}
		}
	}
}

// Functor 클래스 
// 오름차순 정렬 
class compGreater {
public:
	bool operator()(int x, int y) {
		return x < y;
	}		// 작은 값을 기준으로 정렬 
};

// Functor 클래스  
// 내림차순 정렬 
class compLess {
public:
	bool operator()(int x, int y) {
		return x > y;
	}		// 큰 값을 기준으로 정렬 
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	
	// 오름차순 정렬 
	std::cout << "오름차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), compGreater());
	for (auto& value : values) {
		std::cout << value << " ";		// 정렬된 value 들을 출력 
	}
	std::cout << std::endl;
	
	// 내림차순 정렬 
	std::cout << "내림차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), compLess());
	for (auto& value : values) {
		std::cout << value << " ";		// 정렬된 value 들을 출력 
	}
	std::cout << std::endl;

	return 0;
}

// functor 
// 일반 함수처럼 호출될 수 있는 객체
// compGreater ( 오름차순 정렬 )
// 두 값들을 비교하여 작은 값을 기준으로 정렬함 
// comLess ( 내림차순 정렬 )
// 두 값들을 비교하여 큰 값을 기준으로 정렬함 