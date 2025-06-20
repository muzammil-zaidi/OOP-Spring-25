#include<iostream>
using namespace std;

long  GenerateHash(string pass){
    long  hash=5381;
    for(int i=0;i<pass.length();i++){
        hash=hash*33+pass[i];
    }
    return hash;
}

class User{
protected:
    string name;
    int ID;
    string email;
    long hashedPassword;
    string permissions[3];

public:
    User(string name,int ID,string email,string password){
        this->name=name;
        this->ID=ID;
        this->email=email;
        this->hashedPassword=GenerateHash(password);

        for(int i=0;i<3;i++){
            permissions[i]="";
        }
    }

    bool Authenticate(string password){
        return GenerateHash(password)==hashedPassword;
    }

    bool HasPermission(string action){
        for(int i=0;i<3;i++){
            if(permissions[i]==action){
                return true;
            }
        }
        return false;
    }

    string getName(){
        return name;
    }

    virtual void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Email: "<<email<<endl;
    }
};

class Student : public User{
protected:
    int Assignments[10];

public:
    Student(string name,int ID,string email,string password) : User(name,ID,email,password){
        for(int i=0;i<10;i++){
            Assignments[i]=0;

            permissions[0]="submitTask";
            permissions[1]="";
            permissions[2]="";
        }
    }

    void submitAssignment(int index){
        if(index>=0 && index<10){
            Assignments[index]=1;
            cout<<"Task "<<index<<" marked as completed."<<endl;
        }
        else{
            cout<<"Invalid task index."<<endl;
        }
    }

    void display() override{
        cout<<"Student Name: "<<name<<endl;
        cout<<"Student ID: "<<ID<<endl;
        cout<<"student Email: "<<email<<endl;
        cout<<"Assignments: ";
        for(int i=0;i<10;i++){
            cout<<Assignments[i]<<" ";
        }
    }
};

class TA : public Student{
private:
    string StudentList[10];
    string project[2];
public: 
    TA(string name,int ID,string email,string password) : Student(name,ID,email,password){
        permissions[0]="view Projects";
        permissions[1]="Manage Students";
        permissions[2]="";
    }

    void addStudent(string studentName){
        for(int i=0;i<10;i++){
            if(StudentList[i]==""){
                StudentList[i]=studentName;
                cout<<"Student "<<studentName<<" has been added."<<endl;
                return;
            }
        }
        cout<<"Student list is full."<<endl;
    }

    void startproject(string projectName){
        for(int i=0;i<2;i++){
            if(project[i]==""){
                project[i]=projectName;
                cout<<"TA "<<name<<" has started working on project: "<<projectName<<"\n";
                return;
            }
        }
        cout<<"Project list is full."<<endl;
    }

    void display() override{
        cout<<"TA Name: "<<name<<endl;
        cout<<"TA ID: "<<ID<<endl;
        cout<<"TA Email: "<<email<<endl;
        cout<<"Students: ";
        for(int i=0;i<10;i++){
            cout<<StudentList[i]<<" ";
        }
        cout<<"\nProjects: ";
        for(int i=0;i<2;i++){
            cout<<project[i]<<" ";
        }
    }
};

class professor : public User{
    public:
    professor(string name,int ID,string email,string password) : User(name,ID,email,password){
        permissions[0]="assignProject";
        permissions[1]="labManagement";
        permissions[2]="";
    }

    void assignProject(TA &ta,string projectName){
        ta.startproject(projectName);
        cout<<"Professor "<<name<<" has assigned project: "<<projectName<<" to TA: "<<ta.getName()<<"\n";
    }

    void display() override{
        cout<<"Professor Name: "<<name<<endl;
        cout<<"Professor ID: "<<ID<<endl;
        cout<<"Professor Email: "<<email<<endl;
    }
};

void authenticateAndperformAction(User &user,string password,string action){
    if(user.Authenticate(password)){
        if(user.HasPermission(action)){
            cout<<"Authentication successful. Executing action: "<<action<<endl;
        }
        else{
            cout<<"Permission denied for action: "<<action<<endl;
        }
    }
    else{
        cout<<"Authentication failed."<<endl;
    }
}

int main(){
	  Student s("John Smith",101,"john.smith@example.com","password123");
    s.submitAssignment(2);
    s.display();
    cout<<endl;


    TA t("Jane Doe",102,"jane.Doe@example.com","securepass");
    t.addStudent("Alice");
    t.addStudent("Bob");
    t.startproject("AI Research");
    t.display();
    cout<<endl;


    professor p("Dr.Williams",103,"dr.Williams@example.com","profpass");
    p.assignProject(t,"Machine Learning");
    p.display();
    cout<<endl;

    cout<<"Testing authentication and permissions:"<<endl;
    authenticateAndperformAction(s,"password123","submitTask");
    authenticateAndperformAction(t,"securepass","view Projects");
    authenticateAndperformAction(p,"profpass","assignProject");
    authenticateAndperformAction(p,"wrongpass","assignProject");

    return 0;
}
