#include <iostream>

class Passcode{
    friend class SomeClass;
private:
    int passcode;
};

class SomeClass{
    friend void printSomeClassVar(const SomeClass& instance);
public:
    SomeClass() { m_var.passcode = 0; }
private:
    int GetPasscode() const { return m_var.passcode; }
    Passcode m_var;
};

void printSomeClassVar(const SomeClass& instance){
    std::cout << instance.GetPasscode() << std::endl;
}

int main() {
    SomeClass c;
    printSomeClassVar(c);
    return 0;
}
