#include<iostream>
#include<string>
using namespace std;

class Product{
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id,string name,double p,int stock) : productID(id),productName(name),price(p),stockQuantity(stock){}

    virtual void applyDiscount(){
        price*=0.95;
    }

    virtual double calculateTotalPrice(int quantity){
        return price*quantity;
    }

    virtual void displayProductInfo() const{
        cout<<"Product ID: "<<productID<<"\n";
        cout<<"Product Name: "<<productName<<"\n";
        cout<<"Price: $"<<price<<"\n";
        cout<<"Stock: "<<stockQuantity<<" units\n";
    }

    double getPrice() const{
        return price;
    }

    virtual ~Product(){}
};

class Electronics : public Product{
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id,string name,double p,int stock,int warranty,string brandName) : Product(id,name,p,stock),warrantyPeriod(warranty),brand(brandName){}

    void displayProductInfo() const override{
        Product::displayProductInfo();
        cout<<"Brand: "<<brand<<"\n";
        cout<<"Warranty: "<<warrantyPeriod<<" months\n";
    }
};

class Clothing : public Product{
private:
    string size,color,fabricMaterial;

public:
    Clothing(int id,string name,double p,int stock,string sz,string clr,string fabric) : Product(id,name,p,stock),size(sz),color(clr),fabricMaterial(fabric){}

    void applyDiscount() override{
        price*=0.90;
    }

    double calculateTotalPrice(int quantity) override{
        if(quantity>3){
            return (price*quantity)*0.85;
        }
        return price*quantity;
    }

    void displayProductInfo() const override{
        Product::displayProductInfo();
        cout<<"Size: "<<size<<"\n";
        cout<<"Color: "<<color<<"\n";
        cout<<"Fabric Material: "<<fabricMaterial<<"\n";
    }
};

class FoodItem : public Product{
private:
    string expirationDate;
    int calories;

public:
    FoodItem(int id,string name,double p,int stock,string expiry,int cal) : Product(id,name,p,stock),expirationDate(expiry),calories(cal){}

    void applyDiscount() override{
        price*=0.85;
    }

    void displayProductInfo() const override{
        Product::displayProductInfo();
        cout<<"Expiration Date: "<<expirationDate<<"\n";
        cout<<"Calories: "<<calories<<" kcal\n";
    }
};

class Book : public Product{
private:
    string author,genre;

public:
    Book(int id,string name,double p,int stock,string auth,string gen) : Product(id,name,p,stock),author(auth),genre(gen){}

    void displayProductInfo() const override{
        Product::displayProductInfo();
        cout<<"Author: "<<author<<"\n";
        cout<<"Genre: "<<genre<<"\n";
    }
};

double bulkPurchasePrice(const Product& p1,const Product& p2){
    return p1.getPrice()+p2.getPrice();
}

int main(){
    Electronics e(101,"Dell Laptop",800,10,24,"Dell");
    Clothing c(102,"Graphic T-Shirt",20,50,"M","Black","Cotton");
    FoodItem f(103,"Dark Chocolate",5,100,"2025-01-01",250);
    Book b(104,"The Great Gatsby",15,30,"F. Scott Fitzgerald","Classic");

    cout<<"\n--- Product Information ---\n";
    e.displayProductInfo();
    cout<<"\n";
    c.displayProductInfo();
    cout<<"\n";
    f.displayProductInfo();
    cout<<"\n";
    b.displayProductInfo();
    cout << "\n";

    cout<<"\n--- Applying Discounts ---\n";
    c.applyDiscount();
    f.applyDiscount();
    cout<<"After Discount:\n";
    cout<<"T-Shirt New Price: $"<<c.getPrice()<<"\n";
    cout<<"Chocolate New Price: $"<<f.getPrice()<<"\n";

    cout<<"\n--- Total Price Calculation ---\n";
    cout<<"Total Price for 4 T-Shirts: $"<<c.calculateTotalPrice(4)<<"\n";
    cout<<"Total Price for 2 Chocolates: $"<<f.calculateTotalPrice(2)<<"\n";

    cout<<"\n--- Bulk Purchase ---\n";
    cout<<"Bulk Purchase Total Price: $"<<bulkPurchasePrice(e,c)<<"\n";

    return 0;
}
