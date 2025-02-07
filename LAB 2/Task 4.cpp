#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of strings: ";
    cin>>n;
    cin.ignore();
    string* strArray=new string[n];

    for(int i=0;i<n;i++){
        cout<<"Enter string "<<i+1<<": ";
        getline(cin,strArray[i]);
    }

    sort(strArray,strArray+n);

    cout<<"\nSorted Strings:\n";
    for(int i=0;i<n;i++){
        cout<<strArray[i]<<endl;
    }

    delete[] strArray;
    return 0;
}
