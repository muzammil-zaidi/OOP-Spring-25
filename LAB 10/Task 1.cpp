#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::ifstream vehicleFile;
    
    vehicleFile.open("vehicles.txt");
    
    if(!vehicleFile.is_open()){
        std::cerr<<"Error: Unable to open the file 'vehicles.txt'"<<std::endl;
        return 1;
    }
    
    std::cout<<"File opened successfully!"<<std::endl;
    
    std::string line;
    while(std::getline(vehicleFile, line)){
        if (line.empty() || line[0]=='#'){
            continue;
        }
        
        std::cout<<"Read line: "<<line<<std::endl;
    }
    
    vehicleFile.close();
    
    return 0;
}
