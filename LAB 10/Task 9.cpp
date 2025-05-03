#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::ofstream outFile("large_log.txt");
    if(!outFile){
        std::cerr<<"Error: Could not create the file.\n";
        return 1;
    }

    outFile<<"This is the first part of the log.\n";
    outFile<<"This is the second part of the log.\n";
    outFile<<"And the third part.";
    outFile.close();

    std::ifstream inFile("large_log.txt");
    if(!inFile){
        std::cerr<<"Error: Could not open file for reading.\n";
        return 1;
    }

    std::string line;

    std::getline(inFile,line);

    std::getline(inFile,line);
    std::cout<<"Second Line: "<<line<<std::endl;

    inFile.close();
    return 0;
}
