#include <iostream>

using namespace std;

//decleare method with the pointers
void printArray(int size, int arr[]);
void readArray(int size, int arr[]);

int main() 
{
    //0. initialize 
    int n;

    //read from user
    cout<< "enter the array size: ";
    cin >> n;
    int arr[n];
    readArray(n, arr );
    printArray(n, arr);
    
    return 0;
}

//define the funtion
void printArray (int size, int arr[]) 
{
    //printing methods
 
    //1. *(arr+i)
    cout << "\nPrinting using *(arr + i): ";
    for(int i=0; i< size; i++)
        cout << *(arr + i)<<" ";
    //2. arr[i]
    cout << "\nPrinting using arr[i]: ";
     for(int i=0; i< size; i++)
        cout << arr[i]<<" ";
    
    //initialize the pointer and -> on arr
    //3. ptr[i]
    int *ptr = arr; 
    cout << "\nPrinting using ptr[i]: ";
    for(int i=0; i< size; i++)
        cout << ptr[i]<<" ";
    //4. *(ptr+i)
    cout << "\nPrinting using *(ptr + i): ";
    for(int i=0; i< size; i++)
        cout << *(ptr+i)<<" ";
    
    cout << endl;
}
void readArray(int size, int arr[])
{
    //recive data
    cout << "Enter " << size << " elements:\n";
    for (int i =0; i< size;i++)
        cin >> *(arr+i);
}


//notes:
//ptr -> the address that point to (عنوان القيمة ف الستاك)
//*ptr -> the pointer value it points to (القيمة)
//&ptr -> the pointer address (عنوان البوينتر نفسه ف الستاك)

//printing methods
/*
1. *(arr+i)
2. arr[i]
3. ptr[i]
4. *(ptr+i)
*/;