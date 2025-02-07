#include<iostream>
using namespace std;

struct product{
    int productID;
    string name;
    int quantity;
    float price;
};

int main(){
    int n;
    float sum=0;
    cout<<"Enter the number of products: ";
    cin>>n;
    product* p=new product[n];

    for(int i=0;i<n;i++){
        cout<<"\nEnter details for product "<<i+1<<":\n";
        cout<<"Product ID: ";
        cin>>p[i].productID;
        cin.ignore();
        cout<<"Name: ";
        getline(cin,p[i].name);
        cout<<"Quantity: ";
        cin>>p[i].quantity;
        cout<<"Price: ";
        cin>>p[i].price;
    }

    for(int i=0;i<n;i++){
        sum+=p[i].quantity*p[i].price;
    }
    cout<<"\nTotal Inventory Value: "<<sum<<endl;

    delete[] p;
    return 0;
}
