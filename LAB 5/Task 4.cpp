#include<iostream>
#include<string>
using namespace std;

class AlarmSystem{
private:
    string securityLevel;

public:
    AlarmSystem(string level) : securityLevel(level){
        cout<<"Alarm System with security level '"<<securityLevel<<"' created."<<endl;
    }

    ~AlarmSystem(){
        cout<<"Alarm System destroyed.\n";
    }

    void display(){
        cout<<"Alarm System Security Level: "<<securityLevel<<endl;
    }
};

class SmartHome{
private:
    string homeName;
    AlarmSystem alarm;

public:
    SmartHome(string name,string securityLevel) : homeName(name),alarm(securityLevel){
        cout<<"SmartHome '"<<homeName<<"' created."<<endl;
    }

    ~SmartHome(){
        cout<<"SmartHome '"<<homeName<<"' destroyed."<<endl;
    }

    void displayDetails(){
        cout<<"SmartHome: "<<homeName<<endl;
        alarm.display();
        cout<<"------------------------------------\n";
    }
};

int main(){
    SmartHome h1("Apartment A1","High");
    h1.displayDetails();

    SmartHome h2("Apartment B2","Medium");
    h2.displayDetails();

    return 0;
}
