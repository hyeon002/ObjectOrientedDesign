#include <vector> 
#include <string> 
#include <iostream> 

// Base1 클래스 
class Base1 {
public:
	// constructor 
	Base1(int n) : vector_(n, 3) {}
private:
	std::vector<char> vector_;
};

// Base2 클래스 
class Base2 {
public:
	// constructor 
	Base2(int n) : vector_(n, 3) {}
private:
	std::vector<char> vector_;
};

// Derived 클래스 ( Base1, Base2를 상속받음 )
class Derived : public Base1, Base2 {
public:
	Derived(const std::string& str) : Base2(1024), Base1(512)
	{
		i = 0;
	}
private:
	std::string str_;
	int i = 0;
};
int main() {
	Derived drv("1");
	// Base1 -> Base2 순서대로 실행됨 
	// 상속받은 순서대로


	return 0;
}

// Class Derived: public Base2, Base1 으로 할 경우 
// Base2 -> Base1 순서대로 실행됨 