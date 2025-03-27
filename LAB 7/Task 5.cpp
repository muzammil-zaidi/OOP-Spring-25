#include<iostream>
#include<string>
using namespace std;

class Character{
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id,string n,int lvl,int hp,string weapon="None") : characterID(id),name(n),level(lvl),healthPoints(hp),weaponType(weapon){}

    virtual void attack(){
        cout<<name<<" attacks with "<<weaponType<<"!"<<endl;
    }

    virtual void defend(){
        cout<<name<<" defends!"<<endl;
    }

    virtual void displayStats(){
        cout<<"ID: "<<characterID<<" | Name: "<<name<<" | Level: "<<level<<" | HP: "<<healthPoints<<" | Weapon: "<<weaponType<<endl;
    }

    virtual ~Character(){}
};

class Warrior : public Character{
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id,string n,int lvl,int hp,int armor,int damage)  : Character(id,n,lvl,hp,"Sword"),armorStrength(armor),meleeDamage(damage){}

    void attack() override{
        cout<<name<<" swings a sword with "<<meleeDamage<<" damage!"<<endl;
    }
};

class Mage : public Character{
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id,string n,int lvl,int hp,int mana,int power) : Character(id,n,lvl,hp,"Magic Staff"),manaPoints(mana),spellPower(power){}

    void defend() override{
        cout<<name<<" casts a magical barrier using "<<manaPoints<<" mana points!"<<endl;
    }
};

class Archer : public Character{
private:
    int arrowCount;
    float rangedAccuracy;

public:
    Archer(int id,string n,int lvl,int hp,int arrows,float accuracy) : Character(id,n,lvl,hp,"Bow"),arrowCount(arrows),rangedAccuracy(accuracy){}

    void attack() override{
        cout<<name<<" shoots an arrow with "<<(rangedAccuracy*100)<<"% accuracy!"<<endl;
    }
};

class Rogue : public Character{
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id,string n,int lvl,int hp,int stealth,int agil) : Character(id,n,lvl,hp,"Dagger"),stealthLevel(stealth),agility(agil){}

    void displayStats() override{
        Character::displayStats();
        cout<<"Stealth Level: "<<stealthLevel<<" | Agility: "<<agility<<endl;
    }
};

int main(){
    Warrior w(1,"Thor",10,100,50,30);
    Mage m(2,"Merlin",12,80,100,40);
    Archer a(3,"Legolas",15,90,20,0.85);
    Rogue r(4,"Ezio",14,85,90,95);

    cout<<"Character Stats:\n";
    w.displayStats();
    m.displayStats();
    a.displayStats();
    r.displayStats();

    cout<<"\nCharacter Actions:\n";
    w.attack();
    m.defend();
    a.attack();
    r.displayStats();

    return 0;
}
