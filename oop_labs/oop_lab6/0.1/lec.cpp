//class employee
/*#include <iostream>
#include <string>

using namespace std;

class emp{ //class all private but struct no all public

    int id;
    char name[10]; //static allocation -- need to be fixied
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
     void setName(char* _name){
        if(strlen(_name)>3)
            strcpy(name, _name);
        else{
            cout << "invalid value for name";
        }
    }


      //to get
    int getID(){
        return id;
    }
    int getAge(){
        return age;
    }
    char* getName(){
        return name;
    }

    void print(){
        cout<<id<<" , "<<name<<" , "<<age<<" , "<<salary<<endl;
    }

};

int main() {

    emp e1;
  //e1.id=-1;//error because the private
    e1.setID(10);
    e1.setAge(45);

  //cout << e1.id;
    cout << e1.getID()<<endl;
    cout << e1.getAge();
    e1.print();
  return 0;
}
*/
///////////////////////////////////////////

//claa complex num
/*#include <iostream>
#include <string>

using namespace std;

class complexNum{ 

    int real;
    int img;

public:

    //set
    void setReal(int _real){
        real = _real;
    };

    void setImg(int _img){
        img = _img;
    }
    //get
    int getReal(){

    }
    int getImg(){

    }
    void print(){
        if(img>0)
            cout<<real<<"+"<<img<<"j";
        else if(img<0)
            cout<<real<<img<<"j";
        else
            cout<<real;
    }

  complexNum add(complexNum c){
    //real
    //img
  }
  //c1.add
};
//Complex add (Complex c) {
//Complex res;
//res.real=real+c.real; 
//res.img=img+c.img;
//return res;



int main() {

   
  return 0;
}

complexNum add(complexNum c1, complexNum c2){
    complexNum res;
    res.setReal(c1.getReal()+ c2.getReal());
    res.setImg(c1.getImg()+ c2.getImg());

    return res;
}*/


//call by refrence
