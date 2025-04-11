#include <iostream>
using namespace std;

class MatrixTool;

class Matrix {
private:
    int data[2][2];

public:
    Matrix(int x1 = 0, int x2 = 0, int x3 = 0, int x4 = 0) {
        data[0][0] = x1;
        data[0][1] = x2;
        data[1][0] = x3;
        data[1][1] = x4;
    }

    Matrix operator+(const Matrix& m) {
        return Matrix(
            data[0][0] + m.data[0][0],
            data[0][1] + m.data[0][1],
            data[1][0] + m.data[1][0],
            data[1][1] + m.data[1][1]
        );
    }

    Matrix operator-(const Matrix& m) {
        return Matrix(
            data[0][0] - m.data[0][0],
            data[0][1] - m.data[0][1],
            data[1][0] - m.data[1][0],
            data[1][1] - m.data[1][1]
        );
    }

    Matrix operator*(const Matrix& m) {
        return Matrix(
            data[0][0] * m.data[0][0] + data[0][1] * m.data[1][0],
            data[0][0] * m.data[0][1] + data[0][1] * m.data[1][1],
            data[1][0] * m.data[0][0] + data[1][1] * m.data[1][0],
            data[1][0] * m.data[0][1] + data[1][1] * m.data[1][1]
        );
    }

    friend int findDeterminant(const Matrix& m);

    friend class MatrixTool;

    friend ostream& operator<<(ostream& out, const Matrix& m) {
        out<<m.data[0][0]<<" "<<m.data[0][1]<<endl;
        out<<m.data[1][0]<<" "<<m.data[1][1]<<endl;
        return out;
    }
};

int findDeterminant(const Matrix& m) {
    return m.data[0][0] * m.data[1][1] - m.data[0][1] * m.data[1][0];
}

class MatrixTool {
public:
    static void setValue(Matrix& m, int r, int c, int val) {
        if (r >= 0 && r < 2 && c >= 0 && c < 2)
            m.data[r][c] = val;
        else
            cout<<"Invalid index!"<<endl;
    }
};

int main() {
    Matrix a(2, 4, 6, 8);
    Matrix b(1, 3, 5, 7);

    cout<<"Matrix a:\n"<<a;
    cout<<"Matrix b:\n"<<b;

    Matrix add = a + b;
    Matrix sub = a - b;
    Matrix mul = a * b;

    cout<<"a + b:\n"<<add;
    cout<<"a - b:\n"<<sub;
    cout<<"a * b:\n"<<mul;

    cout<<"Determinant of a: "<<findDeterminant(a)<<endl;

    MatrixTool::setValue(a, 1, 0, 99);
    cout<<"Matrix a after modifying element (1,0) to 99:\n"<<a;

    return 0;
}
