#include<iostream>
#include<string>
using namespace std;

struct book{
    string title;
    string author;
    int year;
};

int main(){
    int n,search;
    cout<<"Enter the number of books: ";
    cin>>n;
    cin.ignore();
    book* b=new book[n];

    for(int i=0;i<n;i++){
        cout<<"\nEnter details for book "<<i+1<<":\n";
        cout<<"Title: ";
        getline(cin,b[i].title);
        cout<<"Author: ";
        getline(cin,b[i].author);
        cout<<"Year: ";
        cin>>b[i].year;
        cin.ignore();
	}
    cout<<"\nEnter a year to display books published after that year: ";
    cin>>search;
    cout<<"\nBooks published after "<<search<<":\n";
    bool found=false;
    for(int i=0;i<n;i++){
        if(b[i].year>search){
            cout<<"Title: "<<b[i].title<<", Author: "<<b[i].author<<", Year: "<<b[i].year<<"\n";
            found=true;
        }
    }
    if(!found){
        cout<<"No books found."<<endl;
    }

    delete[] b;
    return 0;
}
