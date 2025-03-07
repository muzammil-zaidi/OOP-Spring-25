#include<iostream>
using namespace std;

class Account{
protected:
    int accountNumber;
    float balance;

public:
    Account(int a,float b) : accountNumber(a),balance(b){}

    virtual void displayDetails(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: $"<<balance<<endl;
    }
};

class SavingsAccount : public Account{
private:
    float interestRate;

public:
    SavingsAccount(int a,float b,float i) : Account(a,b),interestRate(i){}

    void displayDetails() override{
        Account::displayDetails();
        cout<<"Interest Rate: "<<interestRate<< "%"<<endl;
    }
};

class CheckingAccount : public Account{
private:
    float overdraftLimit;

public:
    CheckingAccount(int a,float b,float l) 
        : Account(a,b),overdraftLimit(l){}

    void displayDetails() override{
        Account::displayDetails();
        cout<<"Overdraft Limit: $"<<overdraftLimit<<endl;
    }
};

int main(){
    int a;
    float b,i,l;

    cout<<"Enter Savings Account Number: ";
    cin>>a;
    cout<<"Enter Balance: $";
    cin>>b;
    cout<<"Enter Interest Rate (%): ";
    cin>>i;

    SavingsAccount s(a,b,i);

    cout<<"\nEnter Checking Account Number: ";
    cin>>a;
    cout<<"Enter Balance: $";
    cin>>b;
    cout<<"Enter Overdraft Limit: $";
    cin>>l;

    CheckingAccount c(a,b,l);

    cout<<"\nSavings Account Details:\n";
    s.displayDetails();

    cout<<"\nChecking Account Details:\n";
    c.displayDetails();

    return 0;
}
