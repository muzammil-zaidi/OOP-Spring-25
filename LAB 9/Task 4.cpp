#include<iostream>
using namespace std;

class WeatherSensor{
public:
    virtual void readData()=0;
    virtual void displayReport()=0;
    virtual ~WeatherSensor(){}
};

class Thermometer : public WeatherSensor{
private:
    float temperature;
public:
    void readData() override{
        temperature=26.4;
    }

    void displayReport() override{
        cout<<"Thermometer: Temperature = "<<temperature<<"°C"<<endl;
    }
};

class Barometer : public WeatherSensor{
private:
    float pressure;
public:
    void readData() override{
        pressure=1012.8;
    }

    void displayReport() override{
        cout<<"Barometer: Atmospheric Pressure = "<<pressure<<" hPa"<<endl;
    }
};

int main(){
    const int n=2;
    WeatherSensor* sensors[n];

    sensors[0]=new Thermometer();
    sensors[1]=new Barometer();

    for(int i=0;i<n;i++){
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    for(int i=0;i<n;i++){
        delete sensors[i];
    }

    return 0;
}
