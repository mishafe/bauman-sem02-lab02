#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

class point {
private:
    double x;
    double y;
public:
    point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double getx() { return x; };
    double gety() { return y; };
    static point polar(float, float);
};

point point::polar(float R, float F) {
    point p(R * cos(F), R * sin(F));
    return p;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Must have 3 arguments" << endl;
        return -2;
    }
    const double pi = acos(-1);
    double x, y, R;
    sscanf(argv[1], "(%le%*c%le)", &x, &y);
    sscanf(argv[2], "%le", &R);
    if (x * x + y * y == R * R) {
        cout << "This point is not inside the circle" << endl;
        return -1;
    }
    double distance = sqrt(x * x + y * y);
    double angle = sin(y / distance);
    if (x < 0 && y > 0) angle += pi / 2;
    if (x < 0 && y < 0) angle -= pi / 2;
    point result_point = point::polar(R, angle);
    cout << fixed;
    cout.precision(3);
    cout << "(" << result_point.getx() << "," << result_point.gety() << ")" << endl;
}