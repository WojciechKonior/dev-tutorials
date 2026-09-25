#include <iostream>

class Point {
public:
    int x, y;
};

// composition
class UDT1 {
public:
    UDT1(const Point& point): p(point) {}
    ~UDT1() {}
    int z;
    Point p;
    void print(){std::cout << p.x << " " << p.y << " " << z << std::endl; }
};

// aggregation
class UDT2 {
public:
    UDT2(Point& point) :p(point) {}
    ~UDT2(){}
    void print(){std::cout << p.x << " " << p.y << " " << z << std::endl; }
    int z;
    Point& p;
};

int main() {
    Point p = {1, 2};
    UDT1 u(p); u.print();
    UDT2 u2(p); u.print();
    return 0;
}
