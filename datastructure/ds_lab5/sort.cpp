#include <iostream>
using namespace std;

/* ---------- Utility Function ---------- */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* ---------- Bubble Sort ---------- */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/* ---------- Insertion Sort ---------- */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* ---------- Quick Sort ---------- */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ---------- Main Program ---------- */
int main() {
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Quick Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            break;
        case 3:
            quickSort(arr, 0, n - 1);
            break;
        default:
            cout << "Invalid choice!";
            return 0;
    }

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}