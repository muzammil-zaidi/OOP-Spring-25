#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
using namespace std;

const int MAX_USERS=150;
const int MAX_VEHICLES=100;
const int MAX_BOOKINGS=200;
const int MAX_SEATS=52;
const int MAX_ROUTES=30;
const int MAX_TRANSPORTERS=2;
const int MAX_DRIVERS=100;

class Vehicle;

class User{
protected:
    string name;
    int id;
    bool hasPaid;
public:
    User(int i,const string& n) : id(i),name(n),hasPaid(false){}
    virtual ~User(){}
    virtual void makePayment(){
		hasPaid=true;
	}
    virtual double getFare(bool isAC) const=0;
    bool paymentDone() const{
		return hasPaid;
	}
    string getName() const{
		return name;
	}
    int getID() const{
		return id;
	}
    virtual string getType() const=0;
};

class Student : public User{
public:
    Student(const string& n,int i) : User(i,n){}
    
	double getFare(bool isAC) const override{
    	if(isAC){
        	return 3800+2000;
    	}
		else{
        	return 3800;
    	}
	}

    string getType() const override{
        return "Student";
    }
};

class Faculty : public User{
public:
    Faculty(const string& n,int i) : User(i,n){}
    
	double getFare(bool isAC) const override{
    	if(isAC){
        	return 5000+2000;
    	}
		else{
        	return 5000;
    	}
	}

    string getType() const override{
        return "Faculty";
    }
};

class Driver{
private:
    string name;
    string licenseNo;
public:
    Driver(const string& n="",const string& l="") : name(n),licenseNo(l){}
    
	void display() const{
        cout<<"Driver: "<<name<<", License: "<<licenseNo<<endl;
    }
};

class Route{
private:
    string start;
    string end;
    int distance;
public:
    Route(const string& s="",const string& e="",int d=0) : start(s),end(e),distance(d){}

    bool isLongRoute() const{
		return distance>=25;
	}
    int getDistance() const{
		return distance;
	}
    void display() const{
        cout<<"Route: "<<start<<" to "<<end<<" ("<<distance<<" km)";
        if(isLongRoute()){
    		cout<<" [Long Route]";
		}
        cout<<endl;
    }

    string getStart() const{
		return start;
	}
    string getEnd() const {
		return end;
	}
};

class Seat{
private:
    bool isBooked;
    User* bookedBy;
    string seatType;
public:
    Seat(const string& t="Student") : isBooked(false),bookedBy(nullptr),seatType(t){}

    bool book(User* user){
        if(isBooked || user->getType()!=seatType){
    		return false;
		}
		else{
    		bookedBy=user;
    		isBooked=true;
    		return true;
		}
    }

    bool isAvailable() const{ 
		return !isBooked;
	}
    string getSeatType() const{
		return seatType;
	}

    void display(int index) const{
        if(isBooked){
    		cout<<"Seat "<<index<<": "<<seatType<<" [Booked]"<<endl;
		}
		else{
    		cout<<"Seat "<<index<<": "<<seatType<<" [Available]"<<endl;
		}
    }

    User* getBookedUser() const{
		return bookedBy;
	}
};

class Vehicle{
private:
    int id;
    bool isAC;
    string type;
    Route* route;
    Driver driver;
    Seat seats[MAX_SEATS];
    int seatCount;
public:
    Vehicle(int vi,const string& vt,bool a,Route* r,const Driver& d) : id(vi),isAC(a),type(vt),route(r),driver(d){
        if(vt=="Bus"){
    		seatCount=52;
		}
		else{
    		seatCount=32;
		}
        for(int i=0;i<seatCount;i++){
    		if(i<seatCount/2){
        		seats[i]=Seat("Student");
    		}
			else{
    		    seats[i]=Seat("Faculty");
    		}
		}
    }

    void display() const{
        cout<<"\nVehicle ID: "<<id<<" ("<<type<<") ";
		if(isAC){
    		cout<<"[AC]";
		}
		else{
    		cout<<"[Non-AC]";
		}
		cout<<endl;

        driver.display();
        route->display();
        cout<<"Seats Status:\n";
        for(int i=0;i<seatCount;++i){
            seats[i].display(i+1);
    	}
    }

    bool bookSeat(User* user){
        for(int i=0;i<seatCount;i++){
            if (seats[i].isAvailable() && seats[i].getSeatType()==user->getType()){
                return seats[i].book(user);
            }
        }
        return false;
    }

    int getID() const{
		return id;
	}
    Route* getRoute() const{
		return route;
	}
    bool isACVehicle() const{
		return isAC;
	}
};

class Bus : public Vehicle{
public:
    Bus(int vi, bool a,Route* r,const Driver& d) : Vehicle(vi,"Bus",a,r,d){}
};

class Coaster : public Vehicle{
public:
    Coaster(int vi,bool a,Route* r,const Driver& d) : Vehicle(vi,"Coaster",a,r,d){}
};

class BookingException : public exception{
private:
    string message;
public:
    BookingException(const string& msg) : message(msg){}
    const char* what() const noexcept override{
        return message.c_str();
    }
};

class Transporter{
private:
    string name;
    Vehicle* vehicles[MAX_VEHICLES];
    int vehicleCount;
public:
    Transporter(const string& tn="") : name(tn),vehicleCount(0){}

    bool addVehicle(Vehicle* v){
        if(vehicleCount<MAX_VEHICLES){
            vehicles[vehicleCount++]=v;
            return true;
        }
        return false;
    }

