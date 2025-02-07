#include<iostream>
using namespace std;

int main(){
    int x;
    cout<<"Enter the size of the array: ";
    cin>>x;
    int** arr=new int*[x];

    for(int i=0;i<x;i++){
        arr[i]=new int;
        cout<<"Enter value for element "<<i+1<<": ";
        cin>>*arr[i];
    }

    cout<<"Array elements: ";
    for(int i=0;i<x;i++){
        cout<<*arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<x;i++){
        delete arr[i];
    }
    delete[] arr;
    return 0;
}
