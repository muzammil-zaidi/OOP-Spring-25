#include<iostream>
#include<string>
using namespace std;

class Car{
    string brand;
    string model;
    float price;
    bool availability;
    float revenue;
    string carID;

public:
    Car(){
        brand="Unknown";
        model="Generic";
        price=0.0;
        availability=true;
        revenue=0.0;
        carID="0000";
    }

    Car(string b,string m,float p,bool a,string id){
        brand=b;
        model=m;
        price=p;
        availability=a;
        revenue=0.0;
        carID=id;
    }

    Car(const Car &other){
        cout<<"\nCopying car details...\n";
        cout<<"------------------------"<<endl;
        brand=other.brand;
        model=other.model;
        price=other.price;
        availability=other.availability;
        revenue=other.revenue;
        carID=other.carID;
    }

    ~Car(){
        cout<<"Car object ("<<brand<<" "<<model<<") is being destroyed.\n";
    }

    void checkAvailability(){
        cout<<"\nChecking availability...\n";
        cout<<"------------------------"<<endl;
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

    void rentCar(int days) {
        cout<<"\nProcessing rental request...\n";
        cout<<"------------------------"<<endl;
        if(!availability){
            cout<<"Car is already rented!"<<endl;
            return;
        }

        float totalCost=applyDiscount(days);
        revenue+=totalCost;
        availability=false;

        cout<<"Car has been rented successfully for "<<days<<" days!"<<endl;
        cout<<"Total cost after discount: "<<totalCost<<endl;
    }

    void displayRevenue(){
        cout<<"\nTotal revenue generated by "<<brand<<" "<<model<<" ("<<carID<<"): "<<revenue<<endl;
    }

    void setDetails(string b,string m,float p,bool a,string id){
        brand=b;
        model=m;
        price=p;
        availability=a;
        revenue=0.0;
        carID=id;
    }

    void display(){
        cout<<"\nDisplaying car details...\n";
        cout<< "------------------------"<<endl;
        cout<<"Car ID: "<<carID<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Price per day: "<<price<<endl;
        cout<<"Availability: ";
        if(availability){
            cout<<"Car is Available!"<<endl;
        }
        else{
            cout<<"Car is Unavailable!"<<endl;
        }
        cout<<"Total Revenue: "<<revenue<<endl;
    }
};

int main(){
    Car original("Corolla","BA-23",50,true,"C1234");
    original.display();

    Car copiedCar=original;
    copiedCar.display();

    cout<<"\nRenting the original car for 7 days...\n";
    original.rentCar(7);
    original.displayRevenue();

    original.setDetails("Honda","Civic",100,true,"H5678");
    cout<<"\nAfter modifying the original car:\n";
    original.display();

    cout<<"\nVerifying copied car details remain unchanged:\n";
    copiedCar.display();

    return 0;
}
