/*Class stack and function 
Give it stack and it empty the stack 
Arr dynamic allocated*/

#include <iostream>
using namespace std;

class Stack{
    //0 define 
    int* stack;
    int top;
    int size;
public:
    
    //1.1 constructor
    Stack(int _size){
        size = _size;
        stack = new int[size]; 
        top = -1;
    }
    //1.2 destructor
    ~ Stack(){
        delete[] stack;
        cout << "Obj destructed\n";
    }

    //1.3 push
    void push(int val){
        if (top == size -1){
            cout <<"You can't add Stack is full!!!!!!!!!";
            return;}
        stack[++top] = val;
    }  

    //1.4 pop
    int pop(){
        if (top == -1) {
            cout << "NO data to delete Stack is empty!!!!!!!!!\n";
            return -1;
        }
        return stack[top--];
    }

    //1.5.1 check if the stack is empty or full
    bool isEmpty(){return top == -1;}
   // bool isFull() { return top == size - 1; }

    //1.6 print the values in the stack
    void print() {
        if (isEmpty()) {
            cout << "No data to print Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }

};
void emptyStack(Stack& s);

int main(){

   cout << "=== CASE 1: Non-empty Stack ===\n";
    Stack s1(5);
    
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.print();
    emptyStack(s1);
    s1.print();

    cout << "\n-----------------------\n";
    cout << "=== CASE 2: Empty Stack ===\n";
    Stack s2(0);
    s2.print();
    emptyStack(s2);
    
    return 0;
}

//1.5 empty the stack
    void emptyStack(Stack& s){
        if (s.isEmpty() == false)
        {
        cout << "\nEmptying the stack...\n";
        while (!s.isEmpty()){
            cout << "Popped: " << s.pop() << endl;
        }
        cout << "Your Stack now is empty\n";
    }
        else{
            cout << "your stack is already empty!!" << endl;
        }
    }

