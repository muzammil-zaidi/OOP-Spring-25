#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::ofstream initFile("config.txt");
    if(!initFile){
        std::cerr<<"Error: Could not create file.\n";
        return 1;
    }

    initFile<<"AAAAA"<<"BBBBB"<<"CCCCC";
    initFile.close();

    std::fstream configFile("config.txt",std::ios::in | std::ios::out);
    if(!configFile){
        std::cerr<<"Error: Could not open file for update.\n";
        return 1;
    }

    configFile.seekp(5);
    configFile<<"ZZZZZ";
    configFile.close();

    std::ifstream readFile("config.txt");
    if(!readFile){
        std::cerr<<"Error: Could not open file for reading.\n";
        return 1;
    }

    std::string contents;
    readFile>>contents;
    readFile.close();

    std::cout<<"Updated File Contents: "<<contents<<std::endl;

    return 0;
}
