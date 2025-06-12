#include<iostream>
using namespace std;

class TransportStudent{
private:
    const string studentId;
    string cardId;
    string studentName;
    string assignedStop;
    bool feePaid;

public:
    TransportStudent(string id,string cId,string name,string stop,bool paid=false) : studentId(id),cardId(cId),studentName(name),assignedStop(stop),feePaid(paid){}

    void makeFeePayment(){
        feePaid=true;
    }

    string getStopName() const{
        return assignedStop;
    }

    bool isFeeCleared() const{
        return feePaid;
    }

    string getStudentId() const{
        return studentId;
    }

    void showStudentInfo() const{
        cout<<"Student ID: "<<studentId<<endl;
        cout<<"Name: "<<studentName<<endl;
        cout<<"Card ID: "<<cardId<<endl;
        cout<<"Stop: "<<assignedStop<<endl;
        cout<<"-----------------------------\n";
    }
};

class TransportStop{
private:
    string stopName;
    TransportStudent **enrolledStudents;
    int studentCount;
    int maxStudents;

public:
    TransportStop(string name) : stopName(name){
        studentCount=0;
        maxStudents=2;
        enrolledStudents=new TransportStudent*[maxStudents];
    }

    ~TransportStop(){
        delete[] enrolledStudents;
    }

    void expandCapacity(){
        maxStudents*=2;
        TransportStudent **newList=new TransportStudent *[maxStudents];

        for(int i=0;i<studentCount;i++){
            newList[i]=enrolledStudents[i];
        }

        delete[] enrolledStudents;
        enrolledStudents=newList;
    }

    void addStudentToStop(TransportStudent *stud){
        if(studentCount==maxStudents){
            expandCapacity();
        }
        enrolledStudents[studentCount++]=stud;
    }

    string getStopName() const{
        return stopName;
    }
};

class TransportRoute{
private:
    string routeCode;
    TransportStop **stopsList;
    int totalStops;
    int maxStops;

public:
    TransportRoute(string code) : routeCode(code){
        totalStops=0;
        maxStops=2;
        stopsList=new TransportStop*[maxStops];
    }

    ~TransportRoute(){
        delete[] stopsList;
    }

    void expandStops(){
        maxStops*=2;
        TransportStop **newList=new TransportStop*[maxStops];

        for(int i=0;i<totalStops;i++){
            newList[i]=stopsList[i];
        }

        delete[] stopsList;
        stopsList=newList;
    }

    void addNewStop(TransportStop*newStop){
        if(totalStops==maxStops){
            expandStops();
        }
        stopsList[totalStops++]=newStop;
    }

    TransportStop **getStopsArray(){
        return stopsList;
    }

    int getTotalStops(){
        return totalStops;
    }
};

class TransportBus{
private:
    string busNumber;
    TransportRoute &busRoute;
    TransportStudent **studentsOnBoard;
    int studentTotal;
    int studentLimit;

public:
    TransportBus(string id,TransportRoute &route) : busNumber(id),busRoute(route){
        studentTotal=0;
        studentLimit=2;
        studentsOnBoard=new TransportStudent*[studentLimit];
    }

    ~TransportBus(){
        delete[] studentsOnBoard;
    }

    string getBusNumber() const{
        return busNumber;
    }

    void increaseStudentLimit(){
        studentLimit*=2;
        TransportStudent **newList=new TransportStudent *[studentLimit];

        for(int i=0;i<studentTotal;i++){
            newList[i]=studentsOnBoard[i];
        }

        delete[] studentsOnBoard;
        studentsOnBoard=newList;
    }

    void assignStudentToBus(TransportStudent *stud){
        for(int i=0;i<busRoute.getTotalStops();i++){
            if(busRoute.getStopsArray()[i]->getStopName()==stud->getStopName()){
                if(studentTotal==studentLimit){
                    increaseStudentLimit();
                }
                studentsOnBoard[studentTotal++]=stud;
                cout<<"Student "<<stud->getStudentId()<<" assigned to Bus "<<busNumber<<" at Stop "<<stud->getStopName()<< "\n";
                return;
            }
        }
        cout<<"No matching stop found for student "<<stud->getStudentId()<<"\n";
    }

    void displayBusStudents(){
        for(int i=0;i<studentTotal;i++){
            studentsOnBoard[i]->showStudentInfo();
        }
    }
};

int main(){
    TransportStop *x=new TransportStop("Alpha Stop");
    TransportStop *y=new TransportStop("Beta Stop");
    TransportStop *z=new TransportStop("Gamma Stop");

    TransportRoute r("Route X");
    r.addNewStop(x);
    r.addNewStop(y);
    r.addNewStop(z);

    TransportBus b("34",r);

    TransportStudent *A=new TransportStudent("101","CARD-201","Ali","Alpha Stop");
    TransportStudent *B=new TransportStudent("102","CARD-202","Sara","Beta Stop");
    TransportStudent *C=new TransportStudent("103","CARD-203","Hamza","Gamma Stop");
    TransportStudent *D=new TransportStudent("104","CARD-204","Aisha","Alpha Stop");

    x->addStudentToStop(A);
    y->addStudentToStop(B);
    z->addStudentToStop(C);
    x->addStudentToStop(D);

    b.assignStudentToBus(A);
    b.assignStudentToBus(B);
    b.assignStudentToBus(C);
    b.assignStudentToBus(D);

    cout<<"\n### Students Assigned to Bus "<<b.getBusNumber()<<" ###\n";
    cout<<"---------------------------------------\n";
    b.displayBusStudents();

    delete A;
    delete B;
    delete C;
    delete D;
    delete x;
    delete y;
    delete z;

    return 0;
}
