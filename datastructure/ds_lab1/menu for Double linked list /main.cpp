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
#include <termios.h>
#include <unistd.h>
#include <cstdlib>  //for system()
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
            temp->prev = tail;   // new node points back
            tail->next = temp;   // old tail points forward
            tail = temp;         // update tail
        }
    };

    //3. display function----------------------------------------------------------------
    void display(){
        node * temp = head;

        while (temp){
            cout << temp->e.id << " "
                << temp->e.name << " "
                << temp->e.age << endl;
            temp = temp -> next ;
        }
    };

    //4.count----------------------------------------------------------------
    int count(){
        node * temp = head;
        int c =0;
        while (temp){
            c++;
            temp = temp->next;
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
    void insertAfter(int afterid, int newId, string newName, int newAge){
        node * r = searchByid(afterid);
        if (r == NULL){
            return ;
        }

        node * temp = new node;
        //insert employee data
        (temp -> e).id =newId;
        (temp -> e).name = newName;
        (temp -> e).age = newAge;

        //assign the ptrs with null
        temp -> prev = NULL;
        temp -> next = NULL;

        //case insert after the tail
        if (r == tail){
            r->next = temp;
            temp->prev = r;
            tail = temp;
        }
        else{ //case insert in the middle
            temp->next = r->next;
            temp->prev = r;
            r->next->prev = temp;
            r->next = temp;
        }
    };

    //7. delete all----------------------------------------------------------------

    void deleteAll(){
    node * r = head;
    while(r){
        node* next = r->next;
        delete r;
        r = next;
    }
    head = tail = NULL;
}

};

//====================================================================== the menu implementation ================================================================

char getch(){                      // دالة لمحاكاة دالة getch()
    char buf = 0;                  //to store the enterd char
    struct termios old = {0}, newt={0};      //lib to control the terminal - متغير old علشان نخزن فيه الإعدادات القديمة للتيرمنال قبل ما نغيّرها

    tcgetattr(0, &old);             //talk to the system "get the current value and store it in the old var"

    old.c_lflag &= ~ICANON; // إلغاء الانتظار للـ Enter //the normal status for the terminal
    old.c_lflag &= ~ECHO;   // إلغاء الطباعة التلقائية //reponsible to print the entered key but we hide it for more privicy
    tcsetattr(0, TCSANOW, &old);      //resposiblity: apply the changes right now

    read(0, &buf, 1);                 //read 1 char from the keyboard and store it in the buf

    tcsetattr(0, TCSANOW, &old);      //after finishing reset the settings to old - to prevent effect on the next program

    return buf;                      // return the enterd key
}


void printMenu(int highlight) {
    
    string menu[] = {"New(append)", "Display(display list)", "Count(count nodes)","Search(search by id)", "Delete node ","Delete All" , "insert After", "Exit"};
    int options = 8;
    system("clear"); // clear screen
    //cout.flush();
    cout << "\n=== MENU ===\n\n";
    for (int i = 0; i < options; i++) {
        if (i == highlight)
            cout << "\033[1;47;31m > " << menu[i] << " < \033[0m\n"; // coloring
        else
            cout << "   " << menu[i] << "\n";
    }
}

int main() {
    Doubly_list list;
    int highlight = 0;
    char ch;
    bool exitSelected = false;
    
    int id, age;
    string name;
    const int options = 8;
    
    while (!exitSelected) {
        printMenu(highlight);
        ch = getch();

        if (ch == 27) { // بداية كود السهم
            getch(); // يتجاهل '['
            ch = getch();
            if (ch == 'A' && highlight > 0) highlight--; // ↑
            if (ch == 'B' && highlight < 7) highlight++; // ↓
        } else if (ch == '\n') { // Enter
            system("clear");
        switch (highlight) {
                //cases:
                case 0: // Append
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;

        list.append(id, name, age);
        cout << "\nEmployee added successfully\n";
        getch();
        break;

    case 1: // Display
        cout << "\nEmployees List:\n";
        list.display();
        getch();
        break;

    case 2: // Count
        cout << "\nNumber of nodes = " << list.count() << endl;
        getch();
        break;

    case 3: // Search by ID
        cout << "Enter ID to search: ";
        cin >> id;

        {
            emp e = list.searchByIdP(id);
            if (e.id == -1)
                cout << "Employee not found\n";
            else
                cout << e.id << " " << e.name << " " << e.age << endl;
        }

        getch();
        break;

    case 4: // Delete by ID
        cout << "Enter ID to delete: ";
        cin >> id;

        list.deleteById(id);
        cout << "\nAfter delete:\n";
        list.display();
        getch();
        break;

    case 5: // Delete All
        list.deleteAll();
        cout << "All nodes deleted successfully\n";
        getch();
        break;

    case 6: // Insert After
        int afterId, newId;
        cout << "Inserting new employee:\n";
        cout << "Enter ID to insert after: ";
        cin >> afterId;
        cout << "Enter new Employee ID: ";
        cin >> newId;  
        cout << "Enter new Employee Name: ";
        cin >> name;    
        cout << "Enter new Employee Age: ";
        cin >> age;
        list.insertAfter(afterId, newId, name, age);
        cout << "\nAfter insert:\n";
        getch();
        break;

    case 7: // Exit
        exitSelected = true;
        break;
            }  
        }
    }

    return 0;
}