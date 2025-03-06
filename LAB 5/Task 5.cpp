#include<iostream>
#include<string>
using namespace std;

class Doctor{
private:
    string name;
    string specialization;
    int experience;

public:
    Doctor(string n,string s,int e) : name(n),specialization(s),experience(e){}

    void display(){
        cout<<"Doctor: "<<name<<endl;
        cout<<"Specialization: "<<specialization<<endl;
        cout<<"Experience: "<<experience<<" years"<<endl;
        cout<<"--------------------------------"<<endl;
    }
};

class Hospital{
private:
    string hospitalName;
    Doctor** doctors;
    int doctorCount;
    int capacity;

public:
    Hospital(string name,int maxDoctors) : hospitalName(name),doctorCount(0),capacity(maxDoctors){
        doctors=new Doctor*[capacity];
    }

    ~Hospital(){
        for(int i=0;i<doctorCount;i++){
            delete doctors[i];
        }
        delete[] doctors;
        cout<<"Hospital '"<<hospitalName<<"' destroyed.\n";
    }

    bool addDoctor(string name,string specialization,int experience){
        if(doctorCount<capacity){
            doctors[doctorCount++]=new Doctor(name,specialization,experience);
            return true;
        }
        else{
            cout<<"Hospital '"<<hospitalName<<"' is at full capacity!\n";
            return false;
        }
    }

    void displayDetails(){
        cout<<"Hospital: "<<hospitalName<<endl;
        cout<<"Doctors currently working:\n";
        cout<<"--------------------------------"<<endl;
        if(doctorCount==0){
            cout<<"No doctors assigned yet.\n";
        }
        else{
            for(int i=0;i<doctorCount;i++){
                doctors[i]->display();
            }
        }
    }
};

int main(){
    Hospital h("City Hospital",3);
    
    h.addDoctor("Dr.Sarim","Cardiology",15);
    h.addDoctor("Dr.John","Neurology",7);
    h.addDoctor("Dr.Emaan","Pediatrics",3);
    
    h.displayDetails();

    return 0;
}
