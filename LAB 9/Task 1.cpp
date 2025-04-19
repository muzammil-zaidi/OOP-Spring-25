#include<iostream>
using namespace std;

class Patient{
protected:
    string name;
    string id;
public:
    Patient(string n,string i) : name(n),id(i){}
    virtual void displayTreatment() const=0;
    virtual double calculateCost() const=0;
    virtual ~Patient(){}
};

class InPatient : public Patient{
public:
    InPatient(string n,string i) : Patient(n,i){}
    void displayTreatment() const override{
        cout<<"InPatient Treatment for "<<name<<" (ID: "<<id<<"):"<<endl;
        cout<<"- Surgery\n- Hospital Stay\n- Medication\n";
    }
    double calculateCost() const override{
        return 15000.0;
    }
};

class OutPatient : public Patient{
public:
    OutPatient(string n,string i) : Patient(n,i){}
    void displayTreatment() const override{
        cout<<"OutPatient Treatment for "<<name<<" (ID: "<<id<<"):"<<endl;
        cout<<"- Consultation\n- Diagnostic Tests\n- Prescription\n";
    }
    double calculateCost() const override{
        return 2000.0;
    }
};

int main(){
    const int n=2;
    Patient* patients[n];

    patients[0]=new InPatient("Alice","IP001");
    patients[1]=new OutPatient("Bob","OP001");

    for(int i=0;i<n;i++){
        patients[i]->displayTreatment();
        cout<<"Total Cost: $"<<patients[i]->calculateCost()<<"\n\n";
    }

    for(int i=0;i<n;i++){
        delete patients[i];
    }

    return 0;
}
