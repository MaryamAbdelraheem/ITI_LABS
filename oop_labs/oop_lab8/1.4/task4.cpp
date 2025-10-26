/*class (aggregation obj relationship)
- point (base)
- rec   (2 points)
- triangle (3 points)
- circle (1 point +reduis)
*/

#include <iostream>
using namespace std;

class Point{
    int x;
    int y;
public:
    //constructors:
    Point(int _x, int _y){
        x = _x;
        y = _y;
        //cout <<"\nobj created";
    }
    //destructor
    ~ Point(){
        //delete[] ;
        //cout << "\nObj destructed\n";
    }
    //getter
    int getX(){return x;}
    int getY(){return y;}
    

    //setter 
    void setX(int _x){
        x = _x;
    }
   
    void setY(int _y) {  
       y = _y;
    }
    void setPoint(int _x, int _y){
        x = _x;
        y = _y;
    }
     void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

};
//shapes ---------------------------------------------------------
class Rectangle{

    Point *ul,*lr;
public:
    //constructor
    //chain1
  
    Rectangle(Point* p1, Point* p2):ul(p1),lr(p2)
    { //chain2
        ul = p1;
        lr = p2;
    }
    //destructor
    ~ Rectangle(){
        //cout << "\nobj destroy";
    }
    //print
    void print(){
        cout << "Upper Left: ";
        ul->print();
        cout << " | Lower Right: ";
        lr->print();
        cout << endl;
    }

};
class Triangle{
    Point *p1,*p2,*p3;
public:

     //constructor
    
    //destructor
    Triangle(Point* _p1,Point* _p2, Point* _p3):p1(_p1),p2(_p2),p3(_p3)
    {
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
        //cout <<"\nobj created";
    }

    ~ Triangle(){
        //cout<<"\nobj destroyed";
    }
    //print
    void print(){
        cout << "Triangle vertices:\n";
        cout << "P1 = "; p1->print(); cout << endl;
        cout << "P2 = "; p2->print(); cout << endl;
        cout << "P3 = "; p3->print(); cout << endl;
    }

};
class Circle{

    Point *p1;
    int redius;
public:
    //constructor
    
    Circle(Point* _p1, int _radius = 5) {
        p1 = _p1;
        redius = _radius;
    }
    //destructor
    ~ Circle(){
        //cout<<"\nobj destroed";
    }
    //print
    void print(){
        cout << "Circle info:\n";
        cout << "P1 = "; p1->print(); cout << endl;
        cout << "reduis = "<<redius;cout <<endl;
    }

};


int main(){
    cout << "=== Aggregation Test: Point, Rectangle, Triangle, Circle ===\n";

    // create points independently
    Point p1(2, 3);
    Point p2(6, 8);
    Point p3(5, 1);

    cout << "\n--- Created Points ---\n";
    cout << "P1 = "; p1.print(); cout << endl;
    cout << "P2 = "; p2.print(); cout << endl;
    cout << "P3 = "; p3.print(); cout << endl;

    // pass point addresses to shapes (aggregation)
    cout << "\n--- Rectangle Test ---\n";
    Rectangle r1(&p1, &p2);
    r1.print();

    cout << "\n--- Triangle Test ---\n";
    Triangle t1(&p1, &p2, &p3);
    t1.print();

    cout << "\n--- Circle Test ---\n";
    Circle c1(&p3, 7);
    c1.print();

    cout << "\n=== End of Program ===\n";
    return 0;
}
