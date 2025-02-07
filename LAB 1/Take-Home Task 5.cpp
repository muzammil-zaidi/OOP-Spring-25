#include<iostream>
#include<limits>
using namespace std;

void worst(float averages[],int cities){
    int index=0;
    float worstAverage=averages[0];
    for(int i=0;i<cities;i++){
        if(averages[i]>worstAverage){
            worstAverage=averages[i];
            index=i;
        }
    }
    cout<<"\nAverage AQI for each city over the month:\n";
    for(int i=0;i<cities;i++){
        cout<<"City "<<i+1<<": "<<averages[i]<<endl;
    }
    cout<<"\nThe city with the worst air quality is City "<<index+1<<" with an average AQI of "<<worstAverage<<"\n";
}

void PollutionDays(int AQI[4][28]){
    cout<<"\nCritical Pollution Days (AQI > 150):\n";
    for(int i=0;i<4;i++){
        cout<<"City "<<i+1<<": ";
        bool hasCriticalDays=false;
        for(int j=0;j<28;j++){
            if(AQI[i][j]>150){
                cout<<"Day "<<j+1<<" ";
                hasCriticalDays=true;
            }
        }
        if(!hasCriticalDays){
            cout<<"None";
        }
        cout<<endl;
    }
}

void visualizeAQI(int AQI[4][28]){
    cout<<"\nAQI Visualization (* = 50 AQI):\n";
    for(int i=0;i<4;i++){
        cout<<"City "<<i+1<<":\n";
        for(int j=0;j<28;j++){
            cout<<"Day "<<j+1<<": ";
            int stars=AQI[i][j]/50;
            for(int k=0;k<stars;k++){
                cout<<"*";
            }
            cout<<endl;
        }
    }
}

void ImprovedCity(float weeklyAverages[4][4]){
    cout<<"\nCity with the most improved air quality:\n";
    int index=0;
    float maxImprovement=weeklyAverages[0][0]-weeklyAverages[0][3];
    for(int i=0;i<4;i++){
        float improvement=weeklyAverages[i][0]-weeklyAverages[i][3];
        if(improvement>maxImprovement){
            maxImprovement=improvement;
            index=i;
        }
    }
    cout<<"City "<<index+1<<" with an improvement of "<<maxImprovement<<" AQI points.\n";
}

void Report(int AQI[4][28],float weeklyAverages[4][4]){
    cout<<"\n======= AQI Report =======\n";
    for(int i=0;i<4;i++){
        int highest=INT_MIN,lowest=INT_MAX;
        cout<<"\nCity "<<i+1<<":\n";
        cout<<"Weekly Averages:\n";
        cout<<"Week 1: "<<weeklyAverages[i][0]<<"  "<<"Week 2: "<<weeklyAverages[i][1]<<"  "<<"Week 3: "<<weeklyAverages[i][2]<<"  "<<"Week 4: "<<weeklyAverages[i][3]<<"\n";
        cout<<"Critical Pollution Days: ";
        bool hasCriticalDays=false;
        for(int j=0;j<28;j++){
            if(AQI[i][j]>150){
                cout<<"Day "<<j+1<<" ";
                hasCriticalDays=true;
            }
            highest=max(highest,AQI[i][j]);
            lowest=min(lowest,AQI[i][j]);
        }
        if(!hasCriticalDays){
            cout<<"None";
        }
        cout<<"\nHighest AQI: "<<highest;
        cout<<"\nLowest AQI: "<<lowest<<"\n";
    }
}

int main(){
    int AQI[4][28];
    float averages[4],weeklyAverages[4][4];

    for(int i=0;i<4;i++){
        cout<<"AQI for City "<<i+1<<endl;
        for(int j=0;j<28;j++){
            cout<<"Day "<<j+1<<": ";
            cin>>AQI[i][j];
        }
    }

    for(int i=0;i<4;i++){
        int sum=0;
        for(int j=0;j<28;j++){
            sum+=AQI[i][j];
        }
        averages[i]=sum/28;
    }

    for(int i=0;i<4;i++){
        for(int week=0;week<4;week++){
            int sum=0;
            for(int j=week*7;j<(week+1)*7;j++){
                sum+=AQI[i][j];
            }
            weeklyAverages[i][week]=sum/7;
        }
    }
    
    worst(averages,4);
    PollutionDays(AQI);
    visualizeAQI(AQI);
    ImprovedCity(weeklyAverages);
    Report(AQI,weeklyAverages);
    
	return 0;
}
