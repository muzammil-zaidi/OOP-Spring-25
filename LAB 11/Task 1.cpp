#include<iostream>
#include<exception>
#include<sstream>
using namespace std;

class DimensionMismatchException : public exception{
private:
    string message;
public:
    DimensionMismatchException(int r1,int c1,int r2,int c2){
        ostringstream oss;
        oss<<"DimensionMismatchException - Matrices must have same dimensions ("<<r1<<"x"<<c1<<" vs "<<r2<<"x"<<c2<<") !";
        message=oss.str();
    }

    const char* what() const noexcept override{
        return message.c_str();
    }
};

template <typename T>
class Matrix{
private:
    T** data;
    int rows,cols;

public:
    Matrix(int r,int c){
        rows=r;
        cols=c;
        data=new T*[rows];
        for(int i=0;i<rows;i++){
            data[i]=new T[cols];
        }
    }

    ~Matrix(){
        for(int i=0;i<rows;i++){
            delete[] data[i];
        }
        delete[] data;
    }

    void setElement(int i,int j,T value){
        data[i][j]=value;
    }

    void inputMatrix(){
        cout<<"Enter matrix ("<<rows<<"x"<<cols<<"):\n";
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>data[i][j];
            }
        }    
    }

    void display() const{
        cout<<"Matrix ("<<rows<<"x"<<cols<<"):\n";
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const{
        if(rows!=other.rows || cols!=other.cols){
            throw DimensionMismatchException(rows,cols,other.rows,other.cols);
        }

        Matrix<T> result(rows,cols);
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                result.data[i][j]=data[i][j]+other.data[i][j];
            }
        return result;
    }
};

int main(){
    try{
        Matrix<int> A(2,2);
        Matrix<int> B(3,3);

        A.setElement(0,0,1); A.setElement(0,1,2);
        A.setElement(1,0,3); A.setElement(1,1,4);

        B.setElement(0,0,5); B.setElement(0,1,6); B.setElement(0,2,7);
        B.setElement(1,0,8); B.setElement(1,1,9); B.setElement(1,2,10);
        B.setElement(2,0,11); B.setElement(2,1,12); B.setElement(2,2,13);

        Matrix<int> C=A+B;
        C.display();
    }
    catch(const DimensionMismatchException& e){
        cerr<<e.what()<<endl;
    }

    return 0;
}
