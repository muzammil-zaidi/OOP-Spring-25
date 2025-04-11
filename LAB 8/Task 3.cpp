#include <iostream>
using namespace std;

class Vector2D {
private:
    float xCoord, yCoord;

public:
    Vector2D() : xCoord(0), yCoord(0) {}
    Vector2D(float x, float y) : xCoord(x), yCoord(y) {}

    Vector2D operator+(const Vector2D &other) const {
        return Vector2D(xCoord + other.xCoord, yCoord + other.yCoord);
    }

    Vector2D operator-(const Vector2D &other) const {
        return Vector2D(xCoord - other.xCoord, yCoord - other.yCoord);
    }

    Vector2D operator*(float multiplier) const {
        return Vector2D(xCoord * multiplier, yCoord * multiplier);
    }

    friend float dotProduct(const Vector2D &v1, const Vector2D &v2);
    friend ostream& operator<<(ostream &output, const Vector2D &v);
};

float dotProduct(const Vector2D &v1, const Vector2D &v2) {
    return (v1.xCoord * v2.xCoord + v1.yCoord * v2.yCoord);
}

ostream& operator<<(ostream &output, const Vector2D &v) {
    output << "(" << v.xCoord << ", " << v.yCoord << ")";
    return output;
}

int main() {
    Vector2D a(4, 5), b(2, 1);
    Vector2D sum = a + b;
    Vector2D diff = a - b;
    Vector2D scaled = a * 2;

    cout<<"Vector a = "<<a<<endl;
    cout<<"Vector b = "<<b<<endl;
    cout<<"a + b = "<<sum<<endl;
    cout<<"a - b = "<<diff<<endl;
    cout<<"a * 2 = "<<scaled<<endl;
    cout<<"Dot product = "<<dotProduct(a, b)<<endl;

    return 0;
}
