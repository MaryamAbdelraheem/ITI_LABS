//class emp(id, name, age ,salary) print
#include <iostream>
#include <string>

using namespace std;

class emp{ 

    int id;
    char* name = nullptr; //dynamic allocation 
    int age;
    float salary;
public:
    //setters and getters
    //to set 
    void setID(int _id){
        if(_id >= 1000 && _id<=3000)
            id = _id;
        else{
            cout << "invalid value for id";
        }
    }
  
    //
    void setAge(int _age){ //_ convintial wec work with it
        if(_age >= 30 && _age<= 60)
            age = _age;
        else{
            cout << "invalid value for age";
        }
    }
     void setName(const char* _name){
        if(strlen(_name)>3){
            delete[] name;
            name = new char[strlen(_name)+1];
            strcpy(name, _name);
        }
            
        else{
            cout << "invalid value for name";
        }
    }
     void setSalary(int _salary){ 
        if(_salary >= 3000 && _salary<= 150000)
            salary = _salary;
        else{
            cout << "invalid value for salary";
        }
    }


      //to get
    int getID(){return id;}
    int getAge(){return age;}
    char* getName(){return name;}
    int getSalary(){return salary;}

    void print(){
        cout<< "========YOUR EMPLOYEE DATA: ========="<<endl;
        cout<<"ID:"<<id<<endl
        <<"NAME:"<<name<<endl
        <<"AGE:"<<age<<endl
        <<"SALARY:"<<salary<<endl;
    }

};

int main() {

    emp e1;
    e1.setID(1200);
    e1.setAge(45);
    e1.setName("Mohammed Mahmoud Ali");
    e1.setSalary(8000);

    e1.print();
  return 0;
}
