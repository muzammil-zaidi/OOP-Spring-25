#include <iostream>
using namespace std;

class Admin;

class BankAccount {
private:
    string accID;
    float accBalance;

public:
    BankAccount(string id, float balance) {
        accID = id;
        accBalance = balance;
    }

    friend class Admin;
    friend void transferFunds(BankAccount &sender, BankAccount &receiver, float amount);
};

void transferFunds(BankAccount &sender, BankAccount &receiver, float amount) {
    if (sender.accBalance >= amount) {
        sender.accBalance -= amount;
        receiver.accBalance += amount;
        cout<<"Successfully transferred Rs."<<amount<<" from "<<sender.accID<<" to "<<receiver.accID<<"."<<endl;
    } else {
        cout<<"Transfer failed due to insufficient balance in "<<sender.accID<<"."<<endl;
    }
}

class Admin {
public:
    void showInfo(const BankAccount &acc) {
        cout<<"ID: "<<acc.accID<<endl;
        cout<<"Current Balance: Rs."<<acc.accBalance<<endl;
    }

    void addMoney(BankAccount &acc, float cash) {
        acc.accBalance += cash;
        cout<<"Added Rs."<<cash<<" to "<<acc.accID<<"."<<endl;
    }

    void takeMoney(BankAccount &acc, float cash) {
        if (acc.accBalance >= cash) {
            acc.accBalance -= cash;
            cout<<"Withdrew Rs."<<cash<<" from "<<acc.accID<<"."<<endl;
        } else {
            cout<<"Withdrawal failed due to insufficient funds in "<<acc.accID<<"."<<endl;
        }
    }
};

int main() {
    BankAccount userA("A102", 8500);
    BankAccount userB("B203", 3600);

    Admin control;

    cout<<"--- Starting Details ---"<<endl;
    control.showInfo(userA);
    control.showInfo(userB);
    cout<<endl;

    control.addMoney(userB, 900);
    control.takeMoney(userA, 1200);
    cout<<endl;

    cout<<"--- After Updates ---"<<endl;
    control.showInfo(userA);
    control.showInfo(userB);
    cout<<endl;

    transferFunds(userB, userA, 2500);
    cout<<endl;

    cout<<"--- Final Summary ---"<<endl;
    control.showInfo(userA);
    control.showInfo(userB);

    return 0;
}
