#include <iostream>
#include <string>

// Shape 클래스
class Shape {
public:
    virtual void draw() = 0;    // 순수 가상 함수
    virtual ~Shape() {}         // 가상 소멸자
};

// RoundedRectangle 클래스 ( Shape 를 상속받음 )
class RoundedRectangle : public Shape {
public:
    void draw() override {
        std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
    }
};

// RoundedSquare 클래스 ( Shape 를 상속받음 )
class RoundedSquare : public Shape {
public:
    void draw() override {
        std::cout << "Inside RoundedSquare::draw() method." << std::endl;
    }
};

// Rectangle 클래스 ( Shape 를 상속받음 )
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};

// Square 클래스 ( Shape 를 상속받음 )
class Square : public Shape {
public:
    void draw() override {
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};

// AbstractFactory 추상 클래스
class AbstractFactory {
public:
    virtual Shape* getShape(const std::string& shapeType) = 0;  // 순수 가상 함수
    virtual ~AbstractFactory() {}                               // 가상 소멸자
};

// ShapeFactory 클래스 ( AbstractFactory 를 상속받음 ) 
class ShapeFactory : public AbstractFactory {
public:
    Shape* getShape(const std::string& shapeType) override {
        if (shapeType == "RECTANGLE") {
            return new Rectangle();
        }
        else if (shapeType == "SQUARE") {
            return new Square();
        }
        return nullptr;
    }
};

// RoundedShapeFactory 클래스 ( AbstractFactory 를 상속받음 ) 
class RoundedShapeFactory : public AbstractFactory {
public:
    Shape* getShape(const std::string& shapeType) override {
        if (shapeType == "RECTANGLE") {
            return new RoundedRectangle();
        }
        else if (shapeType == "SQUARE") {
            return new RoundedSquare();
        }
        return nullptr;
    }
};

// FactoryProducer 클래스
class FactoryProducer {
public:
    static AbstractFactory* getFactory(bool rounded) {
        if (rounded) {
            return new RoundedShapeFactory();
        }
        else {
            return new ShapeFactory();
        }
    }
};

int main() {
    // ShapeFactory 생성 
    AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);

    // Reactangle 객체 생성, draw 메서드 호출, 메모리 해제 
    Shape* shape1 = shapeFactory->getShape("RECTANGLE");
    shape1->draw();
    delete shape1;

    // Square 객체 생성 ,, 
    Shape* shape2 = shapeFactory->getShape("SQUARE");
    shape2->draw();
    delete shape2;

    // RoundedShapeFactory 생성 
    AbstractFactory* roundedShapeFactory = FactoryProducer::getFactory(true);

    // RoundedRectangle 객체 생성 ,,
    Shape* shape3 = roundedShapeFactory->getShape("RECTANGLE");
    shape3->draw();
    delete shape3;

    // RoundedSquare 객체 생성 ,, 
    Shape* shape4 = roundedShapeFactory->getShape("SQUARE");
    shape4->draw();
    delete shape4;

    return 0;
}