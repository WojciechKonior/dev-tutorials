#include <iostream>
#include <string>

class Base {
public:
    Base() {baseData = new int[10]; std::cout << "Base constructed\n"; }
    virtual ~Base() {delete[] baseData; std::cout << "Base destructed\n"; }
    virtual void MemberFunc() { std::cout << "Base::MemberFunc()\n"; }
private:
    std::string m_name;
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
    Base *ptr1 = new Deriv();
    delete ptr1;

    return 0;
}
