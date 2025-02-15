#include<iostream>
#include<string>
using namespace std;

class Library{
    private:
        string bookList[50];
        string borrowedBooks[50];
        string availableBooks[50];
        int totalBooks,borrowed,available;

    public:
        Library(){
            totalBooks=0;
            borrowed=0;
            available=0;
        }

        void add(string name){
            if(totalBooks<100){
                bookList[totalBooks]=name;
                availableBooks[available]=name;
                totalBooks++;
                available++;
                cout<<"----------------------------------------------\n";
                cout<<name<<" added to the library.\n";
            }
            else{
                cout<<"Library is full!.\n";
            }
        }

        void lend(string name){
            for(int i=0;i<available;i++){
                if(availableBooks[i]==name){
                    borrowedBooks[borrowed]=name;
                    borrowed++;
                    for(int j=i;j<available-1;j++){
                        availableBooks[j]=availableBooks[j+1];
                    }
                    available--;
                    cout<<"----------------------------------------------\n";
                    cout<<name<<" has been borrowed.\n";
                    return;
                }
            }
            cout<<name<<" is not available.\n";
        }

        void return_book(string name){
            for(int i=0;i<borrowed;i++){
                if(borrowedBooks[i]==name){
                    availableBooks[available]=name;
                    available++;
                    for(int j=i;j<borrowed-1;j++){
                        borrowedBooks[j]=borrowedBooks[j+1];
                    }
                    borrowed--;
                    cout<<"----------------------------------------------\n";
                    cout<<name <<" has been returned.\n";
                    return;
                }
            }
            cout<<name<<" was not borrowed.\n";
        }

        void display_available_books(){
            cout<<"----------------------------------------------\n";
            cout<<"Available Books:\n";
            for(int i=0;i<available;i++){
                cout<<availableBooks[i]<<"\n";
            }
        }

        void display_borrowed_books(){
            cout<<"----------------------------------------------\n";
            cout<<"Borrowed Books:\n";
            for(int i=0;i<borrowed;i++){
                cout<<borrowedBooks[i]<<"\n";
            }
        }
};

int main(){
    Library l;
    l.add("The Stranger");
    l.add("A Brief History of Time");
    l.display_available_books();
    l.lend("The Stranger");
    l.display_borrowed_books();
    l.display_available_books();
    l.return_book("The Stranger");
    l.display_available_books();

    return 0;
}
