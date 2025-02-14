#include<iostream>
#include<string>
using namespace std;

class Car{
	string brand;
	string model;
	float price;
	bool availability;
	float discount;
	
	public:
		Car(){
			brand="Unknown";
			model="Generic";
			price=0.0;
			availability=true;
		}
		
		Car(string a,string b,float c,bool d){
			brand=a;
			model=b;
			price=c;
			availability=d;
		}
		
		void availability(string a,string b){
			if(availability==true){
				cout<<"Available!";
			}
		}
		
		void request(int request){
				if(availability==false){
				cout<<"Unavailable!";
			}
		}
		
		void discount(int day){
			if(day==5){
				discount=(price/100)*5;
			}
			else if(day>10){
				discount=(price/100)*10;
			}
		}
		
		void display(){
			cout<<"Brand: "<<brand<<endl;
			cout<<"Model: "<<model<<endl;
			cout<<"Price: "<<price<<endl;
			cout<<"Availibilty: "<<availibilty<<endl;
			cout<<"Discount: "<<discount<<endl;
		}
};

int main(){
	Car c;
	c.Car("Corrolla","BA-23",232455.00,true);
	c.display();
	
	return 0;
}
