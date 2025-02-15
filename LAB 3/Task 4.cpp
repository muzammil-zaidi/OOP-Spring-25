#include<iostream>
#include<string>
using namespace std;

class Car{
    private:
        string brand;
        string model;
        float fuelCapacity;
        float currentFuelLevel;

    public:
        Car(string a,string b,float c){
            brand=a;
            model=b;
            fuelCapacity=c;
            currentFuelLevel=c;
        }

        void driveTheCar(float fuel){
            if(fuel>0 && fuel<=currentFuelLevel){
                currentFuelLevel-=fuel;
                cout<<"Fuel consumed: "<<fuel<<" liters.\n";
                if(currentFuelLevel<1){
                    cout<<"Warning! low fuel.\n";
                }
            }
            else{ 
                cout<<"Not enough fuel!\n";
            }
        }

        void refuelTank(float fuel){
            if(fuel>0 && (currentFuelLevel+fuel)<=fuelCapacity){
                currentFuelLevel+=fuel;
                cout<<"Refueled "<<fuel<<" liters.\n";
            }
            else{
                cout<<"Invalid refuel amount!.\n";
            }
        }

        void checkFuelStatus(){
            cout<<"Current fuel: "<<currentFuelLevel<<" liters.\n";
            cout<<"---------------------------\n";
        }
};

int main(){
    string brand,model;
    float capacity;
    
    cout<<"Enter car brand: ";
    cin>>brand;
    cout<<"Enter car model: ";
    cin>>model;
    cout<<"Enter fuel tank capacity (liters): ";
    cin>>capacity;

    Car c(brand,model,capacity);
    
    c.checkFuelStatus();
    c.driveTheCar(35);
    c.checkFuelStatus();
    c.driveTheCar(50);
    c.refuelTank(30);
    c.checkFuelStatus();
    
    return 0;
}
