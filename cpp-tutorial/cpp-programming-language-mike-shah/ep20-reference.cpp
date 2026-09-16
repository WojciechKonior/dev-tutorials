#include <iostream>
#include <typeinfo>

int main(){ // main function is a main entrypoint
    
    int x = 42;
    int& ref = x;
    
    std::cout << "x value   : " << x << std::endl;
    std::cout << "x address : " << (void*)&x << std::endl;
    std::cout << "x type    : " << typeid(x).name() << std::endl;
    
    std::cout << "x ref val : " << ref << std::endl;
    std::cout << "x ref addr: " << (void*)&ref << std::endl;
    std::cout << "x ref type: " << typeid(ref).name() << std::endl;
    
    return 0;
}
