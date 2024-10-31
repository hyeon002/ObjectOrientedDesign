#include <iostream> 
#include <vector> 
#include <string>
#include <bitset>

class Observer;

// Subject Ŭ���� 
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

// Observer Ŭ����
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

// BinaryObserver Ŭ���� ( Observer �� �ڽ� ) 
class BinaryObserver : public Observer {
public :
	BinaryObserver(Subject* subject) : Observer(subject) {
		this->subject->attach(this);
	}
	void update() override {
		std::cout << "Binary String: " << std::bitset<8>(subject->getState()) << std::endl;
		// std::bitset<8> -> 2������ ���� (<> ������ ũ�⸸ŭ�� ���� ���ڿ��� )
	}
};

// OctalObserver Ŭ���� ( Observer �� �ڽ� ) 
class OctalObserver : public Observer {
public :
	OctalObserver(Subject* subject) : Observer(subject) {
		this->subject->attach(this);
	}
	void update() override {
		std::cout << "Octal String: " << std::oct << subject->getState() << std::endl;
		// std::oct -> 8������ ����
	}
};

// HexaObserver Ŭ���� ( Observer �� �ڽ� ) 
class HexaObserver : public Observer {
public:
	HexaObserver(Subject* subject) : Observer(subject) {
		this->subject->attach(this);
	}
	void update() override {
		std::cout << std::hex << "Hex String: " << subject->getState() << std::endl;
		// std::hex -> 16������ ����
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