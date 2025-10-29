/*
shapes
        1. circle, square
        2. array of shapes
        3. Print(Shape*) => Print shape
*/

#include <iostream>
using namespace std;

class Shape{

    protected:
    int dim1;
    int dim2;
    int dim3;
public:
    // Constructors
    Shape(int _dim1 = 0, int _dim2 = 0, int _dim3 = 0) {
        dim1 = _dim1;
        dim2 = _dim2;
        dim3 = _dim3;
    }
    
    //print
    virtual void print() { // virtual = polymorphic behavior
        cout << "Generic Shape" << endl;
    }
    //destructor
    virtual ~Shape() { // virtual destructor for safety
        cout << "[Shape destroyed]\n";
    }

};
//shapes ---------------------------------------------------------
class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : Shape(w, h), width(w), height(h) {}

    void print() override {
        cout << "[Rectangle] Width = " << width
             << ", Height = " << height
             << ", Area = " << width * height << endl;
    }

    ~Rectangle() {
        cout << "[Rectangle destroyed]\n";
    }
};



class Triangle : public Shape {
public:
    // Equilateral
    Triangle(int side) : Shape(side, side, side) {}

    // Scalene or Isosceles
    Triangle(int a, int b, int c) : Shape(a, b, c) {}

    void print() override {
        cout << "[Triangle] Sides = (" << dim1 << ", " << dim2 << ", " << dim3 << ")";
        
        // If all sides equal → equilateral
        if (dim1 == dim2 && dim2 == dim3) {
            cout << ", Type = Equilateral";
            cout << ", Area = " << 0.5 * dim1 * dim2;  // base × height / 2
        }
        // If two sides equal → isosceles
        else if (dim1 == dim2 || dim1 == dim3 || dim2 == dim3) {
            cout << ", Type = Isosceles";
            cout << ", Area = " << 0.5 * dim1 * dim2;
        }
        // Else scalene
        else {
            cout << ", Type = Scalene";
            cout << ", Area = " << 0.5 * dim1 * dim2;  // treat dim1 & dim2 as base/height
        }

        cout << endl;
    }

    ~Triangle() {
        cout << "[Triangle destroyed]\n";
    }
};

class Circle : public Shape {
    int radius;
public:
    Circle(int r) : Shape(r), radius(r) {}

    void print() override {
        cout << "[Circle] Radius = " << radius
             << ", Area = " << 3.14 * radius * radius << endl;
    }

    ~Circle() {
        cout << "[Circle destroyed]\n";
    }
};


class Square : public Shape {
    int side;
public:
    Square(int s) : Shape(s, s), side(s) {}

    void print() override {
        cout << "[Square] Side = " << side
             << ", Area = " << side * side << endl;
    }

    ~Square() {
        cout << "[Square destroyed]\n";
    }
};


void Print(Shape* s) {
    s->print(); // calls the correct version auto
}


int main(){

   cout << "=== Shapes: Rectangle, Square, Circle, Triangle ===\n\n";

    // array of shapes
    Shape* shapes[4];

    shapes[0] = new Rectangle(4, 6);
    shapes[1] = new Square(5);
    shapes[2] = new Circle(3);
    shapes[3] = new Triangle(3, 4, 5);

    cout << "--- Shape Info ---\n";
    for (int i = 0; i < 4; i++) {
        Print(shapes[i]);
    }

    cout << "\n=== Cleaning up ===\n";
    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }

    
    
    return 0;

}


   



   