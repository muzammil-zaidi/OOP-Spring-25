#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::ofstream logFile("large_log.txt");
    if(!logFile){
        std::cerr<<"Error: Could not create log file."<<std::endl;
        return 1;
    }
    
    logFile<<"First line of the log file.\n";
    logFile<<"Second line of the log file.\n";
    logFile<<"Third line of the log file.\n";
    logFile<<"Fourth line of the log file.\n";
    logFile<<"Fifth line of the log file.\n";
    logFile.close();

    std::ifstream inFile("large_log.txt");
    if(!inFile){
        std::cerr<<"Error: Could not open the file for reading."<<std::endl;
        return 1;
    }

    char buffer[11];
    inFile.read(buffer,10);
    buffer[10]='\0';
    std::streampos p1=inFile.tellg();
    std::cout<<"Read first 10 characters: "<<buffer<<std::endl;
    std::cout<<"Position after first read: "<<p1<<std::endl;

    inFile.read(buffer,10);
    buffer[10]='\0';
    std::streampos p2=inFile.tellg();
    std::cout<<"Read next 10 characters: "<<buffer<<std::endl;
    std::cout<<"Position after second read: "<<p2<<std::endl;

    inFile.close();

    return 0;
}
