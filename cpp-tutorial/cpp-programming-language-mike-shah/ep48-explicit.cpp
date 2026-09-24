#include <iostream>

class SomeClass{
public:
    SomeClass(int a): var(a) { std::cout << "var = " << var << std::endl;}

private:
    int var;
};

class SomeOtherClass{
public:
    explicit SomeOtherClass(int a): var(a) { std::cout << "var = " << var << std::endl;}

private:
    int var;
};

int main() {
    
    // implicit conversions available;
    SomeClass a(500.32f);
    SomeClass b(500);
    SomeClass c = 500.0f;
    // SomeClass d{500.5}; // this is bad narrowing conversion of ‘5.005e+2’ from ‘double’ to ‘int’

    // implicit conversions not allowed
    SomeOtherClass d(500.35f);
    // SomeOtherClass e = 500.35f; //this is bad conversion from ‘float’ to non-scalar type ‘SomeOtherClass’ requested
    // SomeOtherClass f = 500; // even this conversion from ‘int’ to non-scalar type ‘SomeOtherClass’
    SomeOtherClass e{500};

    return 0;
}
