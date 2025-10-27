/*2. shape class: 
attr -> dim 1,dim2
const -> 1. (dim1,dim2)&(dim1 we equla eltani),()
        + rec (dim1!=dim2), tring(!=) circle (=)*/


#include <iostream>
using namespace std;

class Shape{

    protected:
    int dim1;
    int dim2;
    int dim3;
public:
    //constructors:
    Shape( int _dim1, int _dim2, int _dim3 = 0){ //rectangle , tri(2 dim equlized) , tri(3 dim not equlized)
        dim1 = _dim1;
        dim2 = _dim2;
        dim3 = _dim3;
    }
    Shape(int _dim = 0){ //trig 3 dim equlized , circle 
        dim1 = _dim;
        dim2 = _dim;
        dim3 = _dim;
    }
    //destructor
    ~ Shape(){
        cout <<"shape destoryed";
    }
    //getter
    int getDim1(){return dim1;}
    int getDim2(){return dim2;}
    

    //setter 
    void setDim1(int _dim1){
        dim1 = _dim1;
    }
   
    void setDim2(int _dim2){
        dim2 = _dim2;
    }
    //print
     void print() {
        cout << "Dim1: " << dim1 << ", Dim2: " << dim2;
    }

};
//shapes ---------------------------------------------------------
class Rectangle: public Shape
{
public:
    //constructor
    //chain
    Rectangle(int _dim1, int _dim2) : Shape(_dim1, _dim2) {};
    
    //destructor
    ~ Rectangle(){
        cout << "\nRectangle destroy";
    }

    //print
    void print() {
        cout << "[Rectangle] ";
        Shape::print();
        cout << ", Area = " << dim1 * dim2 << endl;
    }

};

class Triangle : public Shape
{
public:

     //constructor
    //مثلث متساوي الاضلاع
    Triangle(int _dim) : Shape(_dim) {}
    //مثلث بابعاد مختلفة
    Triangle(int _dim1, int _dim2, int _dim3) : Shape(_dim1, _dim2, _dim3) {}

    //destructor
    

    ~ Triangle(){
        //cout<<"\nTriangle  destroyed";
    }
    //print
    void print(){
        cout << "[Triangle] ";
        Shape::print();
        cout << ", Area = " << (0.5 *dim1)* dim2 << endl;
    }

};
class Circle: public Shape
{
public:
    //constructor
    Circle(int radius) : Shape(radius) {};
    //destructor
    ~ Circle(){
        cout<<"\nCircle destroed";
    }
    //print
    void print() {
        cout << "[Circle] ";
        Shape::print();
        cout << ", Area = " << 3.14 * dim1 * dim1 << endl;
    }

};


int main(){
    cout << "=== Shapes : Rectangle, Triangle, Circle ===\n";

    Rectangle r(4, 6);
    Triangle t1(3, 4, 5);
    Triangle t2(5);
    Circle c(7);

    cout << "\n--- Shape Info ---\n";
    r.print();
    t1.print();
    t2.print();
    c.print();

    cout << "\n=== End of Program ===\n";
    
    return 0;

}


   



   