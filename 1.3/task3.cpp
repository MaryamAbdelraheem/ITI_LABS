#include <iostream>
using namespace std;

double power(double base, int exp) 
{
    double result = 1;

    // Handle negative exponents
    bool isNegative = exp < 0;
    if (isNegative) exp = -exp;

    for (int i = 1; i <= exp; i++) {
        result *= base;
    }

    if (isNegative)
        result = 1.0 / result;

    return result;
}

int main() {
    double base;
    int exp;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exp;

    cout << base << "^" << exp << " = " << power(base, exp) << endl;
    return 0;
}