#include <iostream>
#include <string>

class Base {
public:
    Base() {std::cout << "Base constructed\n"; }
    ~Base() {std::cout << "Base destructed\n"; }
    virtual void MemberFunc() { std::cout << "Base::MemberFunc()\n"; }
private:
    std::string m_name;
};

class Deriv: public Base {
public:
    Deriv() {
        std::cout << "Deriv constr. \n"; 
    }
    ~Deriv() {
        std::cout << "Deriv destr. \n";
    }
    void MemberFunc() override { std::cout << "Derived::MemberFunc()\n"; }
};

int main() {
    Deriv *ptr1 = new Deriv();
    ptr1->MemberFunc();

    Base *ptr2 = new Deriv();
    ptr2->MemberFunc();

    Base *ptr3 = new Base();
    ptr3->MemberFunc();

    delete ptr1, ptr2, ptr3;

    return 0;
}
