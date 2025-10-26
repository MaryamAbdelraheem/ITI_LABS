//copy constructor on stack constructor
#include <iostream>
using namespace std;

class Stack{
    //0 define 
    int* stack;
    int tos;
    int size;
public:
    
    //1.1 constructor
    Stack(int _size){
        size = _size;
        stack = new int[size]; 
        tos = -1;
    }
    //copy constructor --------------------------------------------------------------------

    Stack(Stack& s){
        tos = s.tos;
        size = s.size;
        stack = new int[size];
        for (int i=0; i<=tos; i++){
            stack[i] = s.stack[i];
        }
    }

    //-------------------------------------------------------------------------------------
    //1.2 destructor
    ~ Stack(){
        delete[] stack;
        cout << "Obj destructed\n";
    }

    //1.3 push
    void push(int val){
        if (tos == size -1){
            cout <<"You can't add Stack is full!!!!!!!!!";
            return;}
        stack[++tos] = val;
    }  

    //1.4 pop
    int pop(){
        if (tos == -1) {
            cout << "NO data to delete Stack is empty!!!!!!!!!\n";
            return -1;
        }
        return stack[tos--];
    }

    //1.5.1 check if the stack is empty or full
    bool isEmpty(){return tos == -1;}
   // bool isFull() { return top == size - 1; }

    //1.6 print the values in the stack
    void print() {
        if (isEmpty()) {
            cout << "No data to print Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= tos; i++)
            cout << stack[i] << " ";
        cout << endl;
    }

};


int main(){

   cout << "=== COPY CONSTRUCTOR : DEEP COPY ===\n";
   //copy stack
   //declare stack
    cout <<"original stack: "<< endl;
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.print();


    //deep copy
    cout <<"\ncopied stack: "<< endl;
    Stack s2(s1);
    s2.print();

    
    
    return 0;
}


