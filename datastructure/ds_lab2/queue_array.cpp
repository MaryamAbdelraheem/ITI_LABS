#include <iostream>

using namespace std;
//circular queue with array


class Queue{
    int* arr;
    int front;
    int rear;
    int capacity;
public:
    Queue(int s=5){ //construnctor
        front = rear = -1;
        capacity = s;
        arr = new int[capacity];
    }

    // helper functions------------------
    int isEmpty(){
    return rear == -1;
    }   
    int isFull(){
    return (rear == capacity -1 && front ==0) || (rear +1 == front);
    }
    //enqueue
    void enqueue(int val){
        cout << "\nTrying to enqueue: " << val << endl;
        if (isFull()==1){
            return;
        }
        if(rear == -1){
            rear =front =0;
        }
        else if(rear == capacity -1){
            rear =0;
        } else {
            rear++;
        }
        arr[rear] = val;
    }

    //dequeue
    int dequeue (int& d){
        if(isEmpty()==1){
            return 0;
        }
        d = arr[front];
        if(front == rear){
            front = rear = -1;
        } else if(front == capacity -1){
            front =0;
        } else {
            front++;
        }
        return 1;
    }


};



int main(){
    //test queue=========================================
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);

    int x;
    if(q1.dequeue(x)==1){
        cout << x <<  "  dequeued from queue\n" << endl;
    }
    //===================================================



    return 0;
}


//queue with linked list


//stack with linked list

//infix_postfix