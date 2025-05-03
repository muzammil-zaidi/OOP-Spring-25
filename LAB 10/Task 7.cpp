#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::ofstream outFile("sensor_log.txt");

    if(!outFile){
        std::cerr<<"Error: Could not open file for writing.\n";
        return 1;
    }

    outFile<<"Sensor 1: 23.5 C\n";
    std::streampos p1=outFile.tellp();
    std::cout<<"Position after first write: "<<p1<<std::endl;

    outFile<<"Sensor 2: 98.1 %RH\n";
    std::streampos p2=outFile.tellp();
    std::cout<<"Position after second write: "<<p2<<std::endl;

    outFile.close();
    return 0;
}
