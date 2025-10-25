// demonstrate function overloading:
//2 pram id name - 3 pram id name age - 4 prams id name age salary

#include <iostream>
using namespace std;

class Employee{
    int id;
    string name;
    int age;
    float salary;
public:

    
    //2 pram id name
    Employee(int _id, string _name){
        id = _id;
        name = _name;
        age = 0;
        salary = 0;
        
    };
    //3 pram id name age
    Employee(int _id, string _name, int _age){
        id = _id;
        name = _name;
        age = _age;
        salary = 0;
        
    };
    //4 prams id name age salary
    Employee(int _id, string _name, int _age, float _salary){
        id = _id;
        name = _name;
        age = _age;
        salary = _salary;
        
    };

    //member function:
    void print() {
        cout <<"DATA ====================";
        cout << "\nID: " << id << endl
        << "Name: " << name << endl 
        << "Age: " << age << endl
        << "Salary: " << salary << endl;
    }

};
int main() {

    

    Employee e1(1001, "Ali");

    Employee e2(1002, "Ahmed", 22);

    Employee e3(1003, "Mohamed", 45, 10000);

    e1.print();
    e2.print();
    e3.print();
    return 0;
}