    Vehicle* getVehicleByID(int id){
        for(int i=0;i<vehicleCount;i++)
            if(vehicles[i]->getID()==id)
                return vehicles[i];
        return nullptr;
    }

    void displayVehicles() const{
        cout<<"\n--- Vehicles under "<<name<<" ---\n";
        for(int i=0;i<vehicleCount;i++)
            vehicles[i]->display();
    }

    string getName() const{
		return name;
	}
};

class Booking{
private:
    User* user;
    Vehicle* vehicle;
    Route* route;
public:
    Booking(User* u,Vehicle* v) : user(u),vehicle(v),route(v->getRoute()){}

    void confirm(){
        if(!user->paymentDone())
            throw BookingException("Payment not completed!");

        if (!vehicle->bookSeat(user))
            throw BookingException("No available seat for this user type!");

        cout<<"Booking confirmed for " << user->getName()<<" on vehicle ID "<<vehicle->getID()<<endl;
    }

    void display() const{
        cout<<"\n--- Booking Summary ---\n";
        cout<<"User: "<<user->getName()<<"\n";
        vehicle->getRoute()->display();
    }
};

class TransportSystem{
private:
    User* users[MAX_USERS];
    Driver* drivers[MAX_DRIVERS];
    Route* routes[MAX_ROUTES];
    Transporter* transporters[MAX_TRANSPORTERS];
    Booking* bookings[MAX_BOOKINGS];
    int userCount,driverCount,routeCount,bookingCount;

public:
    TransportSystem() : userCount(0),driverCount(0),routeCount(0),bookingCount(0){
        transporters[0]=new Transporter("Nadeem Transporter");
        transporters[1]=new Transporter("Zulfiqar Transporter");
    }

    ~TransportSystem(){
        for(int i=0;i<userCount;i++){
			delete users[i];
		}
        for(int i=0;i<driverCount;i++){
			delete drivers[i];
    	}
		for(int i=0;i<routeCount;i++){
			delete routes[i];
    	}
		for(int i=0;i<bookingCount;i++){
			delete bookings[i];
        }
		delete transporters[0];
        delete transporters[1];
    }

    void addUser(User* u){
        if(userCount<MAX_USERS){
			users[userCount++]=u;
		}
	}

    void addDriver(Driver* d){
        if(driverCount<MAX_DRIVERS){
			drivers[driverCount++]=d;
		}
    }

    void addRoute(Route* r){
        if (routeCount<MAX_ROUTES){
			routes[routeCount++]=r;
		}
    }

    void addVehicleToTransporter(Vehicle* v,int transporterIndex){
        transporters[transporterIndex]->addVehicle(v);
    }

    User* getUserByID(int id){
        for(int i=0;i<userCount;i++)
            if(users[i]->getID()==id)
                return users[i];
        throw BookingException("User not found.");
    }

    void bookSeat(int userID,int vehicleID,int transporterIndex){
        User* user=getUserByID(userID);
        Vehicle* vehicle=transporters[transporterIndex]->getVehicleByID(vehicleID);

        if(!vehicle) throw BookingException("Vehicle not found.");

        Booking* b=new Booking(user,vehicle);
        try{
            b->confirm();
            bookings[bookingCount++]=b;
        }
		catch(BookingException& e){
            delete b;
            throw;
        }
    }

    void showAll(){
        cout<<"\n=========== All Users ===========\n";
        for(int i=0;i<userCount;i++){
            cout<<users[i]->getName();
			if(users[i]->paymentDone()){
    			cout<<" (Paid)";
			}
			else{
	    		cout<<" (Not Paid)";
			}
			cout<<endl;
		}

        cout<<"\n============= Routes =============\n";
        for(int i=0;i<routeCount;i++){
            routes[i]->display();
        }

        for(int i=0;i<MAX_TRANSPORTERS;i++){
            transporters[i]->displayVehicles();
        }
    }

    void saveUsersToFile(const string& filename){
        ofstream out(filename);
        for(int i=0;i<userCount;i++){
            out<<users[i]->getID()<< ","<<users[i]->getName()<<","<<users[i]->paymentDone()<<"\n";
        	out.close();
    	}
    }
};

int main(){
    TransportSystem ts;

    // Add Routes
    Route* r1=new Route("Gulshan","FAST",22);
    Route* r2=new Route("Tower","FAST",32);
    ts.addRoute(r1);
    ts.addRoute(r2);

    // Add Drivers
    Driver* d1=new Driver("Khalid","LIC123");
    Driver* d2=new Driver("Iqbal","LIC456");
    ts.addDriver(d1);
    ts.addDriver(d2);

    // Add Users
    User* u1=new Student("Muzammil",1);
    User* u2=new Faculty("Dr. Ahmed",2);
    ts.addUser(u1);
    ts.addUser(u2);

    // Make payments
    u1->makePayment();
    u2->makePayment();

    // Add Vehicles
    Vehicle* v1=new Bus(101,true,r1,*d1);
    Vehicle* v2=new Coaster(102,false,r2,*d2);
    ts.addVehicleToTransporter(v1,0); // Nadeem Transporter
    ts.addVehicleToTransporter(v2,1); // Zulfiqar Transporter

    // Book Seats
    try{
        ts.bookSeat(1,101,0); // Ali books Bus from Nadeem
        ts.bookSeat(2,102,1); // Dr. Ahmed books Coaster from Zulfiqar
    }
	catch(BookingException& e){
        cout<<"Booking failed: "<<e.what()<<endl;
    }

    // Display system info
    ts.showAll();

    // Save users to file
    ts.saveUsersToFile("file.txt");

    return 0;
}
