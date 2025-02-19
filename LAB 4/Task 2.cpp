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
        cout<<"\nChecking availability...\n";
        cout<< "------------------------"<<endl;
        if(availability){
            cout<<"Car is Available!"<<endl;
        }
        else{
            cout<<"Car is Unavailable!"<<endl;
        }
    }

    float applyDiscount(int days){
        float finalPrice=price*days;
        if(days>10){
            finalPrice*=0.90;
        } 
        else if(days>5){
            finalPrice*=0.95;
        }
        return finalPrice;
    }

    void rentCar(int days){
        cout<<"\nProcessing rental request...\n";
        cout<<"------------------------"<<endl;
        if(!availability){
            cout<<"Car is already rented!"<<endl;
            return;
        }
        
        float totalCost=applyDiscount(days);
        availability=false;

        cout<<"Car has been rented successfully for "<<days<<" days!"<<endl;
        cout<<"Total cost after discount: "<<totalCost<<endl;
    }

    void setDetails(string b,string m,float p,bool a){
        brand=b;
        model=m;
        price=p;
        availability=a;
    }

    void display(){
        cout<<"\nDisplaying car details...\n";
        cout<<"------------------------"<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Price per day: "<<price<<endl;
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
    c.setDetails("Corolla","BA-23",50.0,true);
    c.display();
    c.checkAvailability();
    cout<<"\nRenting the car for 7 days...\n";
    c.rentCar(7);
    c.checkAvailability();
    cout<<"\nTrying to rent the car again for 3 days...\n";
    c.rentCar(3);

    return 0;
}
