#include<iostream>
using namespace std;

class Ghost{
protected:
    string workerName;
    int scareLevel;

public:
    Ghost(string name,int level){
        workerName=name;
        scareLevel=level;
    }

    virtual void haunt() const=0;

    virtual ~Ghost() {}

    int getScareLevel() const{
		return scareLevel;
	}
};

class Poltergeist : public Ghost{
public:
    Poltergeist(string name,int level) : Ghost(name,level){}

    void haunt() const override{
        cout<<workerName<<" moves objects around! Scare Level: "<<scareLevel<<endl;
    }
};

class Banshee : public Ghost{
public:
    Banshee(string name,int level) : Ghost(name,level){}

    void haunt() const override{
        cout<<workerName<<" lets out a piercing scream! Scare Level: "<<scareLevel<<endl;
    }
};

class ShadowGhost : public Ghost{
public:
    ShadowGhost(string name,int level) : Ghost(name,level){}

    void haunt() const override{
        cout<<workerName<<" whispers eerily in the dark... Scare Level: "<<scareLevel<<endl;
    }
};

class Visitor{
private:
    string name;
    int bravery;

public:
    Visitor(string visitorName,int visitorBravery){
        name=visitorName;
        bravery=visitorBravery;
    }

    void reactToScare(int scareLevel) const{
        if(scareLevel<bravery-2){
            cout<<name<<" laughs at the ghosts!\n";
    	}
		else if(scareLevel>bravery+2){
            cout<<name<<" screams and runs away!\n";
        }
		else{
            cout<<name<<" trembles with a shaky voice...\n";
		}
    }
};

class HauntedHouse{
private:
    string houseName;
    Ghost* ghosts[10];
    int ghostCount;

public:
    HauntedHouse(string name){
        houseName=name;
        ghostCount=0;
    }

    void addGhost(Ghost* ghost){
        if(ghostCount<10){
            ghosts[ghostCount]=ghost;
            ghostCount++;
        }
    }

    void simulateHaunting() const{
        cout<<"\nWelcome to "<<houseName<<"! The ghosts are ready...\n";
        for(int i=0;i<ghostCount;i++){
            ghosts[i]->haunt();
        }
    }

    int getTotalScareLevel() const{
        int totalScare=0;
        for(int i=0;i<ghostCount;i++){
            totalScare+=ghosts[i]->getScareLevel();
        }
        return totalScare;
    }

    string getHouseName() const{
        return houseName;
    }

    ~HauntedHouse(){
        for(int i=0;i<ghostCount;i++){
            delete ghosts[i];
        }
    }
};

void visit(Visitor visitors[],int visitorCount,const HauntedHouse& house){
    cout<<"\nA group of visitors enters "<<house.getHouseName()<<"...\n";
    int houseScareLevel=house.getTotalScareLevel();

    for(int i=0;i<visitorCount;i++){
        visitors[i].reactToScare(houseScareLevel);
    }
}

int main(){
	  HauntedHouse h("Darkwood Manor");

    Ghost* g1=new Poltergeist("John",5);
    Ghost* g2=new Banshee("Alice",7);
    Ghost* g3=new ShadowGhost("Eve",6);

    h.addGhost(g1);
    h.addGhost(g2);
    h.addGhost(g3);

    Visitor v[3]={
        Visitor("Alex",3),
        Visitor("Ben",6),
        Visitor("Charlie",9)
    };

    h.simulateHaunting();
    visit(v,3,h);

    return 0;
}
