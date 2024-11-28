#include <iostream> 
#include <algorithm> 
#include <forward_list> 

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	// bubble sort 
	// first : ������ ������ ���� �ݺ��� 
	// last : ������ ������ �� �ݺ��� 
	// comp : �񱳸� ������ �Լ� ��ü ( Functor )
	if (first == last) return;

	// ��ü ������ ��ȸ�Ͽ� ������ �ݺ���  
	for (auto i1 = first; i1 != last; i1++) {
		// ������ �� ������ ���ϸ� ������ 
		for (auto i2 = first; i2 != last; i2++) {
			auto next = i2;
			++next;								
			if (next == last) break;
			if (comp(*next, *i2)) {				// comp �� �� ��Ҹ� �� 
				std::iter_swap(i2, next);		// �� ���� ��ȯ
			}
		}
	}
}

// Functor Ŭ���� 
// �������� ���� 
class compGreater {
public:
	bool operator()(int x, int y) {
		return x < y;
	}		// ���� ���� �������� ���� 
};

// Functor Ŭ����  
// �������� ���� 
class compLess {
public:
	bool operator()(int x, int y) {
		return x > y;
	}		// ū ���� �������� ���� 
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	
	// �������� ���� 
	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), compGreater());
	for (auto& value : values) {
		std::cout << value << " ";		// ���ĵ� value ���� ��� 
	}
	std::cout << std::endl;
	
	// �������� ���� 
	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), compLess());
	for (auto& value : values) {
		std::cout << value << " ";		// ���ĵ� value ���� ��� 
	}
	std::cout << std::endl;

	return 0;
}

// functor 
// �Ϲ� �Լ�ó�� ȣ��� �� �ִ� ��ü
// compGreater ( �������� ���� )
// �� ������ ���Ͽ� ���� ���� �������� ������ 
// comLess ( �������� ���� )
// �� ������ ���Ͽ� ū ���� �������� ������ 