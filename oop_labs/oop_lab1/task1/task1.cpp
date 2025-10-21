#include <iostream>


using namespace std ;
int main() {
    
    int size;

   do {
       cout << "enter your matrix size: ";
        cin >> size;
        if (size % 2 == 0) {
            cout << "Please enter an odd number!\n";
        }
    } while (size % 2 == 0);
   
//2. magic box 

//2.1 declare 
int magic[50][50] = {0};   //place wasn't cleared 
int num = 1;

int r = 0;    //first row      
int c = size / 2; //middle column

while (num <= size * size) 
{
    magic[r][c] = num;
    num++;
    
    int new_r = (r - 1 + size) % size; // move up
    int new_c = (c + 1) % size;        // move right
    
    if (magic[new_r][new_c] != 0)
    {
        r = (r + 1) % size;
    }else
    {
        r = new_r;
        c = new_c;
    }
}
    cout << "\nMagic Square of size " <<endl;
    for (r = 0; r < size; r++) {
        for (c = 0; c < size; c++) {
            cout << magic[r][c] << "\t";
        }
        cout << endl;
    }

 
 //-------------------------------------------------   
//3. bubble sort 





    return 0;
}