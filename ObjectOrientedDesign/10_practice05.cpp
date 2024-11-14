#include <iostream>
#include <cassert>

// CEO Ŭ���� ( rank 1 )
class CEO {
public:
	virtual ~CEO() {};
};

// CPO Ŭ���� ( rank 2, CEO �� ���� ��� )
class CPO : virtual public CEO {
public:
	virtual ~CPO() {};
};

// Manager Ŭ���� ( CEO, CPO �� ���� ��� )
class Manager : virtual public CEO, public CPO {
public:
	virtual ~Manager() {};
};

// Staff Ŭ���� ( rank 4 ) 
class Staff : public Manager {
public:
	virtual ~Staff() {};
};

int main() {
	// CPO* ���� ��, upcasting
	CPO* cpo = new Staff();

	// CEO* ���� ��, upcasting 
	CEO* ceo = new Staff();

	// Staff* ���� ��, cpo dynamic_cast ����
	Staff* staff = dynamic_cast<Staff*>(cpo);
	// cpo �� CPO Ÿ���� �����ͷ�, �����δ� Staff ��ü�� ����Ű�� ���� 
	// �׷��� CPO ���� Staff �� ĳ������ �õ��ϴµ�, 
	// CPO �� Staff �� �θ� Ŭ������ �ƴϹǷ� �� ĳ������ ���е� 
	

	// Staff* ���� ��, ceo dynamic_cast ����
	Staff* staff2 = dynamic_cast<Staff*>(ceo);
	// ceo �� Manager Ÿ���� �����ͷ�, Manager �� CEO �� �ڽ� Ŭ���� 
	// �׷��� Manager �� Staff �� �θ� Ŭ������ �ƴϹǷ� ĳ���ÿ� ������ 

	// Manager* ���� ��, dynamic_cast ���� 
	Manager* manager = dynamic_cast<Manager*>(ceo);

	// assert �Լ� ����Ͽ� ������ ������ nullptr ���� Ȯ�� 
	assert(staff != nullptr);
	assert(staff2 != nullptr);
	assert(manager != nullptr);

	delete cpo;
	delete ceo;

	return 0;
}
