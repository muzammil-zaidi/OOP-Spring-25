#include<iostream>
#include<cctype>
using namespace std;

string lower(string s){
	string str=s;
		for(int i=0;i<str.length();i++){ 
			str[i]=tolower(str[i]);
		}
		return str;
}

int main(){
	int n;
	string a;
	cout<<"Enter number of strings: ";
	cin>>n;
	cout<<endl;
	string *s=new string[n];
	for(int i=0;i<n;i++){
		cout<<"String "<<i+1<<" : ";
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(lower(s[i]).compare(lower(s[j]))<0){
			a=s[i];
			s[i]=s[j];
			s[j]=a;
			}
		}

	}
	cout<<"\n--------------------------------\n";
	cout<<"Sorted String: "<<endl;
	for(int i=0;i<n;i++) {
		cout<<s[i]<<"\n";
	}
	delete[] s;
	return 0;
}
