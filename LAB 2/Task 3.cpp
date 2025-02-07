#include<iostream>
#include<string>
using namespace std;

struct employee{
    string name;
    int hoursWorked;
    double hourlyRate;
};

int main(){
    int n;
    double salary;
    cout<<"Enter the number of employees: ";
    cin>>n;
    cin.ignore();
    employee* e=new employee[n];

    for(int i=0;i<n;i++){
        cout<<"\nEnter details for employee "<<i+1<<":\n";
        cout<<"Name: ";
        getline(cin,e[i].name);
        cout<<"Hours Worked: ";
        cin>>e[i].hoursWorked;
        cout<<"Hourly Rate: ";
        cin>>e[i].hourlyRate;
        cin.ignore();
    }

    cout<<"\nEmployee Salary Details:\n";
    for(int i=0;i<n;i++){
        salary=e[i].hoursWorked*e[i].hourlyRate;
        cout<<"Name: "<<e[i].name<<", Total Salary: $"<<salary<<"\n";
    }

    delete[] e;
    return 0;
}
