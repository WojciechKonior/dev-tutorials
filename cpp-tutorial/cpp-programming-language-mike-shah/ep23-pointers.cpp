#include <iostream>

int main(){ // main function is a main entrypoint
    int x = 7;
    int& ref = x;
    
    int* ptr1 = &x;
    int* ptr2 = &ref;
    
    std::cout << "The data is " << x << std::endl;
    std::cout << "The ref is " << ref << std::endl;
    std::cout << "The ptr1 to data is " << ptr1 << std::endl;
    std::cout << "The dereferenced of ptr1 is " << *ptr1 << std::endl;
    std::cout << "The ptr2 to data is " << ptr2 << std::endl;
    std::cout << "The dereferenced of ptr2 is " << *ptr2 << std::endl;
    
    return 0;
}
