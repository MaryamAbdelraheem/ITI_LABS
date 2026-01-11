#include <iostream>
#include <string>

using namespace std;


struct node {
    int data;
    node * next;

};

//the class creation
class Queue{
    //helpfull ptrss 
    node * front;
    node * rear;
    
    public:
    Queue(){
        front = rear = NULL;
    };
    void Enqueue(int d){
        cout << "\nTrying to enqueue: " << d << endl;
        node* temp = new node;
        if(temp == NULL){
            return;
        }
        temp ->data =d;
        temp -> next = NULL;
        if(front ==NULL){
            front = rear = temp;
        }
        else{
            rear -> next = temp;
            rear = temp;
        }
    }

    bool Dequeue(int &d){
        if(front == NULL){
            return false;
        }
        node* temp = front;
        d = front -> data;

        front = front -> next;
        delete temp;
        return true;
    }

    
};


int main(){
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    int d;
    while(q.Dequeue(d)){
        cout << "Dequeued: " << d << endl;
    }

    return 0;
}

