#include <iostream>
using namespace std;

void print_array(int arr[], int size, int x) {
    if(x==size){
        return;
    }
    print_array(arr, size, x+1);
    cout << arr[x] << " ";

}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size, 0);
    cout << endl;
    return 0;
}