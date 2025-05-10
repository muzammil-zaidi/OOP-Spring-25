#include<iostream>
#include<exception>
#include<string>
using namespace std;

class DatabaseException : public exception{
public:
    const char* what() const noexcept override{
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException{};
class QueryTimeoutException : public DatabaseException{};

template<typename T>
class DatabaseConnector{
private:
    T name;

public:
    DatabaseConnector(T n) : name(n){}

    void connect(){
        if(name=="invalid_db"){
            throw ConnectionFailedException();
        }
        else if(name=="slow_db"){
            throw QueryTimeoutException();
        }
        else{
            cout<<"Connected to "<<name<<" successfully.\n";
        }
    }
};

int main(){
    try{
        cout<<"Attempting to connect to invalid_db ...\n";
        DatabaseConnector<string> d1("invalid_db");
        d1.connect();
    }
    catch(const ConnectionFailedException& e){
        cerr<<"Caught ConnectionFailedException - what(): "<<e.what()<<endl;
    }

    try{
        cout<<"\nAttempting to connect to slow_db ...\n";
        DatabaseConnector<string> d2("slow_db");
        d2.connect();
    }
    catch(const DatabaseException& e){
        cerr<<"Caught a general DatabaseException - what(): "<<e.what()<<endl;
    }

    return 0;
}
