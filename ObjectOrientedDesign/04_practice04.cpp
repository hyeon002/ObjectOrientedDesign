class Animal {
public:
	Animal() {		// default constructor 추가 
		this -> numberOfLeg = 0;
	}
	Animal(int numberOfLeg) {
		this -> numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};

int main() {
	Animal a;
	Animal a(5);	// numberOfLeg 값을 전달 

	return 0;
}