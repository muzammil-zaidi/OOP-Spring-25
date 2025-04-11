#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex operator/(const Complex& other) {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        return Complex(r, i);
    }

    friend double magnitude(const Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};

double magnitude(const Complex& c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << "(" << c.real;
    if (c.imag >= 0)
        out << " + " << c.imag << "i)";
    else
        out << " - " << -c.imag << "i)";
    return out;
}

int main() {
    Complex c1(5, 7);
    Complex c2(2, -3);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout<<"c1 = "<<c1<<endl;
    cout<<"c2 = "<<c2<<endl;
    cout<<"Sum = "<<sum<<endl;
    cout<<"Difference = "<<diff<<endl;
    cout<<"Product = "<<prod<<endl;
    cout<<"Quotient = "<<quot<<endl;
    cout<<"Magnitude of c1 = "<<magnitude(c1)<<endl;
    cout<<"Magnitude of c2 = "<<magnitude(c2)<<endl;

    return 0;
}
