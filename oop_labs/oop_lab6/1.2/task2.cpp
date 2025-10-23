//class bank(id name,balance) => getters, setters 
#include <iostream>
#include <string>

using namespace std;

class Bank{ 

    int id;
    string name; 
    //string name;
    float balance;
public:
    
    //setters and getters
    //to set 
    void setID(int _id){
        if(_id > 0)
            id = _id;
        else{
            cout << "invalid value for id";
        }
    }
  
    
    void setName(const string& _name) {  
        if (_name.length() >= 3)
            name = _name;
        else
            cout << "Invalid Name\n";
    }
    void setBalance(float _balance) {
        if (_balance >= 0)
            balance = _balance;
        else
            cout << "Invalid Balance\n";
    }


      //to get
    int getID(){
        return id;
    }
    string getName(){
        return name;
    }
    float getBalance() {
        return balance;
    }

    //member functions
    // print:
    void print() {
        cout << "Account Info:\n";
        cout << "ID: " << id<<endl
             << "Name: " << name<<endl
             << "Balance: " << balance << endl;
    }
    //withdraw:
    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        }
        else if (amount > balance) 
            cout << "Insufficient balance\n";
        else 
            cout << "Invalid withdraw amount\n";
        
    }
    //deposit:
    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount\n";
        }
    }
};

int main() {

    Bank b1;

    b1.setID(1001);
    b1.setName("Alii");
    b1.setBalance(2500.75);
    //before
    b1.print();
    cout<<"======================"<<endl;
    b1.deposit(1000);
    b1.withdraw(550.50);
    //after
    b1.print();

  return 0;
}
