#include<iostream>
using namespace std;

class Robot{
private:
    string name;
    int hits;

public:
    Robot() : name("unknown"),hits(0){}

    Robot(string n) : name(n),hits(0){}

    void strikeBall(int &ballX,int &ballY,const string &direction) {
        if(direction=="w"){
            ballY++;
        }
        else if(direction=="s"){
            ballY--;
        }
        else if(direction=="d"){
            ballX++;
        }
        else if(direction=="a"){
            ballX--;
        }
        hits++;
    }

    int getHits(){
        return hits;
    }
};

class Ball{
private:
    int x;
    int y;

public:
    Ball() : x(0),y(0){}

    Ball(int a,int b) : x(a),y(b){}

    int fetchX(){
        return x;
    }

    int fetchY(){
        return y;
    }

    void shiftPosition(int dx,int dy){
        x+=dx;
        y+=dy;
    }

    pair<int,int>retrievePosition(){
        return {x,y};
    }
};

class Goal{
private:
    int x;
    int y;

public:
    Goal() : x(3),y(3){}

    bool checkGoal(int ballX,int ballY){
        return (ballX==x && ballY==y);
    }
};

class Team{
private:
    string teamName;
    Robot *r1;

public:
    Team(string n,Robot *r) : teamName(n),r1(r){}

    Robot* getRobot(){
        return r1;
    }

    string getTeamName(){
        return teamName;
    }
};

class Game{
private:
    Team* team1;
    Team* team2;
    Ball ball;
    Goal goal;

public:
    Game(Team *t1,Team *t2) : team1(t1),team2(t2){}

    void resetBall(){
        ball=Ball(0,0);
    }

    void runMatch(Team *t1){
        Robot* robot=t1->getRobot();

        cout<<"Team "<<t1->getTeamName()<<" will play now!\n";
        while(!goal.checkGoal(ball.fetchX(),ball.fetchY())){
            string dir;
            cout<<"Enter the direction (w=up | s=down | d=right | a=left): ";
            cin>>dir;

            if(dir=="w" || dir=="s" || dir=="d" || dir=="a"){
                int ballX=ball.fetchX();
                int ballY=ball.fetchY();
                robot->strikeBall(ballX,ballY,dir);
                ball.shiftPosition(ballX-ball.fetchX(),ballY-ball.fetchY());
                cout<<"Ball position: ("<<ball.fetchX()<<", "<<ball.fetchY()<<")"<<endl;
            }
            else{
                cout<<"Invalid direction!\n";
            }
        }
        cout<<"Team "<<t1->getTeamName()<<" has reached the goal in "<<robot->getHits()<<" hits\n";
        cout<<"--------------------------------------------\n";
    }

    void announceWinner(){
        int hits1=team1->getRobot()->getHits();
        int hits2=team2->getRobot()->getHits();

        cout<<team1->getTeamName()<<" hits: "<<hits1<<endl;
        cout<<team2->getTeamName()<<" hits: "<<hits2<<endl;

        if(hits1<hits2){
            cout<<"Team "<<team1->getTeamName()<<" is the winner of the game\n";
        }
        else if(hits1>hits2){
            cout<<"Team "<<team2->getTeamName()<<" is the winner of the game\n";
        }
        else{
            cout<<"It's a tie!\n";
        }
    }

    void initiateGame(){
        cout<<"The game has started\n";
        runMatch(team1);
        resetBall();
        runMatch(team2);
        announceWinner();
    }
};

int main(){
    Robot r1("BotA");
    Robot r2("BotB");

    Team t1("Titans",&r1);
    Team t2("Warriors",&r2);

    Game game(&t1,&t2);
    game.initiateGame();
    return 0;
}
