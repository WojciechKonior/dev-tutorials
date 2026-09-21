#include <iostream>
int get42(){ return 42; }
void setValueTo99(int& x) { x = 99; }
void setValueTo100(const int& x) {  }
void setValueTo50(int&& x) { x = 50;}

int main() {

    int x = 10; // lvalue: something with a memory location

    // 10 = x; // rvalue: does not point anywhere

    int c = (x + 10); // c and x are lvalues, (x + 10) is rvalue
    int& ref = c; // is an lvalue reference, can only bind to lvalues
    // int& ref2 = 10; // wrong, cannot bind to rvalue
    const int& ref3 = 10; // but const lvalue reference can bind to rvalues
    setValueTo99(c);
    setValueTo100(10);

    // get42() = 100; // wrong, get42() is an rvalue and cannot be assigned to

    int&& rvref = 10; // rvalue reference, can bind to rvalues
    setValueTo50(10);

    return 0;
}
