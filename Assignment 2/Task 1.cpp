#include<iostream>
using namespace std;

class Person{
protected:
    string name;
    int id;
    string contactNumber;

public:
    Person(string n,int i,string c) : name(n),id(i),contactNumber(c){}

    virtual void displayInfo() const{
        cout<<"Name: "<<name<<", ID: "<<id<<", Contact: "<<contactNumber<<endl;
    }

    virtual double calculateFee() const=0;
    virtual ~Person(){}
};

class Student : public Person{
    int semester;
    double feePerSemester;

public:
    Student(string n,int i,string c,int sem,double fee) : Person(n,i,c),semester(sem),feePerSemester(fee){}

    double calculateFee() const override{
        return feePerSemester;
    }

    void displayInfo() const override{
        Person::displayInfo();
        cout<<"Semester: "<<semester<<", Fee Per Semester: "<<feePerSemester<<endl;
    }
};

class Teacher : public Person{
    double salary;
    double feePerMonth;

public:
    Teacher(string n,int i,string c,double sal,double fee) : Person(n,i,c),salary(sal),feePerMonth(fee){}

    double calculateFee() const override{
        return feePerMonth;
    }

    void displayInfo() const override{
        Person::displayInfo();
        cout<<"Salary: "<<salary<<", Fee Per Month: "<< feePerMonth<<endl;
    }
};

class Staff : public Person{
    string designation;
    double feePerMonth;

public:
    Staff(string n,int i,string c,string desig,double fee) : Person(n,i,c),designation(desig),feePerMonth(fee){}

    double calculateFee() const override{
        return feePerMonth;
    }

    void displayInfo() const override{
        Person::displayInfo();
        cout<<"Designation: "<<designation<<", Fee Per Month: "<<feePerMonth<<endl;
    }
};

class Route{
public:
    int routeNumber;
    string startingPoint,endingPoint;

    Route(int r,string start,string end) : routeNumber(r),startingPoint(start),endingPoint(end){}

    bool operator==(const Route& other) const{
        return (routeNumber==other.routeNumber && startingPoint==other.startingPoint && endingPoint==other.endingPoint);
    }

    bool operator<(const Route& other) const{
        return routeNumber<other.routeNumber;
    }
};

class Bus{
    int busNumber;
    int capacity;

public:
    Bus(int num,int cap) : busNumber(num),capacity(cap){}

    void displayBusInfo() const{
        cout<<"Bus No: "<<busNumber<<", Capacity: "<<capacity<<endl;
    }
};

class TransportService{
    Bus bus;
    Route route;
    Person** users;
    int userCount;
    int capacity;

public:
    TransportService(int busNo,int cap,Route r) : bus(busNo,cap),route(r),userCount(0),capacity(cap){
        users=new Person*[capacity];
    }

    ~TransportService(){
        for(int i=0;i<userCount;i++){
            delete users[i];
        }
        delete[] users;
    }

    void addUser(Person* p){
        if(userCount<capacity){
            users[userCount++]=p;
            cout<<"User added successfully.\n";
        }
        else{
            cout<<"Transport full! Increasing capacity...\n";
            Person** temp=new Person*[capacity*2];
            for(int i=0;i<userCount;i++){
                temp[i]=users[i];
            }
            delete[] users;
            users=temp;
            capacity*=2;
            users[userCount++]=p;
            cout<<"User added after capacity expansion.\n";
        }
    }

    void displayDetails(){
        bus.displayBusInfo();
        cout<<"Route No: "<<route.routeNumber<<" ("<<route.startingPoint<<" -> "<<route.endingPoint<<")\n";
        cout<<"Total Users: "<<userCount<<"\n";

        for(int i=0;i<userCount;i++){
            users[i]->displayInfo();
            cout<<"Transport Fee: "<<users[i]->calculateFee()<<endl;
        }
    }
};

int main(){
    Person* s1=new Student("Ali",101,"03123456789",3,35000);
    Person* t1=new Teacher("Dr.Ahmed",201,"03001234567",15000,2000);
    Person* st1=new Staff("Mr.Raza",301,"03211223344","Admin",1500);

    Route r1(1,"Gulshan","FAST Karachi");
    Route r2(1,"Gulshan","FAST Karachi");
    Route r3(2,"Saddar","FAST Karachi");

    if(r1==r2){
        cout<<"Both routes are the same.\n";
    }
    else{
        cout<<"Routes are different.\n";
    }

    if(r1<r3){
        cout<<"Route 1 comes before Route 3 in sorting.\n";
    }

    TransportService ts(1234,2,r1);
    ts.addUser(s1);
    ts.addUser(t1);
    ts.addUser(st1);

    ts.displayDetails();
    return 0;
}
