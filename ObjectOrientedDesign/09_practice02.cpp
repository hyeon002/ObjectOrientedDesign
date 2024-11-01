
// Base 클래스 
class Base {
public:
	void func_1() {};
protected:
	void func_2() {};
private:
	int x_;
};

// Derived 클래스 ( Base 자식, protected로 상속 받음 )
// -> Base 클래스 public 멤버 함수인 func_1 가 protected 로 변환됨 
// -> Base 클래스 protected 멤버 함수인 func_2 가 protected 로 유지됨 
class Derived : protected Base {
public:
	void func_3() {
		func_1();
		func_2();
	}
};

int main() {
	Derived d;
	d.func_3();
	// d.func_1();	ERORR
	// protected 로 변환된 func_1 함수는 외부 함수인 main 함수에서
	// 실행 불가능
}