#include<iostream>
using namespace std;

class Vehicle{
private:
    string Brand;
    string Model;
    float rentalprice;
    string reqLicence;

public:
    Vehicle() : Brand("Unknown Brand"),Model("Unknown Model"),rentalprice(0.0),reqLicence("not provided"){}

    Vehicle(string b,string m,float price,string req) : Brand(b),Model(m),rentalprice(price),reqLicence(req){}

    bool checkEligibility(string userLicence){
        if(userLicence=="Full"){
            return true;
        }
        if(userLicence=="Intermediate" && reqLicence=="Intermediate"){
            return true;
        }
        if(userLicence=="Learner" && reqLicence=="Learner"){
            return true;
        }    
        return false;
    }

    string fetchModel(){
        return Model;
    }

    float fetchRentalPrice(){
        return rentalprice;
    }

    void showVehicleDetails(){
        cout<<"Brand: "<<Brand<<endl;
        cout<<"Model: "<<Model<<endl;
        cout<<"Rental price for a day: "<<rentalprice<<"$"<<endl;
        cout<<"Required licence: "<<reqLicence<<endl;
        cout<<"-----------------------------------\n";
    }
};

class User{
private:
    int UserID;
    string Name;
    int age;
    string contactNumber;
    string LicenseType;

public:
    User() : UserID(0),Name("unknown"),contactNumber("Not provided"),LicenseType("not given"){}

    User(int id,string n,int a,string number,string licence) : UserID(id),Name(n),age(a),contactNumber(number),LicenseType(licence){}

    void modifyLicenceType(string l){
        LicenseType=l;
    }

    void changeName(string n){
        Name=n;
    }

    void adjustAge(int a){
        age=a;
    }

    void updatePhoneNumber(string number){
        contactNumber=number;
    }

    int fetchUserId(){
        return UserID;
    }

    string fetchLicenceType(){
        return LicenseType;
    }

    string fetchUserName(){
        return Name;
    }

    void showUserDetails(){
        cout<<"User ID: "<<UserID<<endl;
        cout<<"Name: "<<Name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact No: "<<contactNumber<<endl;
        cout<<"Licence Type: "<<LicenseType<<endl;
        cout<<"-----------------------------------\n";
    }
};

class RentalSystem{
private:
    User **users;
    Vehicle **vehicles;
    int userCount;
    int vehicleCount;
    int userCapacity;
    int vehicleCapacity;

public:
    RentalSystem(){
        userCount=0;
        vehicleCount=0;
        userCapacity=1;
        vehicleCapacity=1;

        users=new User*[userCapacity];
        vehicles=new Vehicle*[vehicleCapacity];
    }

    void expandUserCapacity(){
        userCapacity *=2;
        User **newUsers=new User*[userCapacity];

        for(int i=0; i<userCount;i++){
            newUsers[i]=users[i];
        }
        delete[] users;
        users=newUsers;
    }

    void expandVehicleCapacity(){
        vehicleCapacity *=2;
        Vehicle **newVehicles=new Vehicle*[vehicleCapacity];

        for(int i=0;i<vehicleCount;i++){
            newVehicles[i]=vehicles[i];
        }

        delete[] vehicles;
        vehicles=newVehicles;
    }

    void enrollUser(int id,string n,int a,string number,string licence){
        if(userCount==userCapacity){
            expandUserCapacity();
        }

        users[userCount++]=new User(id,n,a,number,licence);
        cout<<"User registered successfully\n";
        cout<<"-----------------------------------\n";
    }

    void registerVehicle(string b,string m,float price,string req) {
        if(vehicleCount==vehicleCapacity){
            expandVehicleCapacity();
        }

        vehicles[vehicleCount++]=new Vehicle(b,m,price,req);
        cout<<"Vehicle added successfully\n";
        cout<<"-----------------------------------\n";
    }

    void processRental(int userId,string vehicleModel){        User *user=nullptr;
        Vehicle *selectedVehicle=nullptr;

        for(int i=0;i<userCount;i++){
            if(users[i]->fetchUserId()==userId){
                user=users[i];
                break;
            }
        }

        if(!user){
            cout<<"User not found!\n";
            return;
        }

        for(int i=0;i<vehicleCount;i++){
            if(vehicles[i]->fetchModel()==vehicleModel){
                selectedVehicle=vehicles[i];
                break;
            }
        }

        if(!selectedVehicle){
            cout<<"Vehicle not found!\n";
            return;
        }

        if(selectedVehicle->checkEligibility(user->fetchLicenceType())){
            cout<<"Rental Successful! "<<user->fetchUserName()<<" rented "<<selectedVehicle->fetchModel()<<" for $"<<selectedVehicle->fetchRentalPrice()<<" per day.\n";
        }
        else{
            cout<<"Rental Failed! "<<user->fetchUserName()<<" does not meet the license requirement for this vehicle.\n";
        }
    }

    ~RentalSystem(){
        for(int i=0;i<userCount;i++){
            delete users[i];
        }
        for(int i=0;i<vehicleCount;i++){
            delete vehicles[i];
        }
        delete[] users;
        delete[] vehicles;
    }

    void listAllUsers(){
        for(int i=0;i<userCount;i++){
            cout<<"User "<<i+1<<":"<<endl;
            users[i]->showUserDetails();
        }
    }

    void listAllVehicles(){
        for(int i=0;i<vehicleCount;i++){
            cout<<"Vehicle "<<i+1<< ":"<<endl;
            vehicles[i]->showVehicleDetails();
        }
    }
};

int main(){
    RentalSystem r;

    r.enrollUser(101,"Zain",27,"0300-1234567","Full");
    r.enrollUser(102,"Hassan",19,"0311-9876543","Learner");
    r.enrollUser(103,"Bilal",22,"0322-4567890","Intermediate");
    r.listAllUsers();

    r.registerVehicle("Suzuki","Swift",55.0,"Full");
    r.registerVehicle("KIA","Sportage",60.0,"Intermediate");
    r.registerVehicle("Honda","CD 70",15.0,"Learner");
    r.listAllVehicles();

    r.processRental(101,"Swift");
    r.processRental(102,"Swift");
    r.processRental(103,"Sportage");
    r.processRental(102,"CD 70");
    r.processRental(103,"Swift");

    return 0;
}
