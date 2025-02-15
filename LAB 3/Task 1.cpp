#include<iostream>
#include<string>
using namespace std;

class Wallet{
    private:
        string ownerName;
        float totalBalance;
        string transactionHistory[50];
        int count;

    public:
        Wallet(){
            ownerName="";
            totalBalance=0;
            count=0;
        }

        Wallet(string name){
            ownerName=name;
            totalBalance=0;
            count=0;
        }
        
        void add(float amount){
            totalBalance+=amount;
            if(count<50){
                transactionHistory[count]="Deposited: "+to_string(amount);
                count++;
            }
        }
        
        void spend(float amount){
            if(amount>0 && amount<=totalBalance){
                totalBalance-=amount;
                if(count<50){
                    transactionHistory[count]="Spent: "+ to_string(amount);
                    count++;
                }
                cout<<"Transaction successful!\n";
                if(totalBalance<500){
                    cout<<"Warning! low balance.\n";
                }
            }
            else{
                cout<<"Invalid input!\n";
            }
        }
        void display(){
            cout << "\n--- Transactions for "<<ownerName<<" ---\n";
            cout<<"---------------------------------\n";
            for(int i=0;i<count;i++){
                cout<<transactionHistory[i]<<"\n";
            }
            cout<<"Current Balance: "<<totalBalance<<"\n";
        }   
};

int main(){
    string name;
    cout<<"Enter your name: ";
    getline(cin,name);
    
    Wallet w(name);
    w.add(25000);
    w.spend(8000);
    w.display();
    w.add(5000);
    w.spend(15000);
    w.display();
    
    return 0;
}
