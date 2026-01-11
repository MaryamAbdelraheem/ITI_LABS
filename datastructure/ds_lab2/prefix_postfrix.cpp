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

    Complex operator+(Complex c){
        Complex res;
        //real
        res.real=real+c.real;
        //img
        res.img=img+c.img;
        return res;
    }

    int operator==(Complex c){
        return real==c.real&&img==c.img;
    }
    int operator!=(Complex c){
        return !(*this==c);
    }
    Complex operator=(Complex c){
        real=c.real;
        img=c.img;
        return *this;
    }
    //==========================================
    Complex& operator++(){ //prefix
        real++;
        return *this;
    }

     Complex& operator++(int){ //postfix
        real++;
        return *this;
    }
    //==========================================




};


int main() {
    

    Complex c0(1,2),c1, c2(10), c3(5, 6);
    //c3 = c1.operator+(c2);
    //c3 = c1+c2+c0;
    c3.print();

    //c1 = 2+c3;

    //prefix
    cout << "\nPrefix Increment:\n";
    (++c3).print();
    cout << endl;   
    //postfix
    cout << "\nPostfix Increment:\n";
    (c3++).print();
    cout << endl;
//////////////////////////////////////////////////
    
    

    return 0;
}

