//fib -> recursion
#include <iostream>
using namespace std;

//without recursion

/*int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int a = 0, b = 1, next;

    cout << "Fibonacci Series: ";

    for (int i = 0; i < n; i++) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }

    cout << endl;
    return 0;
}*/

//with recursion

int fibSeries(int n);
int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci of " << n << " = " << fibSeries(n) << endl;
    return 0;
}

int fibSeries(int n){

    if (n == 0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fibSeries(n - 1) + fibSeries(n - 2);
    
}
