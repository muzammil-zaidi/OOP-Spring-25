#include<iostream>
#include<string>
using namespace std;

void Participants(string event,string participants[],int &n){
    do{
        cout<<"Enter the number of participants for "<<event<<" (max 5): ";
        cin>>n;
        if(n<1 || n>5){
            cout<<"Invalid input! Please enter a number between 1 and 5.\n";
        }
    }
	while(n<1 || n>5);
    cin.ignore();
    
    cout<<"Register participants for "<<event<<":\n";
    for(int i=0;i<n;++i){
        cout<<"Enter participant "<<(i+1)<<" name: ";
        getline(cin,participants[i]);
    }
}

bool Registered(string participant,string event[],int n){
    for(int i=0;i<n;++i){
        if(event[i]==participant){
            return true;
        }
    }
    return false;
}

int Donations(int n1,int n2){
    return (n1+n2)*10;
}

void DisplayReverse(string event,string participants[],int n){
    cout<<"\n"<<event<<" Participants in Reverse Order:\n";
    for(int i=n-1;i>=0;--i){
        cout<<participants[i]<<endl;
    }
}

int main(){
    string event1[5],event2[5],name;
    int n1,n2,donation;

    Participants("Event 1",event1,n1);
    Participants("Event 2",event2,n2);

    cout<<"\nEvent 1 Participants:\n";
    for(int i=0;i<n1;++i){
        cout<<event1[i]<<endl;
    }

    cout<<"\nEvent 2 Participants:\n";
    for(int i=0;i<n2;++i){
        cout<<event2[i]<<endl;
    }

    cout<<"\nEnter the name of the participant to check: ";
    getline(cin,name);

    bool Event1=Registered(name,event1,n1);
    bool Event2=Registered(name,event2,n2);

    if(Event1 && Event2){
        cout<<name<<" is registered for both Events!\n";
    }
	else if(Event1){
        cout<<name<<" is registered for Event 1!\n";
    }
	else if(Event2){
        cout<<name<<" is registered for Event 2!\n";
    }
	else{
        cout<<name<<" is not registered in either Event!\n";
    }

    donation=Donations(n1,n2);
    cout<<"\nTotal donation amount collected from both events: $"<<donation<<endl;

    DisplayReverse("Event 1",event1,n1);
    DisplayReverse("Event 2",event2,n2);

    return 0;
}
