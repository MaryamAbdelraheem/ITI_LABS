#include <iostream>
#include <string>

using namespace std;

struct node {
    int data;
    node * prev;

};

class Stack{
    node *tos;
public:
    Stack(){
        tos = NULL;
    };

    //helper functions=====
    bool isEmpty(){
        return tos == NULL;
    };
    bool isFull(){
        node* temp = new node;
        if(temp == NULL){
            return true;
        }
        delete temp;
        return false;
    };


    void push (int d){
        node* temp = new node;
        temp->data =d;
        temp->prev = NULL;
        if(tos == NULL){
            tos=temp;
        }else{
            temp -> prev = tos;
            tos = temp;
        }
       
    };

    int pop (int &d){
        if(tos == NULL){
            return 0;
        }
        d = tos -> data;
        node* temp = tos;
        tos = tos -> prev;
        delete temp;
        return 1;
    };



};


int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    int d;
    while(s.pop(d)){
        cout << d << endl;
    }

    return 0;
}