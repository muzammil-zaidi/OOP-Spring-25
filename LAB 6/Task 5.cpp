#include<iostream>
using namespace std;

class Device{
protected:
    int deviceID;
    bool status;
public:
    Device(int id,bool s) : deviceID(id),status(s){}
    
    virtual void displayDetails(){
        cout<<"Device ID: "<<deviceID<<endl;
        if(status){
            cout<<"Status: ON"<<endl;
        }
        else{
            cout<<"Status: OFF"<<endl;
        }
    }
};

class SmartPhone : virtual public Device{
protected:
    float screenSize;
public:
    SmartPhone(int id, bool s,float size) : Device(id,s),screenSize(size){}
    
    void displayDetails() override{
        Device::displayDetails();
        cout<<"Screen Size: "<<screenSize<<" inches"<<endl;
    }
};

class SmartWatch : virtual public Device{
protected:
    bool heartRateMonitor;
public:
    SmartWatch(int id,bool s,bool hrm) : Device(id,s),heartRateMonitor(hrm){}
    
    void displayDetails() override{
        Device::displayDetails();
        if(heartRateMonitor){
            cout<<"Heart Rate Monitor: Yes"<<endl;
        }
        else{
            cout<<"Heart Rate Monitor: No"<<endl;
        }

    }
};

class SmartWearable : public SmartPhone,public SmartWatch{
private:
    int stepCounter;
public:
    SmartWearable(int id,bool s,float size,bool hrm,int steps)
        : Device(id,s),SmartPhone(id,s,size),SmartWatch(id,s,hrm),stepCounter(steps){}
    
    void displayDetails() override{
        Device::displayDetails();
        cout<<"Screen Size: "<<screenSize<<" inches"<<endl;
        if(heartRateMonitor){
            cout<<"Heart Rate Monitor: Yes"<<endl;
        }else{
            cout<<"Heart Rate Monitor: No"<<endl;
        }
        cout<<"Step Counter: "<<stepCounter<<" steps"<<endl;
    }
};

int main(){
    int id,steps;
    bool status,hrm;
    float size;
    
    cout<<"Enter Device ID: ";
    cin>>id;
    cout<<"Enter Status (1 for ON, 0 for OFF): ";
    cin>>status;
    cout<<"Enter Screen Size (in inches): ";
    cin>>size;
    cout<<"Does it have a Heart Rate Monitor? (1 for Yes, 0 for No): ";
    cin>>hrm;
    cout<<"Enter Step Counter Value: ";
    cin>>steps;
    
    SmartWearable s(id,status,size,hrm,steps);
    
    cout<<"\nSmart Wearable Details:\n";
    s.displayDetails();
    
    return 0;
}
