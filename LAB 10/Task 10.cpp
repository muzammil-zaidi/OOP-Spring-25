#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::ofstream outFile("data_records.txt");
    if(!outFile){
        std::cerr<<"Error: Could not create the file."<<std::endl;
        return 1;
    }

    outFile<<"Record 1\n";
    outFile<<"Record 2\n";
    outFile<<"Record 3\n";
    outFile<<"Record 4\n";
    outFile.close();

    std::ifstream inFile("data_records.txt");
    if(!inFile){
        std::cerr<<"Error: Could not open the file for reading."<<std::endl;
        return 1;
    }

    std::string line;
    std::getline(inFile,line);
    std::getline(inFile,line);

    std::getline(inFile,line);
    std::cout<<"Third Record: "<<line<<std::endl;

    inFile.close();

    return 0;
}
