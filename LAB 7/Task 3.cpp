#include<iostream>
#include<string>
using namespace std;

class Ticket{
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id,string name,double p,string d,string dest) : ticketID(id),passengerName(name),price(p),date(d),destination(dest){}

    virtual void reserve(){
        cout<<"Reserving ticket for "<<passengerName<<" to "<<destination<<endl;
    }

    virtual void cancel(){
        cout<<"Cancelling ticket for "<<passengerName<<endl;
    }

    virtual void displayTicketInfo(){
        cout<<"Ticket ID: "<<ticketID <<"\nPassenger: "<<passengerName<<"\nPrice: $"<<price<<"\nDate: "<<date<<"\nDestination: "<<destination<<endl;
    }

    virtual ~Ticket(){}
};

class FlightTicket : public Ticket{
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id,string name,double p,string d,string dest,string airline,string flight,string seat) : Ticket(id,name,p,d,dest),airlineName(airline),flightNumber(flight),seatClass(seat){}

    void displayTicketInfo() override{
        Ticket::displayTicketInfo();
        cout<<"Airline: "<<airlineName<<"\nFlight No: "<<flightNumber<<"\nSeat Class: "<<seatClass<<endl;
    }
};

class TrainTicket : public Ticket{
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id,string name,double p,string d,string dest,string train,string coach,string time) : Ticket(id,name,p,d,dest),trainNumber(train),coachType(coach),departureTime(time){}

    void reserve() override{
        cout<<"Reserving train ticket with auto-assigned seat."<<endl;
    }

    void displayTicketInfo() override{
        Ticket::displayTicketInfo();
        cout<<"Train No: "<<trainNumber<<"\nCoach: "<<coachType<<"\nDeparture: "<<departureTime<<endl;
    }
};

class BusTicket : public Ticket{
private:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id,string name,double p,string d,string dest,string company,int seat) : Ticket(id,name,p,d,dest),busCompany(company),seatNumber(seat){}

    void cancel() override{
        cout<<"Last-minute cancellation allowed for bus ticket."<<endl;
    }

    void displayTicketInfo() override{
        Ticket::displayTicketInfo();
        cout<<"Bus Company: "<<busCompany<<"\nSeat No: "<<seatNumber<<endl;
    }
};

class ConcertTicket : public Ticket{
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id,string name,double p,string d,string dest,string artist,string v,string seat) : Ticket(id,name,p,d,dest),artistName(artist),venue(v),seatType(seat){}

    void displayTicketInfo() override{
        Ticket::displayTicketInfo();
        cout<<"Artist: "<<artistName<<"\nVenue: "<<venue<<"\nSeat Type: "<<seatType<<endl;
    }
};

int main(){
    Ticket* t[4];

    t[0]=new FlightTicket(101,"Alice",500.0,"2025-04-10","New York","Emirates","EK202","Business");
    t[1] = new TrainTicket(102,"Bob",150.0,"2025-04-15","Los Angeles","Amtrak","Economy","10:00 AM");
    t[2] = new BusTicket(103,"Charlie",50.0,"2025-04-20","San Francisco","Greyhound",22);
    t[3] = new ConcertTicket(104,"David",80.0,"2025-05-05","Chicago","The Weeknd","Stadium","VIP");

    for(int i=0;i<4;i++){
        cout<<"\n--- Ticket "<<i+1<<" Info ---\n";
        t[i]->displayTicketInfo();
    }

    for(int i=0;i<4;i++){
        delete t[i];
    }

    return 0;
}
