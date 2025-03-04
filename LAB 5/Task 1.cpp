#include<iostream>
#include<string>
using namespace std;

class Apartment{
private:
    int id;
    string address;
    char* ownerName;

public:
    Apartment(int i,string a,const char* owner) : id(i),address(a){
        ownerName=new char[strlen(owner)+1];
        strcpy(ownerName,owner);
    }

    Apartment(const Apartment& other) : id(other.id),address(other.address){
        ownerName=new char[strlen(other.ownerName)+1];
        strcpy(ownerName,other.ownerName);
        cout<<"Copy constructor called for apartment ID "<<id<<endl;
    }

    void display() const{
        cout<<"Apartment ID: "<<id<<endl;
		cout<<"Address: "<<address<<endl;
		cout<<"Owner: "<<ownerName<<endl;
		cout<<"--------------------------------"<<endl;
    }

    ~Apartment(){
        delete[] ownerName;
    }
};

int main(){
    Apartment a1(101,"123 Main Street","John");
    Apartment a2=a1;

    cout<<"Original Apartment Details:"<<endl;
    a1.display();
    
    cout<<"Copied Apartment Details:"<<endl;
    a2.display();
    
    return 0;
}
