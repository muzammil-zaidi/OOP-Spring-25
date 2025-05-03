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

    while(std::getline(vehicleFile, line)){
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

        if(type == "AutonomousCar"){
            size_t colonPos=extraData.find(':');
            if(colonPos!=std::string::npos){
                std::string valueStr=extraData.substr(colonPos+1);
                float softwareVersion=std::stof(valueStr);
                std::cout<<"Software Version (float): "<<softwareVersion<<" (from ID: "<<id<<")"<<std::endl;
            }
        }
        else if(type=="ElectricVehicle"){
            size_t colonPos=extraData.find(':');
            if(colonPos!=std::string::npos){
                std::string valueStr=extraData.substr(colonPos+1);
                int batteryCapacity=std::stoi(valueStr);
                std::cout<<"Battery Capacity (int): "<<batteryCapacity<<" (from ID: "<<id<<")"<<std::endl;
            }
        }
        else if(type=="HybridTruck"){
            size_t colonPos=extraData.find(':');
            size_t pipePos=extraData.find('|');
            size_t batteryPos=extraData.find("Battery:");

            if(colonPos!=std::string::npos && pipePos!=std::string::npos && batteryPos!=std::string::npos){
                std::string cargoStr=extraData.substr(colonPos+1,pipePos-colonPos-1);
                std::string batteryStr=extraData.substr(batteryPos+8);

                int cargo=std::stoi(cargoStr);
                int battery=std::stoi(batteryStr);

                std::cout<<"Cargo Capacity (int): "<<cargo<<" (from ID: "<<id<<")"<<std::endl;
                std::cout<<"Battery Capacity (int): "<<battery<<" (from ID: "<<id<<")"<<std::endl;
            }
			else{
                std::cout<<"Error: Invalid ExtraData format for HybridTruck (ID: "<<id<<")"<<std::endl;
            }
        }
        else{
            std::cout<<"Unknown vehicle type: "<<type<<" (ID: "<<id<<")"<<std::endl;
        }

        std::cout<<"----------------------------------------"<<std::endl;
    }

    vehicleFile.close();
    return 0;
}
