/*works on wds old version:

#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define null -32 //for extended key.

using namespace std;

int _main() {
    
    //menu task
    char menu[3][10]={"new","display","exit"};
    int hindex = 2;
    char ch;
    for (int i=0;i<3;i++){
        if(i==hindex)
            textattrr(0x04);
        gotoxy(10,5+i);
        cout<<menu[i];
        textattrr(0x07);
    }
    ch = getch();//for recive the char 
    switch(ch){
        case 27:
            break;
        case -32:
            break;

    }
    
    return 0;
}*/


//=================================================================================
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


struct Employee {
    int id;
    char name[10];
    int age;
    int filled = false;
};

//"new"
void handleNew(Employee emp[], int size) {
    int index;
    cout << "\nEnter index (0-" << size - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= size) {
        cout << "Invalid index!\n";
        return;
    }
    else if (emp[index].filled) {
        cout << "\nExisting data:\n";
        cout << "ID: " << emp[index].id
             << " | Name: " << emp[index].name
             << " | Age: " << emp[index].age << endl;
    } 
    else {
        cout << "\nNo data found, please enter new info:\n";
        cout << "ID: ";
        cin >> emp[index].id;
        cout << "Name: ";
        cin >> emp[index].name;
        cout << "Age: ";
        cin >> emp[index].age;
        emp[index].filled = 1;
        cout << "\nData saved successfully.\n";
    }
    cout << "\nPress any key to return to menu...";
    getch();
}

//"display"
void displayEmployees(Employee emp[], int size) {
    cout << "\n=== Employee List ===\n";
    bool found = false;
    for (int i = 0; i < size; i++) {
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

int main() {
    int highlight = 0;
    char ch;
    int exitSelected = false;

    const int SIZE = 3;
    Employee emp[SIZE];

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
                    handleNew(emp, SIZE);
                    break;
                case 1: //display
                    displayEmployees(emp, SIZE);
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

