class Animal {
public:
	Animal() {		// default constructor �߰� 
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
	Animal a(5);	// numberOfLeg ���� ���� 

	return 0;
}