#include <iostream>
#include <cassert>

// CEO 클래스 ( rank 1 )
class CEO {
public:
	virtual ~CEO() {};
};

// CPO 클래스 ( rank 2, CEO 를 가상 상속 )
class CPO : virtual public CEO {
public:
	virtual ~CPO() {};
};

// Manager 클래스 ( CEO, CPO 를 가상 상속 )
class Manager : virtual public CEO, public CPO {
public:
	virtual ~Manager() {};
};

// Staff 클래스 ( rank 4 ) 
class Staff : public Manager {
public:
	virtual ~Staff() {};
};

int main() {
	// CPO* 선언 후, upcasting
	CPO* cpo = new Staff();

	// CEO* 선언 후, upcasting 
	CEO* ceo = new Staff();

	// Staff* 선언 후, cpo dynamic_cast 진행
	Staff* staff = dynamic_cast<Staff*>(cpo);
	// cpo 는 CPO 타입의 포인터로, 실제로는 Staff 객체를 가리키고 있음 
	// 그러나 CPO 에서 Staff 로 캐스팅을 시도하는데, 
	// CPO 는 Staff 의 부모 클래스가 아니므로 이 캐스팅은 실패됨 
	

	// Staff* 선언 후, ceo dynamic_cast 진행
	Staff* staff2 = dynamic_cast<Staff*>(ceo);
	// ceo 는 Manager 타입의 포인터로, Manager 는 CEO 의 자식 클래스 
	// 그러나 Manager 는 Staff 의 부모 클래스가 아니므로 캐스팅에 실패함 

	// Manager* 선언 후, dynamic_cast 진행 
	Manager* manager = dynamic_cast<Manager*>(ceo);

	// assert 함수 사용하여 포인터 변수가 nullptr 인지 확인 
	assert(staff != nullptr);
	assert(staff2 != nullptr);
	assert(manager != nullptr);

	delete cpo;
	delete ceo;

	return 0;
}
