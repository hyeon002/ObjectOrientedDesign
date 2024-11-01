#include <iostream> 

// Parent 클래스 
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

// Child 클래스 ( Parent 를 상속받음 ) 
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
출력값 ( 수정전 ) 
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
// -> Child 의 Destructor 가 실행되지 않음 
// -> Parent Destructor 에 virtual 키워드를 붙임 

/*
출력값 ( 수정후 ) 
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