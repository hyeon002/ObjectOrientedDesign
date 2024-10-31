#include <iostream> 
#include <vector> 
#include <string>
#include <bitset>

class Observer;

// Subject 클래스 
class Subject {
private:
	std::vector<Observer*> observers;
	int state;

public:
	int getState() {
		return state;
	}

	void setState(int state) {
		this->state = state;
		notifyAllObservers();
	}

	void attach(Observer* observer) {
		observers.push_back(observer);
	}

	void notifyAllObservers();
};

// Observer 클래스
class Observer {
protected :
	Subject* subject;

public:
	virtual void update() = 0;
	Observer(Subject* sub) : subject(sub) {}
};

void Subject::notifyAllObservers() {
	for (Observer* observer : observers) {
		observer->update();
	}
}

// BinaryObserver 클래스 ( Observer 의 자식 ) 
class BinaryObserver : public Observer {
public :
	BinaryObserver(Subject* subject) : Observer(subject) {
		this->subject->attach(this);
	}
	void update() override {
		std::cout << "Binary String: " << std::bitset<8>(subject->getState()) << std::endl;
		// std::bitset<8> -> 2진수로 지정 (<> 정해준 크기만큼의 이진 문자열로 )
	}
};

// OctalObserver 클래스 ( Observer 의 자식 ) 
class OctalObserver : public Observer {
public :
	OctalObserver(Subject* subject) : Observer(subject) {
		this->subject->attach(this);
	}
	void update() override {
		std::cout << "Octal String: " << std::oct << subject->getState() << std::endl;
		// std::oct -> 8진수로 지정
	}
};

// HexaObserver 클래스 ( Observer 의 자식 ) 
class HexaObserver : public Observer {
public:
	HexaObserver(Subject* subject) : Observer(subject) {
		this->subject->attach(this);
	}
	void update() override {
		std::cout << std::hex << "Hex String: " << subject->getState() << std::endl;
		// std::hex -> 16진수로 지정
	}
};

int main() {
	Subject subject;

	new HexaObserver(&subject);
	new OctalObserver(&subject);
	new BinaryObserver(&subject);

	std::cout << "First state change: 15" << std::endl;
	subject.setState(15);

	std::cout << "Second state change: 10" << std::endl;
	subject.setState(10);
}