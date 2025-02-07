#include<iostream>
#include<string>
using namespace std;

class ReverseWords{
	public:
		void arrayinput(char arr[100]){
			int i=0;
			char ch;
			while(i<=100){
				ch=getchar();
				
				if(ch=='\n'){
					break;
				}
				else{
					arr[i]=ch;
					i++;
				}
			}
			arr[i]='\0';
			return i;
		}
		
		void display(char arr[100],int length){
			cout<<"Entered String ";
			for(int i=o;i<length;i++){
				
			}
		}
};

int main(){
	ReverseWords r1;
	char array[100];
	int length=r1.arrayinput(array);
	cout<<length;
	
	return 0;
}
