#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

int main(){
    std::ifstream vehicleFile("vehicles.txt");

    if(!vehicleFile.is_open()){
        std::cerr<<"Error: Unable to open the file 'vehicles.txt'"<<std::endl;
        return 1;
    }

    std::string line;

    while(std::getline(vehicleFile,line)){
        if(line.empty() || line[0]=='#'){
            continue;
        }

        std::istringstream lineStream(line);
        std::string type,id,name,yearStr,extraData,certification;

        std::getline(lineStream,type,',');
        std::getline(lineStream,id,',');
        std::getline(lineStream,name,',');
        std::getline(lineStream,yearStr,',');
        std::getline(lineStream,extraData,',');
        std::getline(lineStream,certification);

        int year=std::stoi(yearStr);

        std::cout<<"Type: "<<type<<std::endl;
        std::cout<<"ID: "<<id<<std::endl;
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"Year: "<<year<<" (int)"<<std::endl;
        std::cout<<"Extra Data: "<<extraData<<std::endl;
        std::cout<<"Certification: "<<certification<<std::endl;
        std::cout<<"----------------------------------------"<<std::endl;
    }

    vehicleFile.close();
    return 0;
}
