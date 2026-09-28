#include <iostream>
#include <string>
#include <initializer_list>

union MyUnion {
    int i;
    long l;
    long long ll;
    float f;
    double d;
    struct {
        char c1;
        char c2;
        char c3;
        char c4;
        char c5;
        char c6;
        char c7;
        char c8;
    } s;

    void print() {
        std::cout << "i: " << i << std::endl;
        std::cout << "l: " << l << std::endl;
        std::cout << "ll: " << ll << std::endl;
        std::cout << "f: " << f << std::endl;
        std::cout << "d: " << d << std::endl;
        std::cout << "{\n\ts.c1: " << (int)s.c1 << std::endl;
        std::cout << "\ts.c2: " << (int)s.c2 << std::endl;
        std::cout << "\ts.c3: " << (int)s.c3 << std::endl;
        std::cout << "\ts.c4: " << (int)s.c4 << std::endl;
        std::cout << "\ts.c5: " << (int)s.c5 << std::endl;
        std::cout << "\ts.c6: " << (int)s.c6 << std::endl;
        std::cout << "\ts.c7: " << (int)s.c7 << std::endl;
        std::cout << "\ts.c8: " << (int)s.c8 << "\n}" << std::endl;
    }
};

int main() {
    MyUnion u;
    u.ll = 42;
    u.print();
    std::cout << "Done" << std::endl;
    return 0;
}
