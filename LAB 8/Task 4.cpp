#include <iostream>
#include <string>
using namespace std;

class Vehicle;

class InventoryHandler {
public:
    void setPrice(Vehicle& v, double newCost);
    void showDetails(const Vehicle& v);
};

class Vehicle {
private:
    string name;
    double cost;

public:
    Vehicle(string n = "", double c = 0.0) {
        name = n;
        cost = c;
    }

    friend class InventoryHandler;
    friend void compareCost(const Vehicle& v1, const Vehicle& v2);
};

void InventoryHandler::setPrice(Vehicle& v, double newCost) {
    v.cost = newCost;
}

void InventoryHandler::showDetails(const Vehicle& v) {
    cout<<"Car:"<<v.name<<",Price:$"<<v.cost<<endl;
}

void compareCost(const Vehicle& v1, const Vehicle& v2) {
    if (v1.cost > v2.cost) {
        cout<<v1.name<<" costs more than "<<v2.name<<"."<<endl;
    } else if (v1.cost < v2.cost) {
        cout<<v2.name<<" costs more than "<<v1.name<<"."<<endl;
    } else {
        cout<<"Prices of both vehicles are identical."<<endl;
    }
}

int main() {
    InventoryHandler handler;

    Vehicle v1("Kia Sportage", 42000);
    Vehicle v2("Hyundai Tucson", 41000);

    cout<<"--- Vehicle Records ---"<<endl;
    handler.showDetails(v1);
    handler.showDetails(v2);

    handler.setPrice(v2, 43000); // Updating price

    cout<<"\n--- Updated Records ---"<<endl;
    handler.showDetails(v1);
    handler.showDetails(v2);

    cout<<"\n--- Price Check ---"<<endl;
    compareCost(v1, v2);

    return 0;
}
