#include<iostream>
using namespace std;

class MenuItem{
protected:
    string dishName;
    double price;
public:
    MenuItem(string d,double p) : dishName(d),price(p){}
    virtual void showDetails() const=0;
    virtual void prepare() const=0;
    virtual ~MenuItem(){}
};

class Appetizer : public MenuItem{
public:
    Appetizer(string d,double p) : MenuItem(d,p){}
    void showDetails() const override{
        cout<<"Appetizer: "<<dishName<<" ($"<<price<<")"<<endl;
    }
    void prepare() const override{
        cout<<"Preparation steps:\n- Light cooking\n- Quick plating\n- Garnishing\n";
    }
};

class MainCourse : public MenuItem{
public:
    MainCourse(string d,double p) : MenuItem(d,p){}
    void showDetails() const override{
        cout<<"Main Course: "<<dishName<<" ($"<<price<<")"<<endl;
    }
    void prepare() const override{
        cout<<"Preparation steps:\n- Full cooking\n- Seasoning\n- Plating\n";
    }
};

int main(){
    const int n=2;
    MenuItem* menu[n];

    menu[0]=new Appetizer("Spring Rolls",5.99);
    menu[1]=new MainCourse("Grilled Chicken",12.49);

    for(int i=0;i<n;i++){
        menu[i]->showDetails();
        menu[i]->prepare();
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        delete menu[i];
    }

    return 0;
}
