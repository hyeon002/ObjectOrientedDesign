#include <iostream> 

// Parent Ŭ���� 
class Parent {
    char* p;
public:
    // Constructor 
    Parent() {
        p = new char[10];
        std::cout << "Parent Constructor invocation" << std::endl;
    }
    // Destructor 
    virtual ~Parent() {
        delete[] p;
        std::cout << "Parent Destructor invocation" << std::endl;
    }
};

// Child Ŭ���� ( Parent �� ��ӹ��� ) 
class Child : public Parent {
    char* c;
public:
    // Constructor 
    Child() : Parent() {
        c = new char[10];
        std::cout << "Child Constructor invocation" << std::endl;
    }
    // Destructor 
    ~Child() {
        delete[] c;
        std::cout << "Child Destructor invocation" << std::endl;
    }
};


int main() {

    std::cout << "--- Case1: Normal Child instantiation ---" << std::endl;
    Child* c = new Child();
    delete c;

    std::cout << "--- Case2: Parent pointer to Child ---" << std::endl;
    Parent* p = new Child();
    delete p;
    
    getchar();
}

/*
��°� ( ������ ) 
-- - Case1: Normal Child instantiation-- -
Parent Constructor invocation
Child Constructor invocation
Child Destructor invocation
Parent Destructor invocation
-- - Case2 : Parent pointer to Child-- -
Parent Constructor invocation
Child Constructor invocation
Parent Destructor invocation
*/
// -> Child �� Destructor �� ������� ���� 
// -> Parent Destructor �� virtual Ű���带 ���� 

/*
��°� ( ������ ) 
--- Case1: Normal Child instantiation ---
Parent Constructor invocation
Child Constructor invocation
Child Destructor invocation
Parent Destructor invocation
--- Case2: Parent pointer to Child ---
Parent Constructor invocation
Child Constructor invocation
Child Destructor invocation
Parent Destructor invocation
*/