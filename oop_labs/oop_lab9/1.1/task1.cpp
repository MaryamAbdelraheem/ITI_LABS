/*1. classes                     //const - setters - getters - print//
-base: person (id,name,age)[✅] 
- employee (+salary) 
- student (+grade)*/


#include <iostream>
#include <string>
using namespace std;

class Person{
    //attr
    int id;
    string name;
    int age;

public:
    //constructors:
    //1
    Person(int _id, string _name, int _age){
        id = _id;
        name = _name;
        age = _age;
    }

    //destructor
    ~ Person(){
        cout << "\nperson destroyyy\n";
    }
  
    //getter
    int getID(){return id;}
    string getName(){return name;}
    int getAge(){return age;}
    

    //setter 
    void setID(int _id){
        id = _id;
    }
   
    void setName(string _name) {  
       name = _name;
    }
    void setAge(int _age){
        age = _age;
    }

    void print() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age;
    }

};
//classes  ---------------------------------------------------------

class Employee: public Person
{
    //attr
    float salary;
public:
    //constructor
    //chain
    Employee(int _id = 0, string _name = "", int _age = 0, float _salary = 0.0):Person(_id, _name, _age) {
        salary = _salary;
    }
 
    //destructor
    ~Employee() {
        cout << "\nEmployee destroyed\n";
    }

    //getter - setter 
    void setSalary(float _salary) { salary = _salary; }
    float getSalary() const { return salary; }

    //print
    void print() const {
        cout << "\n[Employee]\n ";
        Person::print();
        cout << ", Salary: " << salary << endl;
    }

};

class Student: public Person
{
    //attr
    float grade;
    
public:

    //constructor
    Student(int _id = 0, string _name = "", int _age = 0, float _grade = 0.0): Person(_id, _name, _age) 
    {
        grade = _grade;
    }


    //destructor
    ~Student() {
        cout << "\nStudent destroyed\n";
    }

    //getter / setter 
    void setGrade(float _grade) { grade = _grade; }
    float getGrade() const { return grade; }

  
    //print
    void print() const {
        cout << "\n[Student]\n";
        Person::print();
        cout << ", Grade: " << grade << endl;
    }
    

};



int main(){

    Employee e1(1, "Ali", 30, 5000.0);
    Student s1(2, "Mona", 20, 95.5);


    e1.print();
    s1.print();
  
    return 0;

}

 



   