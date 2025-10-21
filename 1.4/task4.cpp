#include <iostream>
using namespace std;

int reverseInt(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;          // Get last digit
        reversed = reversed * 10 + digit;  // Append digit
        n /= 10;                     // Remove last digit
    }
    return reversed;
}

int main() {
    string num;
    cout << "Enter an integer: ";
    cin >> num;
    
    string reversed = "";
    for (int i = num.size() - 1; i >= 0; i--) {
        reversed += num[i];
    }
    cout << "Reversed: " << reversed << endl;
     return 0;
}


   