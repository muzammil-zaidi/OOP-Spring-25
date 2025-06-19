#include<iostream>
using namespace std;

class Vehicle{
protected:
    int VehicleID;
    int speed;
    int capacity;
    int energyEfficiency;
    static int totalShipments;

public:
    Vehicle(int i,int s,int c,int e) : VehicleID(i),speed(s),capacity(c),energyEfficiency(e){
        totalShipments++;
    }

    ~Vehicle(){
        totalShipments--;
    }

    virtual void CalculateOptimalRoute(){
        cout<<"calculating optimal route for transport "<<VehicleID<<endl;
    }

    virtual void EstimatedDeliveryTime(double distance){
        double time=distance/speed;

        cout<<"Estimated arrival time for transport ID "<<VehicleID<<" is "<<time<<" hours"<<endl;
    }

    virtual void Command(string action,string packageId){
        cout<<"Vehicle with ID "<<VehicleID<<" executing command: "<<action<<" for package "<<packageId<<endl;
    }

    virtual void Command(string action,string packageId,string urgency){
        cout<<"Vehicle with ID "<<VehicleID<<" executing command: "<<action<<" for package "<<packageId<<" with urgency: "<<urgency<<endl;
    }

    friend bool operator==(const Vehicle &v1,const Vehicle &v2);

    virtual void Move()=0;
};

int Vehicle::totalShipments=0;

class RamzanDrone : public Vehicle{
public:
    RamzanDrone(int id,int spd,int cap,int eff) : Vehicle(id,spd,cap,eff){}

    void CalculateOptimalRoute() override{
        cout<<"Planning aerial course for AirBot ID: "<<VehicleID<<endl;
    }

    void Move() override{
        cout<<"Drone ID "<<VehicleID<<" is flying at speed "<<speed<<" km/h."<<endl;
    }

    void Command(string action,string packageId,string urgency) override{
        if(urgency=="Urgent"){
            speed=100;
            cout<<"Drone ID "<<VehicleID<<" is flying at speed "<<speed<<" km/h for urgent  iftar delivery of package "<<packageId<<endl;
        }
        else{
            cout<<"Drone ID "<<VehicleID<<" executing command: "<< action<<" for package "<<packageId<<" with urgency: "<<urgency<<endl;
        }
    }
};

class RamzamTimeShip : public Vehicle{
public:
    RamzamTimeShip(int i,int s,int c,int e) : Vehicle(i,s,c,e){}

    void CalculateOptimalRoute() override{
        cout<<"Calculating time-travel route for TimeShip ID: "<<VehicleID<<endl;
    }

    void Move() override{
        cout<<"TimeShip ID "<<VehicleID<<" is verifying historical consistency before proceeding. "<<endl;
    }

    void Command(string action,string packageId,string urgency) override{
        if(urgency=="Urgent"){
            cout<<"TimeShip ID "<<VehicleID<<" validating historical accuracy for package "<<packageId<<endl;
        }
        else{
            cout<<"TimeShip ID "<<VehicleID<<" is delivering package "<<packageId<<endl;
        }
    }
};

class RamzanHyperPod : public Vehicle{
public:
    RamzanHyperPod(int i,int s,int c,int e) : Vehicle(i,s,c,e){}

    void CalculateOptimalRoute() override{
        cout<<"Calculating underground route for HyperPod ID: "<<VehicleID<<endl;
    }

    void Move() override{
        cout<<"HyperPod ID "<<VehicleID<<" is moving at speed " << speed<<" km/h and is navigates an underground tunnel network for efficient bulk delivery."<<endl;
    }
};

bool operator==(const Vehicle &v1,const Vehicle &v2){
    return (v1.speed==v2.speed && v1.capacity==v2.capacity && v1.energyEfficiency==v2.energyEfficiency);
}

int main(){
    RamzanDrone d(1,70,6,12);
    RamzamTimeShip t(2,90,12,18);
    RamzanHyperPod h(3,110,25,22);

    d.CalculateOptimalRoute();
    t.CalculateOptimalRoute();
    h.CalculateOptimalRoute();

    d.EstimatedDeliveryTime(120);
    t.EstimatedDeliveryTime(200);
    h.EstimatedDeliveryTime(300);

    d.Move();
    t.Move();
    h.Move();

    d.Command("Transport","PKG005","Urgent");
    t.Command("Transport","PKG006","Normal");
    h.Command("Transport","PKG007","Urgent");

    return 0;
}
