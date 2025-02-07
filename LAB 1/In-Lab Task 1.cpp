#include<iostream>
#include<string>
using namespace std;

int main(){
    string event1[5],event2[5];
    int n1,n2;
    
    do{
        cout<<"Enter the number of participants for Event 1 (max 5): ";
        cin>>n1;
        if(n1<1 || n1>5){
            cout<<"Invalid input! Please enter a number between 1 and 5.\n";
        }
    }
	while(n1<1 || n1>5);
    cin.ignore();
    cout<<"Participants for Event 1:\n";
    for(int i=0;i<n1;i++){
        cout<<"Enter Name for Participant "<<i+1<<": ";
        getline(cin,event1[i]);
    }

    do{
        cout<<"Enter the number of participants for Event 2 (max 5): ";
        cin>>n2;
        if(n2<1 || n2>5){
            cout<<"Invalid input! Please enter a number between 1 and 5.\n";
        }
    }
	while(n2<1 || n2>5);

    cin.ignore();
    cout<<"Participants for Event 2:\n";
    for(int i=0;i<n2;i++){
        cout<<"Enter Name for Participant "<<i+1<<": ";
        getline(cin,event2[i]);
    }

    cout<<"\nEvent 1 participants:\n";
    for(int i=0;i<n1;i++){
        cout<<event1[i]<<endl;
    }

    cout<<"\nEvent 2 participants:\n";
    for (int i=0;i<n2;i++){
        cout<<event2[i]<<endl;
    }

    return 0;
}
