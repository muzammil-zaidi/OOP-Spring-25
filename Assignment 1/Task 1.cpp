#include<iostream>
using namespace std;

class Skill{
    private:
        int skillID;
        string name;
        string description;
    
    public:
        Skill(){
            skillID=0;
            name="Unknown Skill";
            description="none";
        }

        Skill(int id,string n,string d){
            skillID=id;
            name=n;
            description=d;
        }

        int getSkillId(){
            return skillID;
        }

        void showSkillDetails(){
            cout<<"Skill Details\n";
            cout<<"Skill ID: "<<skillID<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Description: "<<description<<endl;
        }

        void updateSkillDescription(string s){
            description=s;
        }
};

class Sports{
    private:
        int sportID;
        string name;
        string description;
        Skill requiredSkills[2];
        int noOfSkills=0;

    public:
        Sports(){
            sportID=0;
            name="unknown sports";
            description="none";
        }

        Sports(int id,string n,string d){
            sportID=id;
            name=n;
            description=d;
        }

        void addSkill(Skill s){
            if(noOfSkills<2){
                requiredSkills[noOfSkills++]=s;
            }
            else{
                cout<<"Max number of required skills already achieved!\n";
            }
        }

        void removeSkill(Skill s){
            bool found=false;
            for(int i=0;i<noOfSkills;i++){
                if(requiredSkills[i].getSkillId()==s.getSkillId()) {
                    found=true;
                    for(int j=i;j<noOfSkills-1;j++){
                        requiredSkills[j]=requiredSkills[j+1];
                    }
                    cout<<"Skill was removed\n";
                    noOfSkills--;
                    break;
                }
            }
            if(!found){
                cout<<"This Skill is not present here\n";
            }
        }

        void Details(){
            cout<<"Sports Details\n";
            cout<<"Sports ID: "<<sportID<<endl;
            cout<<"Sports Name: "<<name<<endl;
            cout<<"Sports Description: "<<description<<endl;
        }
};

class Mentor;

class Student{
    private:
        int studentID;
        string name;
        int age;
        Sports sportsinterest[2];
        Mentor *mentorAssigned;
        int noOfsports=0;

    public:
        Student(){
            studentID=0;
            name="Unknown Student";
            mentorAssigned=nullptr;
        }

        Student(int id,string n,int a){
            studentID=id;
            name=n;
            age=a;
            mentorAssigned=nullptr;
        }

        void updateSportsInterest(Sports s){
            if(noOfsports<2){
                sportsinterest[noOfsports++]=s;
            }
            else{
                cout<<"Maximum number of sports have been added already!\n";
            }
        }

        void viewMentorDetails(){
            cout<<"Sports interests\n";
            for(int i=0;i<noOfsports;i++){
                sportsinterest[i].Details();
            }
        }

        void registerForMentorship(Mentor &m);

        int getStudentid(){
            return studentID;
        }

        void details(){
            cout<<"Learner Details\n";
            cout<<"Learner ID: "<<studentID<<endl;
            cout<<"Learner Name: "<<name<<endl;
            cout<<"Learner Age: "<<age<<endl;
            viewMentorDetails();
        }
};

class Mentor{
    private:
        int mentorID;
        string name;
        Sports sportsExpertise[2];
        int maxlearner;
        Student *assignedLearners;
        int noOfLearner=0;
        int noOfsports=0;
    
    public:
        Mentor(){
            mentorID=0;
            name="Unknown Mentor";
            maxlearner=3;
            assignedLearners=new Student[maxlearner];
        }

        Mentor(int id,string n,int max){
            mentorID=id;
            name=n;
            maxlearner=max;
            assignedLearners=new Student[max];
        }

        void assignLearner(Student &s){
            if(noOfLearner<maxlearner){
                assignedLearners[noOfLearner++]=s;
            }
            else{
                cout<<"Maximum number of learners are already assigned\n";
            }
        }

        void removeLearner(Student s){
            bool found=false;
            for(int i=0;i<noOfLearner;i++){
                if(assignedLearners[i].getStudentid()==s.getStudentid()){
                    found=true;
                    for(int j=i;j<noOfLearner-1;j++){
                        assignedLearners[j]=assignedLearners[j+1];
                    }
                    cout<<"Learner has been removed\n";
                    noOfLearner--;
                    break;
                }
            }
            if(!found){
                cout<<"This Learner is not assigned here\n";
            }
        }

        void Details(){
            cout<<"Mentor's Details\n";
            cout<<"Mentor ID: "<<mentorID<<endl;
            cout<<"Mentor's Name: "<<name<<endl;
        }

        void viewLearners(){
            cout<<"Mentor's Name: "<<name<<endl;
            cout<<"Learners:\n";
            for(int i=0;i<noOfLearner;i++){
                assignedLearners[i].details();
            }
        }

        void addsportExpertise(Sports s){
            if(noOfsports<2){
                sportsExpertise[noOfsports++]=s;
            }
            else{
                cout<<"Maximum number of sports expertise has been added\n";
            }
        }

        ~Mentor(){ 
            delete[] assignedLearners;
        }
};

void Student::registerForMentorship(Mentor &m){
    mentorAssigned=&m;
    m.assignLearner(*this);
}

int main(){
    Skill skill1(10,"Smash Shot","Powerful overhead shot in badminton.");
    Skill skill2(11,"Spin Control","Ability to add spin to table tennis shots.");

    Sports badminton(110,"Badminton","A fast-paced racket sport played with a shuttlecock.");
    Sports tableTennis(120,"Table Tennis","A sport played with a lightweight ball on a small table.");

    badminton.addSkill(skill1);
    tableTennis.addSkill(skill2);

    cout<<"=== Sports Details ==="<<endl;
    badminton.Details();
    tableTennis.Details();

    Student student1(210,"Hassan",19);
    Student student2(211,"Rohan",21);

    student1.updateSportsInterest(badminton);
    student2.updateSportsInterest(tableTennis);

    cout<<"\n=== Student Details ==="<<endl;
    student1.details();
    student2.details();

    Mentor mentor1(310,"Coach Kamran",2);

    student1.registerForMentorship(mentor1);
    student2.registerForMentorship(mentor1);

    cout<<"\n=== Mentor Details ==="<<endl;
    mentor1.Details();
    mentor1.viewLearners();

    cout<<"\nRemoving Student Rohan from Mentor..."<<endl;
    mentor1.removeLearner(student2);
    mentor1.viewLearners();

    return 0;
}
