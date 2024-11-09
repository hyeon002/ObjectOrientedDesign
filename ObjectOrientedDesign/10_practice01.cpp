#include <iostream>
#include <string>

// Shape Ŭ����
class Shape {
public:
    virtual void draw() = 0;    // ���� ���� �Լ�
    virtual ~Shape() {}         // ���� �Ҹ���
};

// RoundedRectangle Ŭ���� ( Shape �� ��ӹ��� )
class RoundedRectangle : public Shape {
public:
    void draw() override {
        std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
    }
};

// RoundedSquare Ŭ���� ( Shape �� ��ӹ��� )
class RoundedSquare : public Shape {
public:
    void draw() override {
        std::cout << "Inside RoundedSquare::draw() method." << std::endl;
    }
};

// Rectangle Ŭ���� ( Shape �� ��ӹ��� )
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};

// Square Ŭ���� ( Shape �� ��ӹ��� )
class Square : public Shape {
public:
    void draw() override {
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};

// AbstractFactory �߻� Ŭ����
class AbstractFactory {
public:
    virtual Shape* getShape(const std::string& shapeType) = 0;  // ���� ���� �Լ�
    virtual ~AbstractFactory() {}                               // ���� �Ҹ���
};

// ShapeFactory Ŭ���� ( AbstractFactory �� ��ӹ��� ) 
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

// RoundedShapeFactory Ŭ���� ( AbstractFactory �� ��ӹ��� ) 
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

// FactoryProducer Ŭ����
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
    // ShapeFactory ���� 
    AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);

    // Reactangle ��ü ����, draw �޼��� ȣ��, �޸� ���� 
    Shape* shape1 = shapeFactory->getShape("RECTANGLE");
    shape1->draw();
    delete shape1;

    // Square ��ü ���� ,, 
    Shape* shape2 = shapeFactory->getShape("SQUARE");
    shape2->draw();
    delete shape2;

    // RoundedShapeFactory ���� 
    AbstractFactory* roundedShapeFactory = FactoryProducer::getFactory(true);

    // RoundedRectangle ��ü ���� ,,
    Shape* shape3 = roundedShapeFactory->getShape("RECTANGLE");
    shape3->draw();
    delete shape3;

    // RoundedSquare ��ü ���� ,, 
    Shape* shape4 = roundedShapeFactory->getShape("SQUARE");
    shape4->draw();
    delete shape4;

    return 0;
}