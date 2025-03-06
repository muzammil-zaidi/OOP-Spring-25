#include<iostream>
#include<string>
using namespace std;

class Product{
public:
    int id;
    string name;
    int quantity;

    Product(){}

    Product(int i,string n,int q) : id(i),name(n),quantity(q){}

    void display(){
        cout<<"ID: "<<id<<", Name: "<<name<<", Quantity: "<<quantity<<endl;
    }
};

class Warehouse{
private:
    Product inventory[10];
    int count;

public:
    Warehouse() : count(0){}

    void addProduct(int id,string name,int quantity){
        if(count<10){
            inventory[count++]=Product(id,name,quantity);
        }
        else{
            cout<<"Inventory is full!"<<endl;
        }
    }

    void sortByName(){
        for(int i=0;i<count-1;i++){
            for(int j=i+1;j<count;j++){
                if(inventory[i].name>inventory[j].name){
                    swap(inventory[i],inventory[j]);
                }
            }
        }
    }

    void searchByID(int searchID){
        for(int i=0;i<count;i++){
            if(inventory[i].id==searchID){
                cout<<"Product Found:\n";
                inventory[i].display();
                return;
            }
        }
        cout<<"Product with ID "<<searchID<<" not found!\n";
    }

    void displayInventory(){
        cout<<"\nWarehouse Inventory:\n";
        if(count==0){
            cout<<"No products in inventory.\n";
            return;
        }
        for(int i=0;i<count;i++){
            inventory[i].display();
        }
    }
};

int main(){
    int id;
    Warehouse w;

    w.addProduct(101,"Laptop",15);
    w.addProduct(102,"Sofa",7);
    w.addProduct(103,"Apple",12);
    w.addProduct(104,"Table",6);
    w.addProduct(105,"Mobile",3);

    cout<<"Before Sorting:";
    w.displayInventory();
    w.sortByName();
    
    cout<<"\nAfter Sorting:";
    w.displayInventory();

    cout<<"\nEnter product ID to search: ";
    cin>>id;
    w.searchByID(id);

    return 0;
}
