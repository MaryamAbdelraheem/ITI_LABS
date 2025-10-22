//work on new versions:
/*
البدائل بتكون مختلفة:
	•	نستخدم أكواد الألوان (ANSI escape codes) بدل textattr.
	•	نستخدم terminal control بدل gotoxy.
	•	نكتب دالة صغيرة بدل getch().
	•	نستخدم system(“clear”) لمسح الشاشة بدل clrscr().
*/
//for mac

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>  //for system()
#include <string>

using namespace std;

struct Employee {
    int id;
    char name[10];
    int age;
    int filled = false;
};
char getch();
void printMenu(int highlight);
void handleNew(Employee*& emp, int* no);
void displayEmployees(Employee* emp, int no);
bool subMenu();




int main() {
    int highlight = 0;
    char ch;
    int exitSelected = false;

    int no;
    Employee* emp= nullptr;

    while (!exitSelected) {
        printMenu(highlight);
        ch = getch();

        if (ch == 27) { // بداية كود السهم
            getch(); // يتجاهل '['
            ch = getch();
            if (ch == 'A' && highlight > 0) highlight--; // ↑
            if (ch == 'B' && highlight < 3) highlight++; // ↓
        } else if (ch == '\n') { // Enter
            system("clear");
          switch (highlight) {
                case 0: //new
                    handleNew(emp, &no);
                    break;
                case 1: //display
                    displayEmployees(emp, no);
                    break;
                case 2://submenu
                    if (subMenu())
                        exitSelected = true;
                    break;
                case 3:
                    cout << "\nExiting program...\n";
                    exitSelected = true;
                    break;
            }  
        }
    }
    
    return 0;
}


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

//function to print the menu
void printMenu(int highlight) {
    string menu[4] = {"New", "Display", "SubMenu", "Exit"};
    system("clear"); // clear screen
    //cout.flush();
    cout << "\n=== MAIN MENU ===\n\n";
    for (int i = 0; i < 4; i++) {
        if (i == highlight)
            cout << "\033[1;47;31m > " << menu[i] << " < \033[0m\n"; // coloring
        else
            cout << "   " << menu[i] << "\n";
    }
}



//"new"
void handleNew(Employee*& emp, int* no) {
    
    cout << "enter the employee no. : ";
    cin >> *no;

    delete[] emp;
    emp = new Employee[*no];

    
    cout << "Enter Employee Data";
    

   cout << "\n=== Enter Employee Data : ===\n";
    for (int i = 0; i < *no; i++) {
        cout << "\nEmployee #" << i + 1 << ":\n";
        cout << "ID: ";
        cin >> emp[i].id;
        cout << "Name: ";
        cin >> emp[i].name;
        cout << "Age: ";
        cin >> emp[i].age;
        emp[i].filled = true;
    }

    cout << "\nPress any key to return to menu...";
    getch();
}

//"display"
void displayEmployees(Employee* emp, int no) {
    cout << "\n=== Employee List ===\n";
    bool found = false;
    for (int i = 0; i < no; i++) {
        if (emp[i].filled) {
            found = true;
            cout << "Index: " << i
                 << " | ID: " << emp[i].id
                 << " | Name: " << emp[i].name
                 << " | Age: " << emp[i].age << endl;
        }
    }

    if (!found)
        cout << "No employee data found.\n";

    cout << "\nPress any key to return to menu...";
    getch();
}

//"subMenu"
bool subMenu() {
    string submenu[2] = {"Done", "Back"};
    int highlight = 0;
    char ch;
    bool exitProgram = false;
    bool backToMain = false;

    while (!backToMain && !exitProgram) {
        system("clear");
        cout << "\n=== SUB MENU ===\n\n";
        for (int i = 0; i < 2; i++) {
            if (i == highlight)
                cout << "\033[1;47;31m > " << submenu[i] << " < \033[0m\n";
            else
                cout << "   " << submenu[i] << "\n";
        }

        ch = getch();
        if (ch == 27) { // arrows
            getch();
            ch = getch();
            if (ch == 'A' && highlight > 0) highlight--;
            if (ch == 'B' && highlight < 1) highlight++;
        } else if (ch == '\n') { // Enter
            system("clear");
            switch (highlight) {
                case 0:
                    cout << "\nYou selected: Done\n";
                    cout << "Exiting program...\n";
                    exitProgram = true;
                    break;
                case 1:
                    cout << "\nReturning to Main Menu...\n";
                    backToMain = true;
                    break;
            }
            if (!exitProgram)
                getch();
        }
    }

    return exitProgram;
}

