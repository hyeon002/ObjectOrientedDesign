#include <iostream> 

// GlobalClass Ŭ���� 
class GlobalClass {
private:
	int m_value;
	static GlobalClass* s_instance;

	// �����ڸ� private �� ������ ( �ܺο��� ���� ��ü ���� �Ұ��� ) 
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

	// singleton �ν��Ͻ��� ��ȯ�ϴ� �޼��� 
	static GlobalClass* instance()
	{
		if (!s_instance) {
			s_instance = new GlobalClass;
		}
		return s_instance;
	}
};

GlobalClass* GlobalClass::s_instance = 0;

// foo �޼��� 
void foo(void)
{
	GlobalClass::instance()->set_value(1);
	std::cout << "foo: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

// bar �޼��� 
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