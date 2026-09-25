#include <iostream>
#include <string>

class Base {
public:
    Base() {baseData = new int[10]; std::cout << "Base constructed\n"; }
    virtual ~Base() {delete[] baseData; std::cout << "Base destructed\n"; }
    virtual void MemberFunc() { std::cout << "Base::MemberFunc()\n"; }
private:
    // int someNumber;
    int* baseData;
};

class Deriv: public Base {
public:
    Deriv() {
        derivedData = new int[20];
        std::cout << "Deriv constr. \n"; 
    }
    ~Deriv() {
        delete[] derivedData;
        std::cout << "Deriv destr. \n";
    }
    void MemberFunc() override { std::cout << "Derived::MemberFunc()\n"; }

    int* derivedData;
};

int main() {
    std::cout << "Sizeof(Base) = " << sizeof(Base) << std::endl;
    std::cout << "Sizeof(Deriv) = " << sizeof(Deriv) << std::endl;

    return 0;
}
