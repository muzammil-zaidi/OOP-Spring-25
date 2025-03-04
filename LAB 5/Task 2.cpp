#include<iostream>
#include<string>
using namespace std;

class Student{
private:
    int id;
    char* name;
    int* scores;
    int numScores;

public:
    Student(int id,const char* name,int scores[],int numScores) : id(id),numScores(numScores){
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        
        this->scores=new int[numScores];
        for(int i=0;i<numScores;i++){
            this->scores[i]=scores[i];
        }
    }

    Student(const Student& other) : id(other.id),numScores(other.numScores){
        name=new char[strlen(other.name)+1];
        strcpy(name,other.name);
        
        scores=new int[numScores];
        for(int i=0;i<numScores;i++){
            scores[i]=other.scores[i];
        }
        
        cout<<"Copy constructor called for student ID "<<id<<endl;
    }

    void display() const{
        cout<<"Student ID: "<<id<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Scores: "<<endl;
        for(int i=0;i<numScores;i++){
            cout<<scores[i]<<" ";
        }
        cout<<"\n------------------------------"<<endl;
    }

    ~Student(){
        delete[] name;
        delete[] scores;
    }
};

int main(){
    int scores[]={85,90,78};
    Student s1(101,"Ali",scores,3);
    Student s2=s1;

    cout<<"Original Student Details:"<<endl;
    s1.display();
    
    cout<<"Copied Student Details:"<<endl;
    s2.display();
    
    return 0;
}
