#include<iostream>
#include<string>
using namespace std;

class Course{
protected:
    string courseCode;
    int credits;
public:
    Course(string c,int cr) : courseCode(c),credits(cr){}
    virtual void displayInfo() const=0;
    virtual double calculateGrade() const=0;
    virtual ~Course(){}
};

class LectureCourse : public Course{
private:
    double midterm;
    double finalExam;
public:
    LectureCourse(string c,int cr,double m,double f) : Course(c,cr),midterm(m),finalExam(f){}

    void displayInfo() const override{
        cout<<"Lecture Course: "<<courseCode<<" ("<<credits<<" credits)"<<endl;
    }

    double calculateGrade() const override{
        return (midterm*0.4+finalExam*0.6);
    }
};

class LabCourse : public Course{
private:
    double labWork;
    double project;
public:
    LabCourse(string c,int cr,double l,double p) : Course(c,cr),labWork(l),project(p){}

    void displayInfo() const override{
        cout<<"Lab Course: "<<courseCode<<" ("<<credits<<" credits)"<<endl;
    }

    double calculateGrade() const override{
        return (labWork*0.5+project*0.5);
    }
};

int main(){
    const int n=2;
    Course* courses[n];

    courses[0]=new LectureCourse("CS101",3,78.5,88.0);
    courses[1]=new LabCourse("CS102L",1,92.0,85.0);

    for(int i=0;i<n;i++){
        courses[i]->displayInfo();
        cout<<"Final Grade: "<<courses[i]->calculateGrade()<<"\n\n";
    }

    for(int i=0;i<n;i++){
        delete courses[i];
    }

    return 0;
}
