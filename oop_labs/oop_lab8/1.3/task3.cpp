/*class (composition obj relationship)
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

    Point ul,lr;
public:
    //constructor
    //chain1
    Rectangle(int x1, int x2 , int y1 ,int y2):ul(x1,y1),lr(x2,y2)
    {
        ul.setPoint(x1,y1);
        lr.setPoint(x2,y2);
        //cout <<"\nobj created";
    }
    Rectangle(Point p1, Point p2):ul(p1),lr(p2)
    { //chain2
        ul = p1;
        lr = p2;
        //cout <<"\nobj created";
    }
    //destructor
    ~ Rectangle(){
        //cout << "\nobj destroy";
    }
    //print
    void print(){
        cout << "Upper Left: ";
        ul.print();
        cout << " | Lower Right: ";
        lr.print();
        cout << endl;
    }

};
class Triangle{
    Point p1,p2,p3;
public:

     //constructor
    Triangle(int x1, int x2 , int y1 ,int y2, int x3, int y3):p1(x1,y1),p2(x2,y2),p3(x3, y3)
    {
        p1.setPoint(x1,y1);
        p2.setPoint(x2,y2);
        p3.setPoint(x3,y3);
        //cout <<"\nobj created";
    }
    //destructor
    Triangle(Point _p1,Point _p2, Point _p3):p1(_p1),p2(_p2),p3(_p3)
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
        cout << "P1 = "; p1.print(); cout << endl;
        cout << "P2 = "; p2.print(); cout << endl;
        cout << "P3 = "; p3.print(); cout << endl;
    }

};
class Circle{

    Point p1;
    const int reduis = 5;
public:
    //constructor
    Circle(int _x, int _y): p1(_x,_y){
        p1.setPoint(_x,_y);
        //cout <<"\nobj created";
    }
    Circle(Point p): p1(p){
        p1 = p;
        //cout <<"\nobj created";
    }
    //destructor
    ~ Circle(){
        //cout<<"\nobj destroed";
    }
    //print
    void print(){
        cout << "Circle info:\n";
        cout << "P1 = "; p1.print(); cout << endl;
        cout << "reduis = "<<reduis;cout <<endl;
    }

};


int main(){
    cout << "=== Composition Test: Point, Rectangle, Triangle, Circle ===\n";

    // --- Create Points  ---
    Point p1(2, 3);
    Point p2(6, 8);
    Point p3(5, 1);

    cout << "\n--- Created Points ---\n";
    cout << "P1 = "; p1.print();
    cout << "P2 = "; p2.print();
    cout << "P3 = "; p3.print();
    cout << endl;

    // --- Rectangle test ---
    cout << "\n--- Rectangle Test ---\n";
    Rectangle r1(1,2,3,4);
    Rectangle r2(p1, p2);
    r1.print();
    r2.print();
    // --- Triangle test ---
    cout << "\n--- Triangle Test ---\n";
    Triangle t1(1,2,3,4,5,6);
    Triangle t2(p1, p2, p3);
    t1.print();
    t2.print();

    // --- Circle test ---
    cout << "\n--- Circle Test ---\n";
    Circle c1(1,2);
    Circle c2(p1);
    c1.print();
    c2.print();

    cout << "\n=== End of Program ===\n";
    return 0;

}


   



   