/*
5.fractions : GCD(to keep fractions in the simplest form)
Add2fractions()جمع الكسور
*/

#include <iostream>
#include <cstdlib>  // for abs()

using namespace std;
class Fraction{
    int num; //بسط
    int den; //مقام

  int GCD(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    //constructor
    Fraction(int _num=0, int _den=1){
        num = _num;
        den = (_den == 0) ? 1 : _den;;
    }

    //simplify
    void simplify() {
        int gcd = GCD(abs(num), abs(den));
        num /= gcd;
        den /= gcd;
        if (den < 0) { // نخلي المقام موجب دائمًا
            num = -num;
            den = -den;
        }
    }
      //sum
    Fraction add(Fraction f2) {
        Fraction result;
        result.num = (num * f2.den) + (f2.num * den);
        result.den = den * f2.den;
        result.simplify(); 
        return result;
    }

    //print the fraction
    void print(string label = "") const {
        if (!label.empty()) cout << label << endl;
        cout << "   ┌──────────────┐" << endl;
        cout << "   │ Numerator   │ " << num << endl;
        cout << "   │ Denominator │ " << den << endl;
        cout << "   └──────────────┘" << endl;
    }
  

};

int main(){
    cout << "\n============================================\n";
    cout << "            Fraction Adder Pro            \n";
    cout << "============================================\n\n";

    int n1, d1, n2, d2;
    cout << " Enter numerator and denominator of the first fraction (e.g. 2 5): ";
    cin >> n1 >> d1;

    cout << " Enter numerator and denominator of the second fraction (e.g. 3 4): ";
    cin >> n2 >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    cout << "\n════════════════════════════════════════════\n";
    cout << " Entered Fractions:\n";
    cout << "────────────────────────────────────────────\n";
    f1.print(" Fraction 1:");
    f2.print(" Fraction 2:");

    Fraction result = f1.add(f2);

    cout << "\n════════════════════════════════════════════\n";
    cout << " Result after Addition:\n";
    cout << "────────────────────────────────────────────\n";
    result.print(" Simplified Sum:");

    cout << "════════════════════════════════════════════\n";
    cout << " Operation completed successfully! \n";
    cout << "════════════════════════════════════════════\n\n";

    return 0;
}
