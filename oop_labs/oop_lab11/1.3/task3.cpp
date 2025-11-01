#include <iostream>
using namespace std;

//////////////////////////////
// 1. Template Swap
//////////////////////////////
template <class T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

//////////////////////////////
// 2. Template Stack
//////////////////////////////
template <class T>
class Stack {
    T arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(T val) { arr[++top] = val; }
    T pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }

    Stack<T> operator=(Stack<T> s) {
        top = s.top;
        for (int i = 0; i <= top; i++)
            arr[i] = s.arr[i];
        return *this;
    }

    Stack<T> operator+(Stack<T> s) {
        Stack<T> result;
        for (int i = 0; i <= top; i++)
            result.push(arr[i]);
        for (int i = 0; i <= s.top; i++)
            result.push(s.arr[i]);
        return result;
    }
};

int main() {
    cout << "===== Template Swap =====\n";
    int a=5, b=10;
    Swap(a,b);
    cout << "a=" << a << " b=" << b << endl;

    cout << "\n===== Template Stack =====\n";
    Stack<int> s1, s2;
    s1.push(10); s1.push(20);
    s2.push(30); s2.push(40);
    Stack<int> s3 = s1 + s2;

    while (!s3.isEmpty()) cout << s3.pop() << " ";
    cout << endl;
    return 0;
}
