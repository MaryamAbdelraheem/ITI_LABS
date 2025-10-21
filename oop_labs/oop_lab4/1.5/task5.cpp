#include <iostream>
using namespace std;

// تعريف الـ struct
struct Student {
    string name;
    int age;
    float grade;
};

//read student
void readData(Student &s) {
    cout << "Enter student name: ";
    getline(cin, s.name);

    cout << "Enter student age: ";
    cin >> s.age;

    cout << "Enter student grade: ";
    cin >> s.grade;

    // ضروري لتفريغ الـ buffer بعد cin عشان getline يشتغل صح بعد كده
    cin.ignore();
}

// print
void printData(const Student &s) {
    cout << "\n--- Student Information : ---\n";
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Grade: " << s.grade << endl;
}

int main() {
    Student st;

    readData(st);
    printData(st);

    return 0;
}