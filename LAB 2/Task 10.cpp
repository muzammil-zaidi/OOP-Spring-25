#include<iostream>
using namespace std;

int main(){
    int x,y,z;
    cout<<"Enter the dimensions of the 3D array (depth, rows, cols): ";
    cin>>x>>y>>z;
    int ***array=new int**[x];
    for(int i=0;i<x;i++){
        array[i]=new int*[y];
        for(int j=0;j<y;j++){
            array[i][j]=new int[z];
        }
    }
    cout<<"Enter the elements of the 3D array:\n";
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cout<<"Element at ("<<i<<","<<j<<","<<k<<"): ";
                cin>>array[i][j][k];
            }
        }
    }
    cout<<"\n3D Array Elements:\n";
    for(int i=0;i<x;i++){
        cout<<"Depth "<<i+1<<":\n";
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cout<<array[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
	return 0;
}
