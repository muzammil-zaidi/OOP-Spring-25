#include<iostream>
#include<string>
using namespace std;

class Device{
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id,string name,string loc="Unknown") : deviceID(id),deviceName(name),status(false),location(loc){}

    virtual void turnOn(){
        status=true;
        cout<<deviceName<<" is now ON."<<endl;
    }

    virtual void turnOff(){
        status=false;
        cout<<deviceName<<" is now OFF."<<endl;
    }

    virtual void getStatus() const{
        if(status){
            cout<<deviceName<<" Status: ON"<<endl;
        }
        else{
            cout<<deviceName<<" Status: OFF"<<endl;
        }
    }

    virtual void displayInfo() const{
        cout<<"Device ID: "<<deviceID<<"\n";
        cout<<"Device Name: "<<deviceName<<"\n";
        cout<<"Location: "<<location<<"\n";
        if(status){
            cout<<"Status: ON"<<endl;
        }
        else{
            cout<<"Status: OFF"<<endl;
        }
    }
    virtual ~Device(){}
};

class Light : public Device{
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id,string name,string loc,int brightness,string color) : Device(id,name,loc),brightnessLevel(brightness),colorMode(color){}

    void displayInfo() const override{
        Device::displayInfo();
        cout<<"Brightness Level: "<<brightnessLevel<<"\n";
        cout<<"Color Mode: "<<colorMode<<endl;
    }
};

class Thermostat : public Device{
private:
    float currentTemperature;
    float targetTemperature;
    string mode;

public:
    Thermostat(int id,string name,string loc,float targetTemp,string modeType) : Device(id,name,loc),targetTemperature(targetTemp),mode(modeType),currentTemperature(25.0){}

    void getStatus() const override{
        cout<<deviceName<<" Mode: "<<mode<<"\n";
        cout<<"Current Temperature: "<<currentTemperature<<"°C\n";
        cout<<"Target Temperature: "<<targetTemperature<<"°C"<<endl;
    }
};

class SecurityCamera : public Device{
private:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id,string name,string loc,int res,bool nightVision) : Device(id,name,loc),resolution(res),nightVisionEnabled(nightVision),recordingStatus(false){}

    void turnOn() override{
        status=true;
        recordingStatus=true;
        cout<<deviceName<<" is now ON and recording started."<<endl;
    }

    void displayInfo() const override{
        Device::displayInfo();
        cout<<"Resolution: "<<resolution<<"p\n";
        if(nightVisionEnabled){
            cout<<"Night Vision: Enabled"<<"\n";
        }
        else{
            cout<<"Night Vision: Disabled"<<"\n";
        }
        if(recordingStatus){
            cout<<"Recording Status: Recording"<<endl;
        }
        else{
            cout<<"Recording Status: Not Recording"<<endl;
        }
    }
};

class SmartPlug : public Device{
private:
    int powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id,string name,string loc,int power,int timer) : Device(id,name,loc),powerConsumption(power),timerSetting(timer){}

    void turnOff() override{
        cout<< deviceName<<" is now OFF. Power usage logged: "<<powerConsumption<<"W."<<endl;
        status=false;
    }

    void displayInfo() const override{
        Device::displayInfo();
        cout<<"Power Consumption: "<<powerConsumption<<"W\n";
        cout<<"Timer Setting: "<<timerSetting<<" mins"<<endl;
    }
};

int main(){
    Light l(101,"Living Room Light","Living Room",75,"Warm White");
    Thermostat t(102,"Home Thermostat","Hallway",22.5,"Cooling");
    SecurityCamera c(103,"Front Door Camera","Entrance",1080,true);
    SmartPlug p(104,"Coffee Maker Plug","Kitchen",1500,30);

    cout<<"\n--- Smart Home Automation System ---\n"<<endl;

    l.turnOn();
    l.displayInfo();
    cout<<"\n";
    t.getStatus();
    cout<<"\n";
    c.turnOn();
    c.displayInfo();
    cout<<"\n";
    p.turnOn();
    p.turnOff();

    return 0;
}
