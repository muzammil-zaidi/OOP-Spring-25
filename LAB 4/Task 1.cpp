#include<iostream>
#include<string>
using namespace std;

class Car{
    string brand;
    string model;
    float price;
    bool availability;

public:
    Car(){
        brand="Unknown";
        model="Generic";
        price=0.0;
        availability=true;
    }

    Car(string b,string m,float p,bool a){
        brand=b;
        model=m;
        price=p;
        availability=a;
    }

    void checkAvailability(){
        cout<< "\nChecking availability...\n";
        cout<<"------------------------"<<endl;
        if(availability){
            cout<<"Car is Available!"<<endl;
        }
        else{
            cout<<"Car is Unavailable!"<<endl;
        }
    }

    void rentCar(){
        cout<<"\nProcessing rental request...\n";
        cout<<"------------------------"<<endl;
        if(availability){
            availability=false;
            cout<<"Car has been rented successfully!"<<endl;
        }
        else{
            cout<<"Car is already rented!"<<endl;
        }
    }

    void setDetails(string b,string m,float p,bool a){
        brand=b;
        model=m;
        price=p;
        availability=a;
    }

    void display(){
        cout<< "\nDisplaying car details...\n";
        cout<<"------------------------"<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<< model<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Availability: ";
        if(availability){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
};

int main(){
    Car c;
    
    c.display();
    c.setDetails("Corolla","BA-23",232455.00,true);
    c.display();
    c.checkAvailability();
    c.rentCar();
    c.checkAvailability();
    
    return 0;
}
