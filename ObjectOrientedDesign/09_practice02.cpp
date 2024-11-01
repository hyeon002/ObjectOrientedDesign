
// Base Ŭ���� 
class Base {
public:
	void func_1() {};
protected:
	void func_2() {};
private:
	int x_;
};

// Derived Ŭ���� ( Base �ڽ�, protected�� ��� ���� )
// -> Base Ŭ���� public ��� �Լ��� func_1 �� protected �� ��ȯ�� 
// -> Base Ŭ���� protected ��� �Լ��� func_2 �� protected �� ������ 
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
	// protected �� ��ȯ�� func_1 �Լ��� �ܺ� �Լ��� main �Լ�����
	// ���� �Ұ���
}