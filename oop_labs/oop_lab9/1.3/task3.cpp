/**
 3. menu
new -> push
display -> pop
peak -> print last elem
is full->
is empty->
 */

 #include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>  //for system()
#include <string>

using namespace std;

//to read the char without press enter
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

class Employee {

    protected:
    int id;
    char name[10];
    int age;
    int filled = false;

public:
    //constructor
    //defualt 
    Employee() {
        id = 0;
        strcpy(name, "N/A");
        age = 0;
        filled = false;
    }
    //passed
      Employee(int _id, const char* _name, int _age) {
        id = _id;
        strncpy(name, _name, 9);  
        name[9] = '\0';
        age = _age;
        filled = true;
    }
    //destructor
    ~Employee() {
        // cout << "Employee destroyed.\n"; 
    }

    //setter
    void setId(int _id) { id = _id; filled = true; }
    void setName(const char* _name) { strncpy(name, _name, 9); name[9] = '\0'; }
    void setAge(int _age) { age = _age; }

    //getter
    int getId() const { return id; }
    const char* getName() const { return name; }
    int getAge() const { return age; }
    bool isFilled() const { return filled; }

    //print
    void print() const {
        cout << "\n  ID: " << id
             << " \n Name: " << name
             << " \n Age: " << age << endl;
    }
};

class Stack {
    Employee* arr;
    int top;
    int size;

public:
    Stack(int _size) {
        size = _size;
        arr = new Employee[size];
        top = -1;
    }

    ~Stack() { delete[] arr; }

    bool isFull() { return top == size - 1; }
    bool isEmpty() { return top == -1; }

    void push() {
        if (isFull()) {
            cout << "\nStack is FULL!\n";
            getch();
            return;
        }

        int id, age;
        char name[10];
        cout << "\nEnter Employee Data:\n";
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;

        arr[++top] = Employee(id, name, age);
        cout << "\nEmployee added successfully!\n";
        getch();
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nStack is EMPTY!\n";
        } else {
            cout << "\nRemoved Employee:\n";
            arr[top].print();
            top--;
        }
        getch();
    }

    void peek() {
        if (isEmpty()) {
            cout << "\nStack is EMPTY!\n";
        } else {
            cout << "\nTop Employee:\n";
            arr[top].print();
        }
        getch();
    }

    void displayAll() {
        if (isEmpty()) {
            cout << "\nNo Employees to Display.\n";
        } else {
            cout << "\n=== Employee Stack ===\n";
            for (int i = top; i >= 0; i--) {
                cout << "[" << i << "]";
                arr[i].print();
                cout << "------------------\n";
            }
        }
        getch();
    }
};

//function to print the menu
void printMenu(int highlight) {
    
    string menu[] = {"New(ADD)", "Display(DELET)", "peak(CHOOSE)","Is Full?", "Is Empty?","Diaplay All" , "Exit"};
    int options = 7;
    system("clear"); // clear screen
    //cout.flush();
    cout << "\n=== Stack MENU ===\n\n";
    for (int i = 0; i < options; i++) {
        if (i == highlight)
            cout << "\033[1;47;31m > " << menu[i] << " < \033[0m\n"; // coloring
        else
            cout << "   " << menu[i] << "\n";
    }
}

int main() {
    int highlight = 0;
    char ch;
    int exitSelected = false;


    Stack st(3);
    

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
                case 0: st.push(); break;
                case 1: st.pop(); break;
                case 2: st.peek(); break;
                case 3:
                    cout << (st.isFull() ? "\nStack is FULL.\n" : "\nStack is NOT full.\n");
                    getch();
                    break;
                case 4:
                    cout << (st.isEmpty() ? "\nStack is EMPTY.\n" : "\nStack is NOT empty.\n");
                    getch();
                    break;
                case 5:st.displayAll(); break;
                case 6:
                    cout << "\nExiting program...\n";
                    exitSelected = true;
                    break;
            }  
        }
    }

    return 0;
}

