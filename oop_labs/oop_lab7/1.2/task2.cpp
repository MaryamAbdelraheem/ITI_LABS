//Constrctor in complex -> use the default arg 

#include <iostream>
using namespace std;

class Complex{ 

    int real;
    int img;

public:

Complex (int _real=0, int _img=0){
    real=_real;
    img = _img;
}
~ Complex(){
    cout << "\nObject destruction\n";
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

};


int main() {

    Complex c1, c2(10), c3(5, 6);
    cout << "c1 = "; c1.print();            // default constructor → (0,0)
    cout << "\nc2 = "; c2.print();       // (10,0)
    cout << "\nc3 = "; c3.print();      // (5,6)

    return 0;
}

