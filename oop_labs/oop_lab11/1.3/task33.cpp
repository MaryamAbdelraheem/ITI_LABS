#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
public:
    Stack() { 
        top = -1; 
    }
    void push(int val) { 
        arr[++top] = val; 
    }
    int pop() { 
        return arr[top--]; 
    }
    bool isEmpty() { return top == -1; }

    Stack operator=(Stack s) {
        top = s.top;
        for (int i=0; i<=top; i++) arr[i] = s.arr[i];
        return *this;
    }

    Stack operator+(Stack s) {
        Stack result;
        for (int i=0; i<=top; i++) result.push(arr[i]);
        for (int i=0; i<=s.top; i++) result.push(s.arr[i]);
        return result;
    }
};

int main() {
    Stack s1, s2;
    s1.push(10); 
    s1.push(20);
    s2.push(30); 
    s2.push(40);
    Stack s3 = s1 + s2;

    cout << "Merged Stack (s1 + s2): ";
    while (!s3.isEmpty()) cout << s3.pop() << " ";
    cout << endl;
    return 0;
}
