#include <iostream> 

// GlobalClass 클래스 
class GlobalClass {
private:
	int m_value;
	static GlobalClass* s_instance;

	// 생성자를 private 에 생성함 ( 외부에서 직접 객체 생성 불가능 ) 
	GlobalClass(int v = 0)
	{
		m_value = v;
	}
public:
	int get_value()
	{
		return m_value;
	}
	void set_value(int v)
	{
		m_value = v;
	}

	// singleton 인스턴스를 반환하는 메서드 
	static GlobalClass* instance()
	{
		if (!s_instance) {
			s_instance = new GlobalClass;
		}
		return s_instance;
	}
};

GlobalClass* GlobalClass::s_instance = 0;

// foo 메서드 
void foo(void)
{
	GlobalClass::instance()->set_value(1);
	std::cout << "foo: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

// bar 메서드 
void bar(void)
{
	GlobalClass::instance()->set_value(2);
	std::cout << "bar: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

int main()
{
	std::cout << "main: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
	foo();
	bar();
}