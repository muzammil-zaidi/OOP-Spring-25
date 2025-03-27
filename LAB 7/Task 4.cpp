#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n,int a,string c,string addr="") : name(n),age(a),contactNumber(c),address(addr){}

    virtual void displayInfo(){
        cout<<"Name: "<<name<<", Age: "<<age<<", Contact: "<<contactNumber;
        if(!address.empty()){
            cout<<", Address: "<<address;
        }
        cout<<endl;
    }

    virtual void updateInfo(string newContact){
        contactNumber=newContact;
        cout<<"Contact updated successfully.\n";
    }
};

class Patient : public Person{
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n,int a,string c,int id,string history,string doctor) : Person(n,a,c),patientID(id),medicalHistory(history),doctorAssigned(doctor){}

    void displayInfo() override{
        cout<<"Patient ID: "<<patientID<<", ";
        Person::displayInfo();
        cout<<"Medical History: "<<medicalHistory<<", Assigned Doctor: "<<doctorAssigned<<endl;
    }
};

class Doctor : public Person{
    string specialization;
    double consultationFee;
    int maxPatients;
    string patientsList[10];
    int patientCount;

public:
    Doctor(string n,int a,string c,string spec,double fee,int maxP) : Person(n,a,c),specialization(spec),consultationFee(fee),maxPatients(maxP),patientCount(0){}

    void addPatient(string patientName){
        if(patientCount<maxPatients){
            patientsList[patientCount++]=patientName;
        }
        else{
            cout<<"Doctor's patient list is full.\n";
        }
    }

    void displayInfo() override{
        cout<<"Doctor: ";
        Person::displayInfo();
        cout<<"Specialization: "<<specialization<<", Fee: $"<<consultationFee<<"\nPatients: ";
        for(int i=0;i<patientCount;i++){
            cout<<patientsList[i];
            if(i<patientCount-1){
                cout<<", ";
            }
            else{
                cout<<"";
            }
        }
        cout<<endl;
    }
};

class Nurse : public Person{
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n,int a,string c,string ward,string shift) : Person(n,a,c),assignedWard(ward),shiftTimings(shift){}

    void displayInfo() override{
        cout<<"Nurse: ";
        Person::displayInfo();
        cout<<"Assigned Ward: "<<assignedWard<<", Shift: "<<shiftTimings<<endl;
    }
};

class Administrator : public Person{
    string department;
    double salary;

public:
    Administrator(string n,int a,string c,string dept,double sal) : Person(n,a,c),department(dept),salary(sal){}

    void updateInfo(double newSalary){
        salary=newSalary;
        cout<<"Administrator salary updated successfully.\n";
    }

    void displayInfo() override{
        cout<<"Administrator: ";
        Person::displayInfo();
        cout<<"Department: "<<department<<", Salary: $"<<salary<<endl;
    }
};

int main(){
    Patient p("Alice",30,"123456789",101,"Diabetes","Dr. Smith");
    Doctor d("Dr. Smith",45,"987654321","Cardiology",150.0,5);
    Nurse n("Nina",28,"1122334455","ICU","Night");
    Administrator a("Bob",50,"5566778899","HR",75000.0);

    d.addPatient("Alice");

    cout<<"\n--- Hospital Management System ---\n";
    p.displayInfo();
    d.displayInfo();
    n.displayInfo();
    a.displayInfo();

    cout<<"\nUpdating Contact Information...\n";
    p.updateInfo("111222333");
    p.displayInfo();

    cout<<"\nUpdating Administrator Salary...\n";
    a.updateInfo(80000.0);
    a.displayInfo();

    return 0;
}
