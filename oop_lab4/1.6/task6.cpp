#include <iostream>
using namespace std;

// تعريف الـ struct
struct Employee {
    int id;
    string name;
    float salary;
};

//read
void readEmployees(Employee arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nEnter data for employee #" << i + 1 << endl;
        cout << "ID: ";
        cin >> arr[i].id;

        cout << "Name: ";
        cin.ignore();         // لتفريغ البفر قبل getline
        getline(cin, arr[i].name);

        cout << "Salary: ";
        cin >> arr[i].salary;
    }
}

// دالة لطباعة بيانات الموظفين
void printEmployees(const Employee arr[], int n) {
    cout << "\n--- Employees List ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee #" << i + 1 << endl;
        cout << "ID: " << arr[i].id << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Salary: " << arr[i].salary << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee employees[n]; // مصفوفة بحجم n

    readEmployees(employees, n);
    printEmployees(employees, n);

    return 0;
}