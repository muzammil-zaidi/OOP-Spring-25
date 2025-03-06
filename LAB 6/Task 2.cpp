#include<iostream>
using namespace std;

class Vehicle{
protected:
    string brand;
    int speed;
public:
    Vehicle(string a,int b) : brand(a),speed(b){}
    
    virtual void displayDetails(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<" km/h"<<endl;
    }
};

class Car : public Vehicle{
protected:
    int seats;
public:
    Car(string a,int b,int c) : Vehicle(a,b),seats(c){}
    
    void displayDetails() override{
        Vehicle::displayDetails();
        cout<<"Seats: "<<seats<<endl;
    }
};

class ElectricCar : public Car{
private:
    int batteryLife;
public:
    ElectricCar(string a,int b,int c,int d) : Car(a,b,c),batteryLife(d){}
    
    void displayDetails() override{
        Car::displayDetails();
        cout<<"Battery Life: "<<batteryLife<<" hours"<<endl;
    }
};

int main(){
    string brand;
    int speed,seats,batteryLife;
    
    cout<<"Enter Electric Car Brand: ";
    getline(cin, brand);
    cout<<"Enter Speed (km/h): ";
    cin>>speed;
    cout<<"Enter Seating Capacity: ";
    cin>>seats;
    cout<<"Enter Battery Life (hours): ";
    cin>>batteryLife;
    
    ElectricCar e(brand,speed,seats,batteryLife);
    
    cout<<"\nElectric Car Details:"<<endl;
    e.displayDetails();
    
    return 0;
}
