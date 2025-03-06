#include<iostream>
using namespace std;

class Employee{
protected:
    string name;
    float salary;
public:
    Employee(string n,float s) : name(n),salary(s){}
    
    virtual void displayDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: $"<<salary<<endl;
    }
};

class Manager : public Employee{
private:
    float bonus;
public:
    Manager(string n,float s,float b) : Employee(n,s),bonus(b){}
    
    void displayDetails() override{
        Employee::displayDetails();
        cout<<"Bonus: $"<<bonus<<endl;
    }
};

int main(){
    string name;
    float salary,bonus;
    
    cout<<"Enter Manager's Name: ";
    getline(cin,name);
    cout<<"Enter Salary: $";
    cin>>salary;
    cout<<"Enter Bonus: $";
    cin>>bonus;
    
    Manager m(name,salary,bonus);
    
    cout<<"\nManager Details:"<<endl;
    m.displayDetails();
    
    return 0;
}
