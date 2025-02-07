#include<iostream>
using namespace std;

void worst(float averages[]){
    int index=0;
    float worstAverage=averages[0];
    for(int i=0;i<4;i++){
        if (averages[i]>worstAverage){
            worstAverage=averages[i];
            index=i;
        }
    }
    cout<<"\nAverage AQI for each city over the week:\n";
    for(int i=0;i<4;i++){
        cout<<"City "<<i+1<<": "<<averages[i]<<endl;
    }
    cout<<"\nThe city with the worst air quality is City "<<index+1<<" with an average AQI of "<<worstAverage<<"\n";
}

int main(){
    int AQI[4][7];
    float averages[4];
    for(int i=0;i<4;i++){
        cout<<"AQI for City "<<i+1<<endl;
        for(int j=0;j<7;j++){
            cout<<"Day "<<j+1<<": ";
            cin>>AQI[i][j];
        }
    }

    for(int i=0;i<4;i++){
        int sum=0;
        for(int j=0;j<7;j++){
            sum+=AQI[i][j];
        }
        averages[i]=sum/7;
    }
    worst(averages);
    return 0;
}
