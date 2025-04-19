#include<iostream>
using namespace std;

class Shipment{
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string t,double w) : trackingNumber(t),weight(w){}
    virtual void estimateDeliveryTime()=0;
    virtual void showDetails()=0;
    virtual ~Shipment(){}
};

class AirFreight : public Shipment{
public:
    AirFreight(string t,double w) : Shipment(t,w){}

    void estimateDeliveryTime() override{
        cout<<"Air Freight: Estimated delivery time = "<<(weight*0.5)<<" hours"<<endl;
    }

    void showDetails() override{
        cout<<"Air Freight - Tracking#: "<<trackingNumber<<", Weight: "<<weight<<" kg"<<endl;
    }
};

class GroundShipment : public Shipment{
public:
    GroundShipment(string t,double w) : Shipment(t,w){}

    void estimateDeliveryTime() override{
        cout<<"Ground Shipment: Estimated delivery time = "<<(weight*1.5)<<" hours"<<endl;
    }

    void showDetails() override{
        cout<<"Ground Shipment - Tracking#: "<<trackingNumber<<", Weight: "<<weight<<" kg"<<endl;
    }
};

int main(){
    const int n=2;
    Shipment* shipments[n];

    shipments[0]=new AirFreight("AIR123",10.0);
    shipments[1]=new GroundShipment("GRND456",10.0);

    for(int i=0;i<n;i++){
        shipments[i]->showDetails();
        shipments[i]->estimateDeliveryTime();
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        delete shipments[i];
    }

    return 0;
}
