#include<iostream>
#include<string>
using namespace std;

class FitnessTracker{
    private:
        string userName;
        int dailyStepGoal;
        int stepsTaken;
        double caloriesBurned;

    public:
        FitnessTracker(string name,int goal){
            userName=name;
            dailyStepGoal=goal;
            stepsTaken=0;
            caloriesBurned=0;
        }

        void steps(int step){
            stepsTaken+=step;
            calories();
        }

        void calories(){
            caloriesBurned=stepsTaken*0.04;
        }

        void display(){
            cout<<"-------------------------------\n";
            cout<<"User Name: "<<userName;
            cout<<"\n-------------------------------";
            cout<<"\nSteps Taken: "<<stepsTaken<<"\nCalories Burned: "<<caloriesBurned<<"\nGoal for the day: "<<dailyStepGoal;
            if(stepsTaken>=dailyStepGoal){
                cout<<"\nYou achieved your step goal!"<<endl;
            }
            else{
                cout<<"\nKeep Going! You need  more steps to reach your goal."<<endl;
            }

        }    
};

int main(){
    FitnessTracker f("Muzammil",5000);
    f.steps(2800);
    f.display();
    f.steps(1200);
    f.display();
    f.steps(2000);
    f.display();
    
    return 0;
}
