#include <iostream>

struct Vec1{
    int x, y, z;
    void print(){std::cout << x << " "<<y<<" "<<z<<std::endl;}
};

struct Vec2{
    Vec2() = default;
    int x, y, z;
    void print(){std::cout << x << " "<<y<<" "<<z<<std::endl;}
};

struct Vec3{
    Vec3() {};
    int x, y, z;
    void print(){std::cout << x << " "<<y<<" "<<z<<std::endl;}
};

int main() {
    Vec1 v; // junk values
    v.print();

    Vec1 v2{}; // zero-initialized by compiler-made default construktor;
    v2.print();

    Vec2 v3;
    v3.print(); // junk

    Vec2 v4{};
    v4.print();

    Vec3 v5;
    v5.print();

    Vec3 v6{};
    v6.print();
    return 0;
}
