//swap function without pointers
/*#include <iostream>
using namespace std;

void swap(int i, int y);

int main() {

    int a = 9,  b = 8;
    cout << "Before swap: " << a << " " << b << endl;
    swap(a, b);
    return 0;
}
void swap (int i, int y) 
{
   //move i num to temp
    int temp = i;
    //move the y value to i var
    i = y;
    //move the temp value (i value) to y var
    y = temp;


    cout << "After swap (inside function): " << i << " " << y << endl;

}*/

//swap function with pointers
#include <iostream>

using namespace std;

//decleare method with the pointers
void swap(int *i, int *y);

int main() {

    //0. initiat the vars
    int i,y;

    //1. recive data from user
    cout << "enter your first number: ";
    cin >> i;
    cout << "enter your second number: ";
    cin >> y;

    cout << "Before swap: " << i << " " << y << endl;
    
    //2.apply your function
    swap(&i, &y);//pass by address

    cout << "After swap (inside function): " << i << " " << y << endl;
    
    return 0;
}

//define the funtion
void swap (int *i, int *y) 
{
    //move i value num to temp
    int temp = *i;
    //move the y value to i var
    *i = *y;
    //move the temp value (i value) to y var
    *y = temp;
}

//ptr -> the address that point to (عنوان القيمة ف الستاك)
//*ptr -> the pointer value it points to (القيمة)
//&ptr -> the pointer address (عنوان البوينتر نفسه ف الستاك)