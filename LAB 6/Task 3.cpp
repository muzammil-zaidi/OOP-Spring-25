#include<iostream>
using namespace std;

class Person{
protected:
    string name;
    int age;
public:
    Person(const string& n,int a) : name(n),age(a){}

    virtual void displayDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<" years"<<endl;
    }
};

class Teacher : virtual public Person{
protected:
    string subject;
public:
    Teacher(const string& n,int a,const string& s) : Person(n,a),subject(s){}

    void displayDetails() override{
        Person::displayDetails();
        cout<<"Subject Expertise: "<<subject<<endl;
    }
};

class Researcher : virtual public Person{
protected:
    string researchArea;
public:
    Researcher(const string& n,int a,const string& r) : Person(n,a),researchArea(r){}

    void displayDetails() override{
        Person::displayDetails();
        cout<<"Research Area: "<<researchArea<<endl;
    }
};

class Professor : public Teacher,public Researcher{
private:
    int publications;
public:
    Professor(const string& n,int a,const string& s,const string& r,int p)
        : Person(n,a),Teacher(n,a,s),Researcher(n,a,r), publications(p){}

    void displayDetails() override{
        Person::displayDetails();
        cout<<"Subject Expertise: "<<subject<<endl;
        cout<<"Research Area: "<<researchArea<<endl;
        cout<<"Publications: "<<publications<<endl;
    }
};

int main(){
    string name,subject,researchArea;
    int age,publications;

    cout<<"Enter Professor's Name: ";
    getline(cin, name);
    cout<<"Enter Age: ";
    cin>>age;
    cin.ignore();
    cout<<"Enter Subject Expertise: ";
    getline(cin, subject);
    cout<<"Enter Research Area: ";
    getline(cin, researchArea);
    cout<<"Enter Number of Publications: ";
    cin>>publications;

    Professor p(name,age,subject,researchArea,publications);

    cout<<"\nProfessor Details:\n";
    p.displayDetails();

    return 0;
}
