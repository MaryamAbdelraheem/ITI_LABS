/*Class implemet the Queue FIFO 
EnQueue and dequeue index 
Use 2 indexes one for entering and one for removing for fixing O(n) problem .
*/

#include <iostream>

using namespace std;

class Queue{
    int* queue;
    int indx_back;
    int indx_front;
    int size;
    int count;
public:
    //1.1 constructor
    Queue(int _size){
        size =_size;
        queue = new int[size];
        indx_front = 0;
        indx_back = -1;
        count = 0;
    }

    //1.2 destructor
    ~ Queue(){
        delete[] queue;
    }

    //1.3.1 check if empty or full
    bool isEmpty() {return count == 0;}
    bool isFull(){return count == size;}

    //1.3 enqueue ++
    void enqueue(int val){
        if (isFull()){
            cout<<"You can't enqueue your queue is full!!!!!!!";
            return;
        }
        indx_back = (indx_back + 1) % size;
        queue[indx_back]=val;
        count++;
        cout << val << " enqueued.\n"<<endl;
    }

    //1.4 dequeue --
    int dequeue(){
        if (isEmpty()) {
            cout << "You can't dequeue your queue is empty!!!!\n";
            return -1;
        }
        int val = queue[indx_front];
        indx_front = (indx_front + 1)%size;
        count--;
        cout << val << " dequeued.\n"<<endl;
        return val;
    }

    //1.5
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int idx = indx_front;
        for (int i = 0; i < count; i++) {
            cout << queue[idx] << " ";
            idx = (idx + 1) % size;
        }
        cout << endl;
    }
};
int main(){

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();

    q.dequeue();
    q.dequeue();
    q.print();


    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); 
    q.print();

    q.dequeue();
    q.print();

    return 0;
}
