/*class complex
real, img, setters, getters, print 
member function add 
standalone function subtract 
standalone print*/

#include <iostream>
#include <string>

using namespace std;

class Complex{ 

    int real;
    int img;

public:

    //set
    void setReal(int _real){
        real = _real;
    };

    void setImg(int _img){
        img = _img;
    }
    //get
    int getReal(){
        return real;
    }
    int getImg(){
        return img;
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

};

//declare standalone functions:
Complex subtract(Complex c1, Complex c2 );
//standalone print=========================================================
void printt(Complex c ) {
    c.print();
}


int main() {

    //1. create the objs:
    Complex c1, c2, sum, diff;
    
    //2. set your nums:
    c1.setReal(3);
    c1.setImg(4);

    c2.setReal(1);
    c2.setImg(-2);

    //3. print them:
    cout << "c1 = ";
    c1.print();
    cout << "\n";

    cout << "c2 = ";
    c2.print();
    cout << "\n";

    //4.calc:
        //4.1 member functions:
        //add
    sum = c1.add(c2);
    cout << "Sum (c1 + c2) = ";
    sum.print();
    cout << "\n";

        //4.2 standalone functions:
    diff = subtract(c1, c2);
    cout << "Difference (c1 - c2) = ";
    diff.print();
    cout << "\n";

  return 0;
}

//standalone function subtract ============================================
Complex subtract(Complex c1, Complex c2){
    Complex res;
    res.setReal(c1.getReal() - c2.getReal());
    res.setImg(c1.getImg() - c2.getImg());
    return res;
};
