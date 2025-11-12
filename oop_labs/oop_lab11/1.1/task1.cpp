#include <iostream>
using namespace std;

class Complex{ 

    int real;
    int img;
    static int no;  //declare the var ////////////////////////////

public:

Complex (int _real=0, int _img=0){
    real=_real;
    img = _img;
    no++; //////////////////////////////////////
}

//copy constructor 
Complex (Complex& r){
    real=r.real;
    img = r.img;
    no++;////////////////////////////////////////
}
~ Complex(){
    cout << "\nObject destruction\n";
    no--;////////////////////////////////////////
}

    //set
    
    void setReal(int _real){real = _real;}

    void setImg(int _img){img = _img;}
    //get
    int getReal(){return real;}
    int getImg(){return img;}
    
    //member function print =============================================
    void print(){
        if(img>0)
            cout<<real<<"+"<<img<<"j";
        else if(img<0)
            cout<<real<<img<<"j";
        else
            cout<<real;
    }

    //member function add=================================================
  Complex add(Complex c){
    Complex res;
    //real
    res.real=real+c.real;
    //img
    res.img=img+c.img;
    return res;
};

static int getCounter(){
    return no;
}

friend void myfunc(Complex r){};
};
//define static var
int Complex::no=0;

void myfunc(Complex r){
    cout << "\n\nCurrent number of objects(in function): " << r.getCounter() << endl;
}

int main() {
    
    Complex c0(7,9);

    myfunc(c0);

    Complex c1, c2(10), c3(5, 6);
    cout << "c1 = "; c1.print();
    cout << "\nc2 = "; c2.print();
    cout << "\nc3 = "; c3.print();

    cout << "\n\nCurrent number of objects(after function destroyed): " << c1.getCounter() << endl;

    return 0;
}

