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

//copy constructor 
Complex (Complex& r){
    real=r.real;
    img = r.img;
    
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
    Complex& operator++(){ //prefix
        real++;
        return *this;
    }

     Complex operator++(int){ //postfix

        Complex res(real,img); //local data
        real++;
        return res;
    }

    explicit operator int(){
        return real;
    }



friend Complex operator+(int c,    Complex z);
};

//standalone function
Complex operator+(int c,    Complex z)
{
    Complex res(z.real+c,z.img);
    return res;
}

int main() {
    

    Complex c0(1,2),c1, c2(10), c3(5, 6);
    //c3 = c1.operator+(c2);
    //c3 = c1+c2+c0;
    c3.print();

    //c1 = 2+c3;

    c3= ++c1;

    if (c1==c2){
        cout<<"equals";
    }
    else{
        cout<<"\nNot equals";
    }
//////////////////////////////////////////////////
    if (c1!=c2){
        cout<<"Not equals";
    }
    else{
        cout<<"\n equals";
    }

    return 0;
}

