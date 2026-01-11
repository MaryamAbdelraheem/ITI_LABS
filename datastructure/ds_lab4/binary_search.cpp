#include <iostream>
#include <string>

using namespace std;
//iterative binary search>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int bs(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return mid; // Key found
        else if (arr[mid] < key) //key bigger than mid >>>>>>>
            start = mid + 1; // Search in the right half
        else                   //key smaller than mid >>>>>>>>
            end = mid - 1; // Search in the left half
    }

    return -1; // Key not found
}
//recursive binary search>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int bs_recursive(int arr[], int start, int end, int key) {
    if (start > end)
        return -1; // Key not found
    int mid = (start + end) / 2;
    if (arr[mid] == key)
        return mid; // Key found
    else if (arr[mid] < key) //key bigger than mid >>>>>>>
        return bs_recursive(arr, mid + 1, end, key); // Search in the right half
    else                   //key smaller than mid >>>>>>>>
        return bs_recursive(arr, start, mid - 1, key); // Search in the left half
}

//=====================================================================================================
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 23;
    
    int result_iterative = bs(arr, size, key);
    if (result_iterative != -1)
        cout << "Iterative: Element found at index " << result_iterative << endl;
    else
        cout << "Iterative: Element not found in the array" << endl;

    int result_recursive = bs_recursive(arr, 0, size - 1, key);
    if (result_recursive != -1)
        cout << "Recursive: Element found at index " << result_recursive << endl;
    else
        cout << "Recursive: Element not found in the array" << endl;

    return 0;
}