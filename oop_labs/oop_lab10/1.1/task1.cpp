/*
1. Parent (x,y), child(2)
1. Parent:: virtual add (x,y)
2. child:: override add (x,y,z)
*/

#include <iostream>
using namespace std;

class Parent{
    protected:
    int x,y;
public:
    Parent(int _x, int _y){
        x = _x;
        y = _y;
    }
    virtual int add() {
        cout << "Parent add(x, y): ";
        return x + y;
    }
    
};


class Child: public Parent{
    int z;
public:
    Child(int _x, int _y , int _z):Parent(_x, _y){
        z = _z;
    };
    int add() override {
        cout << "Child add(x, y, z): ";
        return x + y + z;
    };

};

int main(){

    Parent* p;

    Parent obj1(2,3);
    Child obj2(2,3,4);

    p = &obj1;
    cout << p->add() << endl; 

    p = &obj2;
    cout << p->add() << endl;

    return 0;
}
