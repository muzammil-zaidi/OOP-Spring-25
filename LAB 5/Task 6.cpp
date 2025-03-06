#include<iostream>
#include<string>
using namespace std;

class Level{
private:
    string levelName;
    int difficulty;

public:
    Level(string name,int diff) : levelName(name),difficulty(diff){}

    void display(){
        cout<<"Level: "<<levelName<<" (Difficulty: "<<difficulty<<")"<<endl;
    }
};

class VideoGame{
private:
    string title;
    string genre;
    Level** levels;
    int levelCount;
    int maxLevels;

public:
    VideoGame(string t,string g,int maxL) : title(t),genre(g),levelCount(0),maxLevels(maxL){
        levels=new Level*[maxLevels]();
    }

    ~VideoGame(){
        for(int i=0;i<levelCount;i++){
            delete levels[i];
        }
        delete[] levels;
        cout<<"Game '"<<title<<"' destroyed."<<endl;
    }

    bool addLevel(string name,int difficulty){
        if(levelCount<maxLevels){
            levels[levelCount++]=new Level(name,difficulty);
            return true;
        }
        cout<<"Maximum limit reached!"<<endl;
        return false;
    }

    void displayDetails(){
        cout<<"Game: "<<title<<" (Genre: "<<genre<<")"<<endl;
        cout<<" ===========Levels============"<<endl;
        if(levelCount==0){
            cout<<"No levels added yet."<<endl;
        }
        else{
            for(int i=0;i<levelCount;i++){
                levels[i]->display();
            }
        }
        cout<<"-------------------------------------"<<endl;
    }
};

int main(){
    VideoGame v("Space Adventure","Action",3);

    v.addLevel("Training Ground",1);
    v.addLevel("Alien Encounter",2);
    v.addLevel("Final Battle",3);

    v.displayDetails();

    return 0;
}
