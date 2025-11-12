#include <iostream>
using namespace std;

class Complex {
    int real, img;
public:
    Complex(int r=0, int i=0) { 
        real = r; img = i; 
    }
    Complex(const Complex &c) { 
        real = c.real; img = c.img;
    }

    void print() {
        if (img >= 0) cout << real << "+" << img << "j";
        else cout << real << img << "j";
    }

    Complex operator+(Complex c) { return Complex(real + c.real, img + c.img); }
    Complex operator+(int n) { return Complex(real + n, img); }

    ///
    friend Complex operator+(int n, Complex c) {
        return Complex(c.real + n, c.img);
    }

    bool operator==(Complex c) { 
        return (real == c.real && img == c.img);
    }
    bool operator!=(Complex c) { 
        return !(*this == c); 
    }

    Complex& operator++() {  // prefix
        real++; return *this; 
    }     
    Complex operator++(int){ //postfix

        Complex res(real,img); //local data
        real++;
        return res;
    }


    explicit operator int() { return real; }  // casting to int
};

int main() {
    Complex c1(2,3), c2(1,2);
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = "; c3.print(); cout << endl;

    Complex c4 = c1 + 5;
    cout << "c1 + 5 = "; c4.print(); cout << endl;

    Complex c5 = 5 + c1;
    cout << "5 + c1 = "; c5.print(); cout << endl;

    if (c1 == c2) cout << "Equal\n"; else cout << "Not Equal\n";

    ++c1; cout << "++c1 = "; c1.print(); cout << endl;
    c1++; cout << "c1++ = "; c1.print(); cout << endl;

    int x = (int)c1;
    cout << "Casting Complex to int = " << x << endl;
    return 0;
}
