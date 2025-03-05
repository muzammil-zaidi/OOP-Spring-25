#include<iostream>
#include<string>
using namespace std;

class Employee;

class Project{
private:
    string title;
    string deadline;
    Employee* employees[10];
    int employeeCount;

public:
    Project(string t,string d) : title(t),deadline(d), employeeCount(0){}

    void addEmployee(Employee* emp);

    void display();

    string getTitle(){
        return title;
    }
};

class Employee{
private:
    string name;
    string designation;
    Project* projects[10];
    int projectCount;

public:
    Employee(string n,string d) : name(n),designation(d), projectCount(0){}

    void assignProject(Project* proj){
        if(projectCount<10){
            projects[projectCount++]=proj;
            proj->addEmployee(this);
        }
    }

    void displayProjects(){
        cout<<"Employee: "<<name<<"\nDesignation: "<<designation<<"\nProjects: ";
        for(int i=0;i<projectCount;i++){
            cout<<projects[i]->getTitle();
            if(i<projectCount-1){
                cout<<", ";
            }    
        }
        cout<<"\n-----------------------------------\n";
    }

    string getName(){
        return name;
    }
    string getDesignation(){
        return designation;
    }
};

void Project::addEmployee(Employee* emp){
    if(employeeCount<10){
        employees[employeeCount++]=emp;
    }
}

void Project::display(){
    cout<<"Project: "<<title<<"\nDeadline: "<<deadline<<"\nEmployees: ";
    for(int i=0;i<employeeCount;i++){
        cout<<employees[i]->getName()<<" ("<<employees[i]->getDesignation()<<")";
        if(i<employeeCount-1){
            cout<<", ";
        }    
    }
    cout<<"\n-----------------------------------\n";
}

int main(){
    Employee e1("Ali","Software Engineer");
    Employee e2("Sara","Project Manager");

    Project p1("AI Development","2025-06-01");
    Project p2("Web App","2025-07-15");

    e1.assignProject(&p1);
    e1.assignProject(&p2);
    e2.assignProject(&p1);

    cout<<"=== Employee Details ==="<<endl;
    e1.displayProjects();
    e2.displayProjects();

    cout<<"\n=== Project Details ==="<<endl;
    p1.display();
    p2.display();

    return 0;
}
