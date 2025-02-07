#include<iostream>
using namespace std;

int main(){
    int r1,c1,r2,c2;
    cout<<"Enter rows and columns for first matrix: ";
    cin>>r1>>c1;
    cout<<"Enter rows and columns for second matrix: ";
    cin>>r2>>c2;

    if(c1!=r2){
        cout<<"Matrix multiplication not possible! Columns of first matrix must match rows of second matrix." << endl;
        return 1;
    }

    int** mat1=new int*[r1];
    int** mat2=new int*[r2];
    int** result=new int*[r1];

    for(int i=0;i<r1;i++){
    	mat1[i]=new int[c1];
	}
    for(int i=0;i<r2;i++){
    	mat2[i]=new int[c2];
	}
    for(int i=0;i<r1;i++){
    	result[i]=new int[c2];
	}

    cout<<"Enter elements of first matrix:"<<endl;
    for(int i=0;i<r1;i++){
    	for(int j=0;j<c1;j++){
    		cin>>mat1[i][j];
		}
	}

    cout<<"Enter elements of second matrix:"<<endl;
    for(int i=0;i<r2;i++){
    	for(int j=0;j<c2;j++){
    		cin>>mat2[i][j];
		}
	}

    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            result[i][j]=0;
            for(int k=0;k<c1;k++){
                result[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }

    cout<<"Resultant Matrix:"<<endl;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<r1;i++){
    	delete[] mat1[i];
	}
    for(int i=0;i<r2;i++){
    	delete[] mat2[i];
	}
    for(int i=0;i<r1;i++){
    	delete[] result[i];
	}
	delete[] mat1;
	delete[] mat2;
	delete[] result;

    return 0;
}
