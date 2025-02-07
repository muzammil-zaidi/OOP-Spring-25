#include<iostream>
using namespace std;

int** allocate(int rows,int cols){
    int** matrix=new int*[rows];
    for(int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }
    return matrix;
}

void input(int** matrix,int rows,int cols,const string&name){
    cout<<"Enter elements for "<<name<<" matrix:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
}

void display(int** matrix,int rows,int cols,const string&name){
    cout<<name<<" Matrix:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int** add(int** a,int** b,int rows,int cols){
    int** result=allocate(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j]=a[i][j]+b[i][j];
        }
    }
    return result;
}

int** subtract(int** a,int** b,int rows,int cols){
    int** result=allocate(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j]=a[i][j]-b[i][j];
        }
    }
    return result;
}

void deallocate(int** matrix,int rows){
    for(int i=0;i<rows;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(){
    int rows,cols;
    cout<<"Enter the number of rows and columns: ";
    cin>>rows>>cols;

    int** a=allocate(rows,cols);
    int** b=allocate(rows,cols);

    input(a,rows,cols,"First");
    input(b,rows,cols,"Second");

    int** sum=add(a,b,rows,cols);
    int** difference=subtract(a,b,rows,cols);

    display(sum,rows,cols,"Sum");
    display(difference,rows,cols,"Difference");

    deallocate(a,rows);
    deallocate(b,rows);
    deallocate(sum,rows);
    deallocate(difference,rows);

    return 0;
}
