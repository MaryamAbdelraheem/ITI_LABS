/**
new -> append 
display -> display
count -> count the nodes
search -> search by id from the user
delete -> by the id from the user
insert after -> null / tail append / after
delete all -> delete node by node
 */

#include <iostream>
#include <string>

using namespace std;

struct emp{
    int id;
    string name;
    int age;
};

struct node {
    emp e;
    node * next;
    node * prev;
};

//the class creation
class Doubly_list{
    //helpfull ptrss 
    node * head;
    node * tail;

    private : 
    node * searchByid(int id){
        node * temp = head;

        while(temp){
            if ((temp->e).id == id)
            {
                return temp;
            }
            temp = temp -> next;
        }
        return NULL;    
    }
    
    public:
    
    //1.constructor----------------------------------------------------------------
    Doubly_list(){
        head = tail = NULL;
    };

    //2.append function----------------------------------------------------------------
    void append(int id, string name, int age){
        node * temp = new node;
        //insert employee data
        (temp -> e).id =id;
        (temp -> e).name = name;
        (temp -> e).age = age;

        //assign the ptrs with null
        temp -> prev = NULL;
        temp -> next = NULL;


        //assign the head and the tail to the new node (in case it is 1 node)
        if(head == NULL)
        {
            head = tail = temp;
        }
        else // in case it is more than 1 node
        {
            temp -> prev = tail;
            temp -> next = temp;
            tail = temp;
        }
    };

    //3. display function----------------------------------------------------------------
    void display(){
        node * temp = head;

        while (temp){
            cout << (temp ->e).id,(temp ->e).name,(temp ->e).age;
            temp = temp -> next ;
        }
    };

    //4.count----------------------------------------------------------------
    int count(){
        node * temp = head;
        int c =0;
        while (temp){
            c++;
        }
        return c;
    };

    //5.searchById (private version)----------------------------------------------------------------
    //create above

    //5.1 dispaly data using searchById (public version)
    emp searchByIdP(int id){
        emp e;
        e.id = -1;

        node * r = searchByid(id);
        if(r!=NULL){
            return r->e;
        }
        else
        {
            return e;
        }

    };

    //5.2 delete by id using searchById
    void deleteById(int id){
        node * r = searchByid(id);
        //5.2.1 case no node 
        if (r == NULL)
        {
            return ;
        }

        //5.2.2 case one node
        if (head == tail){
            head = tail = NULL;
        }// 5.2.3 case more then 1 node & its at the first
        else if(r == head){
            head = head -> next;
            head -> prev = NULL;
        }//5.2.4 case its at the end
        else if(r == tail){
            tail = tail -> prev;
            tail-> next = NULL;
        } 
        else{
           //pass 
        }

        //delete r;
    }

    //6.insert after ----------------------------------------------------------------

    //7. delete all----------------------------------------------------------------
    void deleteAll(){
        node * r = head;
        while(r){
            head -> next ;
            delete r;
        }
    }

};

