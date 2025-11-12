#include <iostream>
using namespace std;

class Fraction {
    int num, den;
public:
    Fraction(int n=0, int d=1) { 
        num = n; 
        den = (d==0)?1:d; 
    }

    void print() { 
        cout << num << "/" << den; 
    }

    Fraction operator+(Fraction f) {
        return Fraction(num*f.den + f.num*den, den*f.den);
    }

    Fraction operator+(int n) { 
        return Fraction(num + n*den, den); 
    }

    friend Fraction operator+(int n, Fraction f) {
        return Fraction(f.num + n*f.den, f.den);
    }

    bool operator==(Fraction f) { 
        return num*f.den == f.num*den; 
    }

    Fraction operator=(Fraction f) { 
        num = f.num; den = f.den; return *this; 
    }

    Fraction& operator++() {  // prefix
        num += den; return *this;
     }    
    Fraction operator++(int) { // postfix
        Fraction temp = *this; 
        num += den; 
        return temp; 
    }  
};

int main() {
    Fraction f1(1,2), f2(1,3);
    Fraction f3 = f1 + f2;
    cout << "f1 + f2 = "; f3.print(); cout << endl;

    Fraction f4 = f1 + 2;
    cout << "f1 + 2 = "; f4.print(); cout << endl;

    Fraction f5 = 2 + f1;
    cout << "2 + f1 = "; f5.print(); cout << endl;

    if (f1 == f2) cout << "Equal\n"; else cout << "Not Equal\n";

    ++f1; cout << "++f1 = "; f1.print(); cout << endl;
    f1++; cout << "f1++ = "; f1.print(); cout << endl;
    return 0;
}
