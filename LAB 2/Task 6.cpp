#include<iostream>
#include<string>
using namespace std;

struct student{
    string name;
    int rollNumber;
    double marks[3];
};

int main(){
    int n;
    double average;
    cout<<"Enter the number of students: ";
    cin>>n;
    cin.ignore();
    student* s=new student[n];

    for(int i=0;i<n;i++){
        cout<<"\nEnter details for student "<<i+1<<":\n";
        cout<<"Name: ";
        getline(cin,s[i].name);
        cout<<"Roll Number: ";
        cin>>s[i].rollNumber;
        cout<<"Enter marks for 3 subjects: ";
        for(int j=0;j<3;j++){
            cin>>s[i].marks[j];
        }
        cin.ignore();
    }

    cout<<"\nStudent Records:\n";
    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<3;j++){
            sum+=s[i].marks[j];
        }
        average=sum/3.0;
        cout<<"Name: "<<s[i].name<<", Roll Number: "<<s[i].rollNumber<<", Average Marks: "<<average<<"\n";
    }

    delete[] s;
    return 0;
}
